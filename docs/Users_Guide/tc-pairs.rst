.. _tc-pairs:

*************
TC-Pairs Tool
*************

Introduction
============

The TC-Pairs tool provides verification for tropical cyclone forecasts in ATCF file format. It matches an ATCF format tropical cyclone (TC) forecast with a second ATCF format reference TC dataset (most commonly the Best Track analysis). The TC-Pairs tool processes both track and intensity adeck data and probabilistic edeck data. The adeck matched pairs contain position errors, as well as wind, sea level pressure, and distance to land values for each TC dataset. The edeck matched pairs contain probabilistic forecast values and the verifying observation values. The pair generation can be subset based on user-defined filtering criteria. Practical aspects of the TC-Pairs tool are described in :numref:`TC-Pairs_Practical-information`. 

Scientific and statistical aspects
==================================

.. _TC-Pairs_Diagnostics:

TC Diagnostics
-----------------

TC diagnostics provide information about a TC's structure or its environment. Each TC diagnostic is a single-valued measure that corresponds to some aspect of the storm itself or the surrounding large-scale environment. TC diagnostics can be derived from observational analyses, model fields, or even satellite observations. Examples include:

  * Inner core diagnostics provide information about the structure of the storm near the storm center. Examples include the intensity of the storm and the radius of maximum winds.

  * Large scale diagnostics provide information about quantities that characterize its environment. Examples include environmental vertical wind shear, total precipitable water, the average relative humidity, measures of convective instability, and the upper bound of intensity that a storm may be expected to achieve in its current environment. These diagnostics are typically derived from model fields as an average of the quantity of interest over either a circular area or an annulus centered on the storm center. Often, the storm center is taken to be the underlying model's storm center. In other cases, the diagnostics may be computed along some other specified track.

  * Ocean-based diagnostics provide information about the sea's thermal characteristics in the vicinity of the storm center. Examples include the sea surface temperature, ocean heat content, and the depth of warm water of a given temperature.

  * Satellite-based diagnostics provide information about the storm structure as observed by geostationary satellite infrared imagery. Examples include information about the shape and extent of the cold-cirrus canopy of the TC and whether patterns are present that may portend intensification.

