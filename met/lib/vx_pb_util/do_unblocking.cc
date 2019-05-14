

//////////////////////////////////////////////////////////////////////////////////


using namespace std;

#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <cmath>

#include "vx_pb_util/copy_bytes.h"
#include "vx_pb_util/do_unblocking.h"


//////////////////////////////////////////////////////////////////////////////////


static int read_pad(int fd, PadSize);


//////////////////////////////////////////////////////////////////////////////////


void do_unblocking(int in, int out, PadSize padsize)

{

int rec_size1, rec_size2;


while ( (rec_size1 = read_pad(in, padsize)) > 0 )  {

   copy_bytes(in, out, rec_size1);

   rec_size2 = read_pad(in, padsize);

   if ( rec_size1 != rec_size2 )  {

      cerr << "\n\nERROR: do_unblocking() -> "
           << "first and second record sizes don't match!\n\n";

      exit ( 1 );

   }

}   //  while


   //
   //  done
   //

return;

}


//////////////////////////////////////////////////////////////////////////////////


int read_pad(int fd, PadSize padsize)

{

int n_read, bytes;
int value;
unsigned int I;
unsigned long long L;
unsigned char * b = (unsigned char *) 0;


switch ( padsize )  {

   case padsize_4:
      bytes = 4;
      b = (unsigned char *) (&I);
      break;

   case padsize_8:
      bytes = 8;
      b = (unsigned char *) (&L);
      break;

   default:
      cerr << "\n\nERROR: read_pad() -> "
           << "bad pad size\n\n";
      exit ( 1 );
      break;

}   //  switch


n_read = read(fd, b, bytes);

if ( n_read == 0 )  return ( 0 );

if ( (n_read < 0) || ((n_read > 0) && (n_read != bytes)) )  {

      cerr << "\n\nERROR: read_pad() -> "
           << "read error\n\n";

   exit ( 1 );

}


switch ( padsize )  {

   case padsize_4:
      value = I;
      break;

   case padsize_8:
      value = (int) L;
      break;

   default:
      cerr << "\n\nERROR: read_pad() -> "
           << "bad pad size\n\n";
      exit ( 1 );
      break;

}   //  switch

   //
   //  done
   //

return ( value );

}


//////////////////////////////////////////////////////////////////////////////////


