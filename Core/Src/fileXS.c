/*
 * fileXS.c
 *
 *  Created on: Jan 29, 2024
 *      Author: tj925438
 */

#include "FileXS.h"

/* create the file content, on flash memory */

static const unsigned char _FILE_0_Content[] =
"enter a URL as IPADDR/index.html"
;

static const unsigned char _FILE_1_Content[] =
"<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\">\r\n\
<html xmlns:v=\"urn:schemas-microsoft-com:vml\" xmlns:o=\"urn:schemas-microsoft-com:office:office\" xmlns:w=\"urn:schemas-microsoft-com:office:word\" xmlns=\"http://www.w3.org/TR/REC-html40\">\r\n\
<head>\r\n\
<meta http-equiv=\"Content-Type\" content=\"text/html; charset=iso-8859-1\">\r\n\
<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">\r\n\
<title> \r\n\
USB ECM Web Page\r\n\
</title>\r\n\
<style>\r\n\
#more {display: none;}\r\n\
ol{\r\n\
margin-left: -1.3em;\r\n\
}\r\n\
ol:before {\r\n\
content: '- ';\r\n\
margin: 26px;\r\n\
}\r\n\
</style>\r\n\
</head>\r\n\
<body style=\"\" lang=\"EN-US\" link=\"blue\" vlink=\"blue\">\r\n\
<h2>Welcome to the Web Page</h2>\r\n\
<a href=\"page2.html\">Page 2</a>\r\n\
</body>\r\n\
</html>\r\n"
;

static const unsigned char _FILE_2_Content[] =
"<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\">\r\n\
<html xmlns:v=\"urn:schemas-microsoft-com:vml\" xmlns:o=\"urn:schemas-microsoft-com:office:office\" xmlns:w=\"urn:schemas-microsoft-com:office:word\" xmlns=\"http://www.w3.org/TR/REC-html40\">\r\n\
<head>\r\n\
<meta http-equiv=\"Content-Type\" content=\"text/html; charset=iso-8859-1\">\r\n\
<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">\r\n\
<title> \r\n\
USB ECM Web Page\r\n\
</title>\r\n\
<style>\r\n\
#more {display: none;}\r\n\
ol{\r\n\
margin-left: -1.3em;\r\n\
}\r\n\
ol:before {\r\n\
content: '- ';\r\n\
margin: 26px;\r\n\
}\r\n\
</style>\r\n\
</head>\r\n\
<body style=\"\" lang=\"EN-US\" link=\"blue\" vlink=\"blue\">\r\n\
<h2>Welcome to the Page 2</h2>\r\n\
<form method=\"post\" action=\"/page2.html\">\r\n\
<input value=\"LED_ON\" name=\"led\" type=\"radio\">LED ON<br>\r\n\
<input value=\"LED_OFF\" name=\"led\" type=\"radio\">LED OFF<br>\r\n\
<br>\r\n\
<input value=\"Send\" type=\"submit\"></form>\r\n\
<p><a href=\"index.html\">back to home</a></p>\r\n\
</body>\r\n\
</html>\r\n"
;

static FileXSContentDescriptor contentDescriptor[] = {
		{
				"/",							/* just "/", just IP address entered - sent as "text/plain" */
				sizeof(_FILE_0_Content) -1,		/* without NUL */
				_FILE_0_Content
		},
		{
				"/index.html",
				sizeof(_FILE_1_Content) -1,		/* without NUL */
				_FILE_1_Content
		},
		{
				"/page2.html",
				sizeof(_FILE_2_Content) -1,
				_FILE_2_Content
		}
};

static FX_FILE fxs_file = {
		.fx_file_id = -1
};

static int findDescriptor(CHAR *file_name)
{
	int i;
	for (i = 0; i < (sizeof(contentDescriptor) / sizeof(FileXSContentDescriptor)); i++)
	{
		if (strcmp(file_name, contentDescriptor[i].file_name) == 0)
		{
			return i;
		}
	}

	return -1;
}

/* implement the FileX functions needed */

UINT  fxs_file_open(FX_MEDIA *media_ptr, FX_FILE *file_ptr, CHAR *file_name, UINT open_type)
{
	int i;

	if (fxs_file.fx_file_id != -1)
		return(FX_ALREADY_CREATED);					//already open

	i = findDescriptor(file_name);
	if ( i != -1)
	{
		fxs_file.fx_file_id = i;
		fxs_file.fx_file_current_logical_offset = 0;
		fxs_file.fx_file_current_file_size = contentDescriptor[i].file_size;

		file_ptr->fx_file_id = i;
		return(FX_SUCCESS);
	}

	return(FX_NOT_FOUND);
}

UINT  fxs_directory_information_get(FX_MEDIA *media_ptr, CHAR *directory_name,
                                    UINT *attributes, ULONG *size,
                                    UINT *year, UINT *month, UINT *day,
                                    UINT *hour, UINT *minute, UINT *second)
{
	int i;

	i = findDescriptor(directory_name);
	if ( i != -1)
	{
		if (size)
			*size = contentDescriptor[i].file_size;

		return(FX_SUCCESS);
	}

	return(FX_NOT_FOUND);
}

UINT  fxs_file_read(FX_FILE *file_ptr, VOID *buffer_ptr, ULONG request_size, ULONG *actual_size)
{
	ULONG rdSize;

	if (fxs_file.fx_file_id == -1)
	{
		*actual_size = 0;
		return(FX_NOT_OPEN);
	}

	if (request_size > (fxs_file.fx_file_current_file_size - fxs_file.fx_file_current_logical_offset))
		rdSize = fxs_file.fx_file_current_file_size - fxs_file.fx_file_current_logical_offset;
	else
		rdSize = request_size;

	if (rdSize)
	{
		memcpy(buffer_ptr, contentDescriptor[fxs_file.fx_file_id].file_content + fxs_file.fx_file_current_logical_offset, rdSize);

		*actual_size = rdSize;
		fxs_file.fx_file_current_logical_offset += rdSize;

		return(FX_SUCCESS);
	}

	return(FX_END_OF_FILE);
}

UINT  fxs_file_close(FX_FILE *file_ptr)
{
	fxs_file.fx_file_id = -1;

	return(FX_SUCCESS);
}
