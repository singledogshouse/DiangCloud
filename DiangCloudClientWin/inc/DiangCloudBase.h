#ifndef _DIANGCLOUD_BASE_H_
#define _DIANGCLOUD_BASE_H_

#include <assert.h>

#define TEMP_SERVER_ADRESS	"127.0.0.1"
#define TEMP_SERVER_PORT	12345
#define TEMP_CLIENT_PORT	12346
#define TEMP_FILE_PATH		"D:\\test.txt"

inline void ASSERT(const char *prompt)
{
	assert(*prompt && false);
}

#endif // _DIANGCLOUD_BASE_H_

