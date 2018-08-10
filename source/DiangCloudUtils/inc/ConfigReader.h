
#ifndef _CONFIG_READER_H_H_
#define _CONFIG_READER_H_H_

#include <string>

using namespace std;

#ifndef _DLLEXP
#define _DLLEXP					__declspec(dllexport)
#endif //_DLLEXP

class ConfigReaderImpl;

class _DLLEXP ConfigReader
{
public:
	ConfigReader();
	~ConfigReader();

public:
	string getAddress();
	unsigned short getPort();
	bool init();

private:
	ConfigReaderImpl *m_impl;
};

#endif // !_CONFIG_READER_H_H_
