#include "filetext_FFI.h"

uw_Basis_string uw_Filetext_FFI_blobAsText (uw_context ctx,
		uw_Basis_blob blob) {

  // TODO check if blob.data is a valid ascii string
  // that means no \0 in the middle, no unprintable chars
  
  if(blob.size < 1)
    goto invalid;
  
  for(int i = 0; i < blob.size; ++i)
    {
      if(blob.data[i] == '\0')
	goto invalid;
    }

  goto valid;

 invalid:

  return "";

 valid:
    
  return blob.data;
}