Diagnostics are critically important for training and running statistical-dynamical models that predict a TC's intensity or size. One of the most well-known diagnostics sets is that of the Statistical Hurricane Intensity Prediction Scheme (SHIPS), which supports predictions of TC intensity. A large 30-year development dataset of TC diagnostics has been retrospectively derived to support the training of the SHIPS intensity model as well as other related models such as the Logistic Growth Equation Model (LGEM), SHIPS Rapid Intensification Index (SHIPS-RII), and others. These diagnostics, called *lsdiag* for "large scale" environment, are computed using a *perfect prog* approach in which the diagnostics are computed on the reference model's verifying analyses to generate a set of time-dependent diagnostics from t=0 out to the desired maximum forecast lead time. This is repeated for each initialization, building up a full history of diagnostics for each storm. By using the subsequent verifying analysis for later lead times, the model is taken to be "perfect", removing the impact of model forecast errors. The resulting developmental dataset is ideal for training statistical-dynamical models such as SHIPS. To generate forecasts in real-time, the diagnostics are computed along a forecast track (often taken to be the National Hurricane Center's official forecast) using the fields of the underlying NWP model (e.g, the Global Forecast System, or GFS model). The resulting diagnostics are then used as *predictors* in models like SHIPS and LGEM to predict a TC's future intensity or probability of undergoing rapid intensification.

Beside their use in TC prediction, TC diagnostics can be very useful to forecasters to understand the forecast scenario. They are also useful to model developers for evaluation of model errors and understanding model performance under different environmental conditions. For instance, a modeler may wish to understand their model's track biases under conditions of high vertical wind shear. TC diagnostics can also be used to understand the sensitivity of the model's intensity predictions to oceanic conditions such as upwelling. The TC-Pairs tool allows filtering and subsetting based on the values of one or several TC diagnostics.

As of MET v11.0.0, two types of TC diagnostics are supported in TC-Pairs:

  .. SHIPS_DIAG_DEV: Includes a plethora of inner core, environmental, oceanic, and satellite-based diagnostics. These diagnostics are computed using the *perfect prog* approach.

  * SHIPS_DIAG_RT: Real-time SHIPS diagnostics computed from a NWP model such as the Global Forecast System (GFS) model along a GFS forecast track defined by a SHIPS-specific tracker. Note that these SHIPS-derived forecast tracks do not appear in the NHC adeck data.

  * CIRA_DIAG_RT: Real-time model-based diagnostics computed along the model's predicted track.

Diagnostics from the SHIPS Development Datasets (SHIPS_DIAG_DEV) will be supported in a future release of MET.

A future version of MET will also allow the CIRA model diagnostics to be computed directly from model forecast fields. Until then, users may obtain the SHIPS diagnostics at the following locations:

  * SHIPS_DIAG_DEV: https://rammb2.cira.colostate.edu/research/tropical-cyclones/ships/#DevelopmentalData

  * SHIPS_DIAG_RT: https://ftp.nhc.noaa.gov/atcf/lsdiag/


.. _TC-Pairs_Practical-information:

Practical information
=====================

This section describes how to configure and run the TC-Pairs tool. The TC-Pairs tool is used to match a tropical cyclone model forecast to a corresponding reference dataset. Both tropical cyclone forecast/reference data must be in ATCF format. Output from the TC-dland tool (NetCDF gridded distance file) is also a required input for the TC-Pairs tool. It is recommended to run tc_pairs on a storm-by-storm basis, rather than over multiple storms or seasons to avoid memory issues.

tc_pairs usage
--------------

The usage statement for tc_pairs is shown below:

.. code-block:: none

  Usage: tc_pairs
         -adeck path and/or -edeck path
         -bdeck path
         -config file
         [-diag source path]
         [-out base]
         [-log file]
         [-v level]

tc_pairs has required arguments and can accept several optional arguments.

Required arguments for tc_pairs
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

1. The **-adeck path** argument indicates the adeck TC-Pairs acceptable format data containing tropical cyclone model forecast (output from tracker) data to be verified. Acceptable data formats are limited to the standard ATCF format and the one column modified ATCF file, generated by running the tracker in genesis mode. It specifies the name of a TC-Pairs acceptable format file or top-level directory containing TC-Pairs acceptable format files ending in ".dat" to be processed. The **-adeck** or **-edeck** option must be used at least once.

2. The **-edeck path** argument indicates the edeck ATCF format data containing probabilistic track data to be verified. It specifies the name of an ATCF format file or top-level directory containing ATCF format files ending in ".dat" to be processed. The **-adeck** or **-edeck** option must be used at least once.

3. The **-bdeck path** argument indicates the TC-Pairs acceptable format data containing the tropical cyclone reference dataset to be used for verifying the adeck data. This data is typically the NHC Best Track Analysis, but could be any TC-Pairs acceptable formatted reference. The acceptable data formats for bdecks are the same as those for adecks. This argument specifies the name of a TC-Pairs acceptable format file or top-level directory containing TC-Pairs acceptable format files ending in ".dat" to be processed.

4. The **-config file** argument indicates the name of the configuration file to be used. The contents of the configuration file are discussed below.

Optional arguments for tc_pairs
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

5. The **-diag source path** argument indicates the TC-Pairs acceptable format data containing the tropical cyclone diagnostics dataset corresponding to the adeck tracks. The **source** can be set to CIRA_DIAG_RT or SHIPS_DIAG_RT to indicate the input diagnostics data source. The **path** argument specifies the name of a TC-Pairs acceptable format file or top-level directory containing TC-Pairs acceptable format files ending in ".dat" to be processed. Support for additional diagnostic sources will be added in future releases.

6. The -**out base** argument indicates the path of the output file base. This argument overrides the default output file base (**./out_tcmpr**).

7. The **-log file** option directs output and errors to the specified log file. All messages will be written to that file as well as standard out and error. Thus, users can save the messages without having to redirect the output on the command line. The default behavior is no log file.

8. The **-v level** option indicates the desired level of verbosity. The contents of "level" will override the default setting of 2. Setting the verbosity to 0 will make the tool run with no log messages, while increasing the verbosity above 1 will increase the amount of logging.

This tool currently only supports the rapid intensification (**RI**) edeck probability type but support for additional edeck probability types will be added in future releases.

At least one **-adeck** or **-edeck** option must be specified. The **-adeck, -edeck**, and **-bdeck** options may optionally be followed with **suffix=string** to append that string to all model names found within that data source. This option may be useful when processing track data from two different sources which reuse the same model names.

An example of the tc_pairs calling sequence is shown below:

.. code-block:: none

  tc_pairs -adeck aal092010.dat -bdeck bal092010.dat -config TCPairsConfig

In this example, the TC-Pairs tool matches the model track (aal092010.dat) and the best track analysis (bal092010.dat) for the 9th Atlantic Basin storm in 2010. The track matching and subsequent error information is generated with configuration options specified in the **TCPairsConfig** file.

The TC-Pairs tool implements the following logic:

• Parse the adeck, edeck, and bdeck data files and store them as track objects.

• Parse diagnostics data files and add the requested diagnostics to the existing adeck track objects.

• Apply configuration file settings to filter the adeck, edeck, and bdeck track data down to a subset of interest.

• Apply configuration file settings to derive additional adeck track data, such as interpolated tracks, consensus tracks, time-lagged tracks, and statistical track and intensity models.

• For each adeck track that was parsed or derived, search for a matching bdeck track with the same basin and cyclone number and overlapping valid times. If not matching against the BEST track, also ensure that the model initialization times match.

• For each adeck/bdeck track pair, match up their track points in time, lookup distances to land, compute track location errors, and write an output TCMPR line for each track point.

• For each set of edeck probabilities that were parsed, search for a matching bdeck track.

• For each edeck/bdeck pair, write paired edeck probabilities and matching bdeck values to output PROBRIRW lines.

tc_pairs configuration file
---------------------------

The default configuration file for the TC-Pairs tool named **TCPairsConfig_default** can be found in the installed *share/met/config/* directory. Users are encouraged to copy these default files before modifying their contents. The contents of the configuration file are described in the subsections below.

The contents of the tc_pairs configuration file are described below.

____________________

.. code-block:: none

  storm_id     = [];
  basin        = [];
  cyclone      = [];
  storm_name   = [];
  init_beg     = "";
  init_end     = "";
  init_inc     = [];
  init_exc     = [];
  valid_beg    = "";
  valid_end    = "";
  valid_inc    = [];
  valid_exc    = [];
  init_hour    = [];
  init_mask    = "";
  valid_mask   = "";
  lead_req     = [];
  match_points = TRUE;
  version      = "VN.N";

The configuration options listed above are common to multiple MET tools and are described in :numref:`config_options_tc`.

____________________

.. code-block:: none

  model = [ "DSHP", "LGEM", "HWRF" ];

The **model** variable contains a list of comma-separated models to be used. Each model is identified with an ATCF TECH ID (normally four unique characters). This model identifier should match the model column in the ATCF format input file. An empty list indicates that all models in the input file(s) will be processed. Note that when reading ATCF track data, all instances of the string AVN are automatically replaced with GFS.

____________________

.. code-block:: none

  write_valid = [ "20101231_06" ];

The **write_valid** entry specifies a comma-separated list of valid time strings in YYYYMMDD[_HH[MMSS]] format for which output should be written. An empty list indicates that data for all valid times should be written. This option may be useful when verifying track forecasts in realtime. If evaluating performance for a single valid time, this option can limit the output to that time and skip output for earlier track points.

____________________

.. code-block:: none

  check_dup = FALSE;

The **check_dup** flag expects either TRUE and FALSE, indicating whether the code should check for duplicate ATCF lines when building tracks. Setting **check_dup** to TRUE will check for duplicated lines, and produce output information regarding the duplicate. Any duplicated ATCF line will not be processed in the tc_pairs output. Setting **check_dup** to FALSE, will still exclude tracks that decrease with time, and will overwrite repeated lines, but specific duplicate log information will not be output. Setting **check_dup** to FALSE will make parsing the track quicker.

____________________

.. code-block:: none

  interp12 = NONE;

The **interp12** flag expects the entry NONE, FILL, or REPLACE, indicating whether special processing should be performed for interpolated forecasts. The NONE option indicates no changes are made to the interpolated forecasts. The FILL and REPLACE (default) options determine when the 12-hour interpolated forecast (normally indicated with a "2" or "3" at the end of the ATCF ID) will be renamed with the 6-hour interpolated ATCF ID (normally indicated with the letter "I" at the end of the ATCF ID). The FILL option renames the 12-hour interpolated forecasts with the 6-hour interpolated forecast ATCF ID only when the 6-hour interpolated forecasts is missing (in the case of a 6-hour interpolated forecast which only occurs every 12-hours (e.g. EMXI, EGRI), the 6-hour interpolated forecasts will be "filled in" with the 12-hour interpolated forecasts in order to provide a record every 6-hours). The REPLACE option renames all 12-hour interpolated forecasts with the 6-hour interpolated forecasts ATCF ID regardless of whether the 6-hour interpolated forecast exists. The original 12-hour ATCF ID will also be retained in the output file (all modified ATCF entries will appear at the end of the TC-Pairs output file). This functionality expects both the 12-hour and 6-hour early (interpolated) ATCF IDs to be listed in the model field.

____________________

.. code-block:: none

  consensus = [
     {
        name     = "CON1";
        members  = [ "MOD1", "MOD2", "MOD3" ];
        required = [   true,  false, false  ];
        min_req  = 2;
        write_members = TRUE;
     }
  ];

The **consensus** field allows the user to generate a user-defined consensus forecasts from any number of models. All models used in the consensus forecast need to be included in the **model** field (first entry in **TCPairsConfig_default**). The name field is the desired consensus model name. The **members** field is a comma-separated list of model IDs that make up the members of the consensus. The **required** field is a comma-separated list of true/false values associated with each consensus member. If a member is designated as true, the member is required to be present in order for the consensus to be generated. If a member is false, the consensus will be generated regardless of whether the member is present. The length of the required array must be the same length as the members array. The **min_req** field is the number of members required in order for the consensus to be computed. The required and min_req field options are applied at each forecast lead time. If any member of the consensus has a non-valid position or intensity value, the consensus for that valid time will not be generated. The **write_members** field is a boolean that indicates whether or not to write output for the individual consensus members. If set to true, standard output will show up for all members. If set to false, output for the consensus members is excluded from the output, even if they are used to define other consensus tracks in the configuration file. If a consensus model is defined in the configuration file, there will be non-missing output for the consensus track variables in the output file (NUM_MEMBERS, TRACK_SPREAD, TRACK_STDEV, MSLP_STDEV, MAX_WIND_STDEV). See the TCMPR line type definitions below.

____________________

.. code-block:: none

  lag_time = [ "06", "12" ];

The **lag_time** field is a comma-separated list of forecast lag times to be used in HH[MMSS] format. For each adeck track identified, a lagged track will be derived for each entry. In the tc_pairs output, the original adeck record will be retained, with the lagged entry listed as the adeck name with "_LAG_HH" appended.

____________________

.. code-block:: none

  best_technique = [ "BEST" ];
  best_baseline  = [ "BCLP", "BCD5", "BCLA" ];

The **best_technique** field specifies a comma-separated list of technique name(s) to be interpreted as BEST track data. The default value (BEST) should suffice for most users. The **best_baseline** field specifies a comma-separated list of CLIPER/SHIFOR baseline forecasts to be derived from the best tracks. Specifying multiple **best_technique** values and at least one **best_baseline** value results in a warning since the derived baseline forecast technique names may be used multiple times.

The following are valid baselines for the **best_baseline** field:

**BTCLIP**: Neumann original 3-day CLIPER in best track mode. Used for the Atlantic basin only. Specify model as BCLP.

**BTCLIP5**: 5-day CLIPER (:ref:`Aberson, 1998 <Aberson-1998>`)/SHIFOR (:ref:`DeMaria and Knaff, 2003 <Knaff-2003>`) in best track mode for either Atlantic or eastern North Pacific basins. Specify model as BCS5.

**BTCLIPA**: Sim Aberson's recreation of Neumann original 3-day CLIPER in best-track mode. Used for Atlantic basin only. Specify model as BCLA.

____________________

.. code-block:: none

  oper_technique = [ "CARQ" ];
  oper_baseline  = [ "OCLP", "OCS5", "OCD5" ];

The **oper_technique** field specifies a comma-separated list of technique name(s) to be interpreted as operational track data. The default value (CARQ) should suffice for most users. The **oper_baseline** field specifies a comma-separated list of CLIPER/SHIFOR baseline forecasts to be derived from the operational tracks. Specifying multiple **oper_technique** values and at least one **oper_baseline** value results in a warning since the derived baseline forecast technique names may be used multiple times.

The following are valid baselines for the **oper_baseline** field:

**OCLIP**: Merrill modified (operational) 3-day CLIPER run in operational mode. Used for Atlantic basin only. Specify model as OCLP.

**OCLIP5**: 5-day CLIPER (:ref:`Aberson, 1998 <Aberson-1998>`)/ SHIFOR (:ref:`DeMaria and Knaff, 2003 <Knaff-2003>`) in operational mode, rerun using CARQ data. Specify model as OCS5.

**OCLIPD5**: 5-day CLIPER (:ref:`Aberson, 1998 <Aberson-1998>`)/ DECAY-SHIFOR (:ref:`DeMaria and Knaff, 2003 <Knaff-2003>`). Specify model as OCD5.

____________________

.. code-block:: none

  anly_track = BDECK;

Analysis tracks consist of multiple track points with a lead time of zero for the same storm. An analysis track may be generated by running model analysis fields through a tracking algorithm. The **anly_track** field specifies which datasets should be searched for analysis track data and may be set to **NONE, ADECK, BDECK**, or **BOTH**. Use **BOTH** to create pairs using two different analysis tracks.

____________________

.. code-block:: none

  match_points = TRUE;

The **match_points** field specifies whether only those track points common to both the adeck and bdeck tracks should be written out. If **match_points** is selected as FALSE, the union of the adeck and bdeck tracks will be written out, with "NA" listed for unmatched data.

____________________

.. code-block:: none

  dland_file = "MET_BASE/tc_data/dland_global_tenth_degree.nc";

The **dland_file** string specifies the path of the NetCDF format file (default file: dland_global_tenth_degree.nc) to be used for the distance to land check in the tc_pairs code. This file is generated using tc_dland (default file provided in installed *share/met/tc_data* directory).

____________________

.. code-block:: none

 watch_warn = {
     file_name   = "MET_BASE/tc_data/wwpts_us.txt";
     time_offset = -14400;
  }

The **watch_warn** field specifies the file name and time applied offset to the **watch_warn** flag. The **file_name** string specifies the path of the watch/warning file to be used to determine when a watch or warning is in effect during the forecast initialization and verification times. The default file is named **wwpts_us.txt**, which is found in the installed *share/met/tc_data/* directory within the MET build. The **time_offset** string is the time window (in seconds) assigned to the watch/warning. Due to the non-uniform time watches and warnings are issued, a time window is assigned for which watch/warnings are included in the verification for each valid time. The default watch/warn file is static, and therefore may not include warned storms beyond the current MET code release date; therefore users may wish to create a post in the `METplus GitHub Discussions Forum <https://github.com/dtcenter/METplus/discussions>`_ in order to obtain the most recent watch/warning file if the static file does not contain storms of interest.

____________________

.. code-block:: none

 diag_info_map = [
    {
       diag_source    = "CIRA_DIAG_RT";
       track_source   = "GFS";
       field_source   = "GFS_0p50";
       match_to_track = [ "GFS" ];
       diag_name      = [];
    },
    {
       diag_source    = "SHIPS_DIAG_RT";
       track_source   = "SHIPS_TRK";
       field_source   = "GFS_0p50";
       match_to_track = [ "OFCL" ];
       diag_name      = [];
    }
 ];

A TCMPR line is written to the output for each track point. If diagnostics data is also defined for that track point, a TCDIAG line is written immediately after the corresponding TCMPR line. The contents of that TCDIAG line is determined by the **diag_info_map** entry.

The **diag_info_map** entries define how the diagnostics read with the **-diag** command line option should be used. Each array element is a dictionary consisting of entries for **diag_source**, **track_source**, **field_source**, **match_to_track**, and **diag_name**.

The **diag_source** entry is one of the supported diagnostics data sources. The **track_source** entry is a string defining the ATCF ID of the track data used to define the locations at which diagnostics are computed. This string is written to the **TRACK_SOURCE** column of the TCDIAG output line. The **field_source** entry is a string describing the gridded model data from which the diagnostics are computed. This string is written to the **FIELD_SOURCE** column of the TCDIAG output line type. The **match_to_track** entry specifies a comma-separated list of strings defining the ATCF ID(s) of the tracks to which these diagnostic values should be matched. The **diag_name** entry specifies a comma-separated list of strings for the tropical cyclone diagnostics of interest. If a non-zero list of diagnostic names is specified, only those diagnostics appearing in the list are written to the TCDIAG output line type. If defined as an empty list (default), all diagnostics found in the input are written to the TCDIAG output lines.

____________________

.. code-block:: none

 diag_convert_map = [
    {
       diag_source = "CIRA_DIAG";
       key         = [ "(10C)", "(10KT)", "(10M/S)" ];
       convert(x)  = x / 10;
    },
    {
       diag_source = "SHIPS_DIAG";
       key         = [ "LAT",  "LON",  "CSST", "RSST", "DSST", "DSTA", "XDST", "XNST", "NSST", "NSTA",
                       "NTMX", "NTFR", "U200", "U20C", "V20C", "E000", "EPOS", "ENEG", "EPSS", "ENSS",
                       "T000", "TLAT", "TLON", "TWAC", "TWXC", "G150", "G200", "G250", "V000", "V850",
                       "V500", "V300", "SHDC", "SHGC", "T150", "T200", "T250", "SHRD", "SHRS", "SHRG",
                       "HE07", "HE05", "PW01", "PW02", "PW03", "PW04", "PW05", "PW06", "PW07", "PW08",
                       "PW09", "PW10", "PW11", "PW12", "PW13", "PW14", "PW15", "PW16", "PW17", "PW18",
                       "PW20", "PW21" ];
       convert(x)  = x / 10;
    },
    {
       diag_source = "SHIPS_DIAG";
       key         = [ "VVAV", "VMFX", "VVAC" ];
       convert(x)  = x / 100;
    },
    {
        diag_source = "SHIPS_DIAG";
        key         = [ "TADV" ];
        convert(x)  = x / 1000000;
    },
    {
       diag_source = "SHIPS_DIAG";
       key         = [ "Z850", "D200", "TGRD", "DIVC" ];
       convert(x)  = x / 10000000;
    },
    {
       diag_source = "SHIPS_DIAG";
       key         = [ "PENC", "PENV" ];
       convert(x)  = x / 10 + 1000;
    }
 ];

The **diag_convert_map** entries define conversion functions to be applied to diagnostics data read with the **-diag** command line option. Each array element is a dictionary consisting of a **diag_source**, **key**, and **convert(x)** entry.

The **diag_source** entry is one of the supported diagnostics data sources. Partial string matching logic is applied, so **SHIPS_DIAG** entries are matched to both **SHIPS_DIAG_RT** and **SHIPS_DIAG_DEV** diagnostic sources. The **key** entry is an array of strings. The strings can specify diagnostic names or units, although units are only checked for **CIRA_DIAG** sources. If both the name and units are specified, the conversion function for the name takes precedence. The **convert(x)** entry is a function of one variable which defines how the diagnostic data should be converted. The defined function is applied to any diagnostic value whose name or units appears in the **key**.

____________________

.. code-block:: none

  basin_map = [
     { key = "SI"; val = "SH"; },
     { key = "SP"; val = "SH"; },
     { key = "AU"; val = "SH"; },
     { key = "AB"; val = "IO"; },
     { key = "BB"; val = "IO"; }
  ];

The **basin_map** entry defines a mapping of input names to output values.
Whenever the basin string matches "key" in the input ATCF files, it is
replaced with "val". This map can be used to modify basin names to make them
consistent across the ATCF input files.

Many global modeling centers use ATCF basin identifiers based on region
(e.g., 'SP' for South Pacific Ocean, etc.), however the best track data
provided by the Joint Typhoon Warning Center (JTWC) use just one basin
identifier 'SH' for all of the Southern Hemisphere basins. Additionally,
some modeling centers may report basin identifiers separately for the Bay
of Bengal (BB) and Arabian Sea (AB) whereas JTWC uses 'IO'.

The basin mapping allows MET to map the basin identifiers to the expected
values without having to modify your data. For example, the first entry
in the list below indicates that any data entries for 'SI' will be matched
as if they were 'SH'. In this manner, all verification results for the
Southern Hemisphere basins will be reported together as one basin.

An empty list indicates that no basin mapping should be used. Use this if
you are not using JTWC best tracks and you would like to match explicitly
by basin or sub-basin. Note that if your model data and best track do not
use the same basin identifier conventions, using an empty list for this
parameter will result in missed matches.

.. _tc_pairs-output:

tc_pairs output
---------------

TC-Pairs produces output in TCST format. The default output file name can be overwritten using the -out file argument in the usage statement. The TCST file output from TC-Pairs may be used as input into the TC-Stat tool. The header column in the TC-Pairs output is described in :numref:`TCST Header`.

.. _TCST Header:

.. list-table:: Header information for TC-Pairs TCST output.
  :widths: auto
  :header-rows: 2

  * - 
    - 
    - HEADER
  * - Column Number
    - Header Column Name
    - Description
  * - 1
    - VERSION
    - Version number
  * - 2
    - AMODEL
    - User provided text string designating model name
  * - 3
    - BMODEL
    - User provided text string designating model name
  * - 4
    - DESC
    - User provided description text string
  * - 5
    - STORM_ID
    - BBCCYYYY designation of storm
  * - 6
    - BASIN
    - Basin (BB in STORM_ID)
  * - 7
    - CYCLONE
    - Cyclone number (CC in STORM_ID)
  * - 8
    - STORM_NAME
    - Name of Storm
  * - 9
    - INIT
    - Initialization time of forecast in YYYYMMDD_HHMMSS format.
  * - 10
    - LEAD
    - Forecast lead time in HHMMSS format.
  * - 11
    - VALID
    - Forecast valid time in YYYYMMDD_HHMMSS format.
  * - 12
    - INIT_MASK
    - Initialization time masking grid applied
  * - 13
    - VALID_MASK
    - Valid time masking grid applied
  * - 14
    - LINE_TYPE
    - Output line types described below

.. _TCMPR Line Type:

.. list-table:: Format information for TCMPR (Tropical Cyclone Matched Pairs) output line type.
  :widths: auto
  :header-rows: 2

  * - 
    - 
    - TCMPR OUTPUT FORMAT
  * - Column Number
    - Header Column Name
    - Description
  * - 14
    - TCMPR
    - Tropical Cyclone Matched Pair line type
  * - 15
    - TOTAL
    - Total number of pairs in track
  * - 16
    - INDEX
    - Index of the current track pair
  * - 17
    - LEVEL
    - Level of storm classification
  * - 18
    - WATCH_WARN
    - HU or TS watch or warning in effect
  * - 19
    - INITIALS
    - Forecaster initials
  * - 20
    - ALAT
    - Latitude position of adeck model
  * - 21
    - ALON
    - Longitude position of adeck model
  * - 22
    - BLAT
    - Latitude position of bdeck model
  * - 23
    - BLON
    - Longitude position of bdeck model
  * - 24
    - TK_ERR
    - Track error of adeck relative to bdeck (nm)
  * - 25
    - X_ERR
    - X component position error (nm)
  * - 26
    - Y_ERR
    - Y component position error (nm)
  * - 27
    - ALTK_ERR
    - Along track error (nm)
  * - 28
    - CRTK_ERR
    - Cross track error (nm)
  * - 29
    - ADLAND
    - adeck distance to land (nm)
  * - 30
    - BDLAND
    - bdeck distance to land (nm)
  * - 31
    - AMSLP
    - adeck mean sea level pressure
  * - 32
    - BMSLP
    - bdeck mean sea level pressure
  * - 33
    - AMAX_WIND
    - adeck maximum wind speed
  * - 34
    - BMAX_WIND
    - bdeck maximum wind speed
  * - 35, 36
    - A/BAL_WIND_34
    - a/bdeck 34-knot radius winds in full circle
      or the mean of the non-zero 34-knot wind quadrants
  * - 37, 38
    - A/BNE_WIND_34
    - a/bdeck 34-knot radius winds in NE quadrant
  * - 39, 40
    - A/BSE_WIND_34
    - a/bdeck 34-knot radius winds in SE quadrant
  * - 41, 42
    - A/BSW_WIND_34
    - a/bdeck 34-knot radius winds in SW quadrant
  * - 43, 44
    - A/BNW_WIND_34
    - a/bdeck 34-knot radius winds in NW quadrant
  * - 45, 46
    - A/BAL_WIND_50
    - a/bdeck 50-knot radius winds in full circle
      or the mean of the non-zero 50-knot wind quadrants
  * - 47, 48
    - A/BNE_WIND_50
    - a/bdeck 50-knot radius winds in NE quadrant
  * - 49, 50
    - A/BSE_WIND_50
    - a/bdeck 50-knot radius winds in SE quadrant
  * - 51, 52
    - A/BSW_WIND_50
    - a/bdeck 50-knot radius winds in SW quadrant
  * - 53, 54
    - A/BNW_WIND_50
    - a/bdeck 50-knot radius winds in NW quadrant
  * - 55, 56
    - A/BAL_WIND_64
    - a/bdeck 64-knot radius winds in full circle
      or the mean of the non-zero 64-knot wind quadrants
  * - 57, 58
    - A/BNE_WIND_64
    - a/bdeck 64-knot radius winds in NE quadrant
  * - 59, 60
    - A/BSE_WIND_64
    - a/bdeck 64-knot radius winds in SE quadrant
  * - 61, 62
    - A/BSW_WIND_64
    - a/bdeck 64-knot radius winds in SW quadrant
  * - 63, 64
    - A/BNW_WIND_64
    - a/bdeck 64-knot radius winds in NW quadrant
  * - 65, 66
    - A/BRADP
    - pressure in millibars of the last closed isobar, 900 - 1050 mb
  * - 67, 68
    - A/BRRP
    - radius of the last closed isobar in nm, 0 - 9999 nm
  * - 69, 70
    - A/BMRD
    - radius of max winds, 0 - 999 nm
  * - 71, 72
    - A/BGUSTS
    - gusts, 0 through 995 kts
  * - 73, 74
    - A/BEYE
    - eye diameter, 0 through 999 nm
  * - 75, 76
    - A/BDIR
    - storm direction in compass coordinates, 0 - 359 degrees
  * - 77, 78
    - A/BSPEED
    - storm speed, 0 - 999 kts
  * - 79, 80
    - A/BDEPTH
    - system depth, D-deep, M-medium, S-shallow, X-unknown
  * - 81
    - NUM_MEMBERS
    - consensus variable: number of models (or ensemble members) that were used to build the consensus track
  * - 82
    - TRACK_SPREAD
    - consensus variable: the mean of the distances from the member location to the consensus track location (nm)
  * - 83
    - TRACK_STDEV
    - consensus variable: the standard deviation of the distances from the member locations to the consensus track location (nm)
  * - 84
    - MSLP_STDEV
    - consensus variable: the standard deviation of the member's mean sea level pressure values 
  * - 85
    - MAX_WIND_STDEV
    - consensus variable: the standard deviation of the member's maximum wind speed values 

.. _TCDIAG Line Type:

.. list-table:: Format information for TCDIAG (Tropical Cyclone Diagnostics) output line type.
  :widths: auto
  :header-rows: 2

  * -
    -
    - TCDIAG OUTPUT FORMAT
  * - Column Number
    - Header Column Name
    - Description
  * - 14
    - TCDIAG
    - Tropical Cyclone Diagnostics line type
  * - 15
    - TOTAL
    - Total number of pairs in track
  * - 16
    - INDEX
    - Index of the current track pair
  * - 17
    - DIAG_SOURCE
    - Diagnostics data source indicated by the `-diag` command line option
  * - 18
    - TRACK_SOURCE
    - ATCF ID of the track data used to define the diagnostics
  * - 19
    - FIELD_SOURCE
    - Description of gridded field data source used to define the diagnostics
  * - 20
    - N_DIAG
    - Number of storm diagnostic name and value columns to follow
  * - 21
    - DIAG_i
    - Name of the of the ith storm diagnostic (repeated)
  * - 22
    - VALUE_i
    - Value of the ith storm diagnostic (repeated)

.. _PROBRIRW Line Type:

.. list-table:: Format information for PROBRIRW (Probability of Rapid Intensification/Weakening) output line type.
  :widths: auto
  :header-rows: 2

  * - 
    - 
    - PROBRIRW OUTPUT FORMAT
  * - Column Number
    - Header Column Name
    - Description
  * - 14
    - PROBRIRW
    - Probability of Rapid Intensification/Weakening line type
  * - 15
    - ALAT
    - Latitude position of edeck model
  * - 16
    - ALON
    - Longitude position of edeck model
  * - 17
    - BLAT
    - Latitude position of bdeck model
  * - 18
    - BLON
    - Longitude position of bdeck model
  * - 19
    - INITIALS
    - Forecaster initials
  * - 20
    - TK_ERR
    - Track error of adeck relative to bdeck (nm)
  * - 21
    - X_ERR
    - X component position error (nm)
  * - 22
    - Y_ERR
    - Y component position error (nm)
  * - 23
    - ADLAND
    - adeck distance to land (nm)
  * - 24
    - BDLAND
    - bdeck distance to land (nm)
  * - 25
    - RI_BEG
    - Start of RI time window in HH format
  * - 26
    - RI_END
    - End of RI time window in HH format
  * - 27
    - RI_WINDOW
    - Width of RI time window in HH format
  * - 28
    - AWIND_END
    - Forecast maximum wind speed at RI end
  * - 29
    - BWIND_BEG
    - Best track maximum wind speed at RI begin
  * - 30
    - BWIND_END
    - Best track maximum wind speed at RI end
  * - 31
    - BDELTA
    - Exact Best track wind speed change in RI window
  * - 32
    - BDELTA_MAX
    - Maximum Best track wind speed change in RI window
  * - 33
    - BLEVEL_BEG
    - Best track storm classification at RI begin
  * - 34
    - BLEVEL_END
    - Best track storm classification at RI end
  * - 35
    - N_THRESH
    - Number of probability thresholds
  * - 36
    - THRESH_i
    - The ith probability threshold value (repeated)
  * - 37
    - PROB_i
    - The ith probability value (repeated)
