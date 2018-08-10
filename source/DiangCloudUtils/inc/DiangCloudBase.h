#ifndef _DIANGCLOUD_BASE_H_
#define _DIANGCLOUD_BASE_H_

#include <string>

#ifndef _DLLEXP
#define _DLLEXP					__declspec(dllexport)
#endif //_DLLEXP
#define CONFIG_FILE_PATH		".\\config.ini"
#define LOG_FILE_PATH			".\\log.log"
#define DEFAULT_ADDRESS			"localhost"
#define DEFAULT_SERVER_PORT		12345
#define DEFAULT_CLIENT_PORT		12346

using namespace std;

namespace DC_BASE
{
	_DLLEXP inline void ASSERT(const char *prompt = "");
	_DLLEXP void WRITELOG(string log);
	_DLLEXP inline void DCERROR(string msg);
}
#endif // _DIANGCLOUD_BASE_H_

