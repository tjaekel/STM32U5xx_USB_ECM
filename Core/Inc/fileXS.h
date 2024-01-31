#ifndef __FILEXS_H__
#define __FILEXS_H__

//#include "tx_port.h"
//#include "fx_api.h"

#include "fx_api.h"
#include "fx_system.h"
#include "fx_file.h"

typedef struct {
	CHAR *file_name;
	ULONG file_size;
	const unsigned char *file_content;
} FileXSContentDescriptor;

UINT  fxs_file_open(FX_MEDIA *media_ptr, FX_FILE *file_ptr, CHAR *file_name, UINT open_type);
UINT  fxs_directory_information_get(FX_MEDIA *media_ptr, CHAR *directory_name,
                                    UINT *attributes, ULONG *size,
                                    UINT *year, UINT *month, UINT *day,
                                    UINT *hour, UINT *minute, UINT *second);
UINT  fxs_file_read(FX_FILE *file_ptr, VOID *buffer_ptr, ULONG request_size, ULONG *actual_size);
UINT  fxs_file_close(FX_FILE *file_ptr);

#endif

