
#include "DiangCloudBase.h"

#include <assert.h>
#include <fstream>
#include <time.h>
#include <iomanip>

namespace DC_BASE
{
	inline void ASSERT(const char *prompt /*= ""*/)
	{
		assert(*prompt && false);
	}

	void WRITELOG(string log)
	{
		time_t t = time(nullptr);
		ofstream outFile;
		outFile.open(LOG_FILE_PATH,
			fstream::out | fstream::app);
		if (!outFile.is_open())
		{
			ASSERT("OPEN LOG FAILED!");
			return;
		}
		outFile << put_time(localtime(&t), "%c")
				<<"  "
				<< log
				<< endl;
		outFile.close();
	}
	void DCERROR(string msg)
	{
		WRITELOG(msg);
		ASSERT(msg.c_str());
	}
}