// *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*
// ** Copyright UCAR (c) 1992 - 2024
// ** University Corporation for Atmospheric Research (UCAR)
// ** National Center for Atmospheric Research (NCAR)
// ** Research Applications Lab (RAL)
// ** P.O.Box 3000, Boulder, Colorado, 80307-3000, USA
// *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*


///////////////////////////////////////////////////////////////////////////////

#ifndef __VAR_INFO_UGRID_H__
#define __VAR_INFO_UGRID_H__

///////////////////////////////////////////////////////////////////////////////

#include "var_info.h"

#include "data_file_type.h"
#include "long_array.h"
#include "math_constants.h"
#include "nc_constants.h"
#include "bool_array.h"

///////////////////////////////////////////////////////////////////////////////

class VarInfoUGrid : public VarInfo
{
   private:

      //
      // NetCDF-specific parameters
      //

      LongArray Dimension; // Dimension values for extracting 2D field
      BoolArray Is_offset; // boolean for Dimension value (true: offset, false: value to be an offset (false for value)
      NumArray  Dim_value; // Dimension values as float for extracting 2D field

      void init_from_scratch();
      void assign(const VarInfoUGrid &);
      void clear_dimension();

   public:
      VarInfoUGrid();
      ~VarInfoUGrid();
      VarInfoUGrid(const VarInfoUGrid &);
      VarInfoUGrid & operator=(const VarInfoUGrid &);
      VarInfo *clone() const;

      void dump(std::ostream &) const;
      void clear();

      //
      // get stuff
      //

      GrdFileType       file_type()      const;
      const LongArray & dimension()      const;
      int               dimension(int i) const;
      const NumArray  & dim_value()      const;
      double            dim_value(int i) const;
      const BoolArray & is_offset()      const;
      bool              is_offset(int i) const;
      int               n_dimension()    const;

      //
      // set stuff
      //

      void set_magic(const ConcatString &, const ConcatString &);
      void set_dict(Dictionary &s);

      void add_dimension(int dim, bool as_offset=true, double dim_value=bad_data_double);

      //
      // do stuff
      //

      bool is_precipitation()     const;
      bool is_specific_humidity() const;
      bool is_u_wind()            const;
      bool is_v_wind()            const;
      bool is_wind_speed()        const;
      bool is_wind_direction()    const;
};

///////////////////////////////////////////////////////////////////////////////

inline GrdFileType       VarInfoUGrid::file_type()      const { return(FileType_UGrid);         }
inline const LongArray & VarInfoUGrid::dimension()      const { return(Dimension);             }
inline int               VarInfoUGrid::dimension(int i) const { return(Dimension[i]);          }
inline int               VarInfoUGrid::n_dimension()    const { return(Dimension.n_elements());}
inline const NumArray  & VarInfoUGrid::dim_value()      const { return(Dim_value);             }
inline double            VarInfoUGrid::dim_value(int i) const { return(Dim_value[i]);          }
inline const BoolArray & VarInfoUGrid::is_offset()      const { return(Is_offset);             }
inline bool              VarInfoUGrid::is_offset(int i) const { return(Is_offset[i]);          }

///////////////////////////////////////////////////////////////////////////////

#endif  // __VAR_INFO_UGRID_H__

///////////////////////////////////////////////////////////////////////////////