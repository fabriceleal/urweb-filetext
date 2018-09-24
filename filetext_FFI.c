#include "filetext_FFI.h"

uw_Basis_string uw_Filetext_FFI_blobAsText (uw_context ctx,
		uw_Basis_blob blob) {

  // TODO check if blob.data is a valid ascii string
  // that means no \0 in the middle, no unprintable chars
  // TODO do i need to handle the byte order mask of utf8 files?
  // TODO are ascii files any different?
  
  if(blob.size < 1)
    goto invalid;

  int offset = 0;
  
  if(blob.size > 2) {
    if(blob.data[0] == -17 &&
       blob.data[1] == -69 &&
       blob.data[2] == -65)
      {
	// UTF8
	offset = 3;
      }
  }
  
  if(blob.size == offset)
    goto invalid;
  
  for(int i = offset; i < blob.size; ++i)
    {
      if(blob.data[i] == '\0')
	goto invalid;
    }

  goto valid;

 invalid:

  return "";

 valid:
    
  return blob.data + offset;
}
