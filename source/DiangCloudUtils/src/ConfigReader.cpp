
#include "ConfigReader.h"
#include "DiangCloudBase.h"
#include <fstream>
#include <algorithm>

using namespace DC_BASE;

///////////////////////////////////
// Implement
class ConfigReaderImpl
{
public:
	ConfigReaderImpl();
	~ConfigReaderImpl() {}

public:
	string getAddress();
	unsigned short getPort();
	bool init();

private:
	string			m_address;
	unsigned short	m_port;
};

ConfigReaderImpl::ConfigReaderImpl()
	: m_port(DEFAULT_SERVER_PORT)
	, m_address(DEFAULT_ADDRESS)
{

}

string ConfigReaderImpl::getAddress()
{
	return m_address;
}

unsigned short ConfigReaderImpl::getPort()
{
	return m_port;
}

bool ConfigReaderImpl::init()
{
	ifstream inFile;
	inFile.open(CONFIG_FILE_PATH);
	if (!inFile.is_open())
	{
		DCERROR("Open config file failed.");
		return false;
	}
	string line;
	while (getline(inFile, line))
	{
		size_t posStart = line.find("[");
		if (string::npos == posStart)
		{
			continue;
		}
		size_t posEnd = line.find("]");
		if (string::npos == posEnd || posEnd <= posStart)
		{
			continue;
		}
		string key = line.substr(posStart + 1, posEnd - posStart - 1);
		transform(key.begin(), key.end(), key.begin(), ::toupper);

		string val;
		if ("ADDRESS" != key && "PORT" != key)
		{
			continue;
		}
		if (!getline(inFile, val))
		{
			break;
		}

		if (!val.empty())
		{
			size_t index = string::npos;
			while ((index = val.find(' ')) != string::npos)
	        {
				val.erase(index, 1);
			}
			while ((index = val.find('\t')) != string::npos)
			{
				val.erase(index, 1);
			}
		}
		
		if ("ADDRESS" == key)
		{
			m_address = val;
			WRITELOG("Using user-defined address: " + val);
		}
		else if ("PORT" == key)
		{
			m_port = stoi(val.c_str());
			WRITELOG("Using user-defined address: " + val);
		}
	}

	return true;
}
///////////////////////////////////

ConfigReader::ConfigReader()
{
	m_impl = new ConfigReaderImpl;
}

ConfigReader::~ConfigReader()
{
	delete m_impl;
	m_impl = NULL;
}

string ConfigReader::getAddress()
{
	return m_impl->getAddress();
}

unsigned short ConfigReader::getPort()
{
	return m_impl->getPort();
}

bool ConfigReader::init()
{
	return m_impl->init();
}
