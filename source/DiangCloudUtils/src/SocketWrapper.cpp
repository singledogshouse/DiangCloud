
#include "SocketWrapper.h"
#include "DiangCloudBase.h"

#include <WinSock2.h>

#pragma comment (lib, "ws2_32.lib")

using namespace DC_BASE;

namespace
{
	bool WSA_INIT_SUCCESSED = false;

	void WSA_INIT()
	{
		WSADATA wsadata;
		if (0 != WSAStartup(MAKEWORD(2, 2), &wsadata))
		{
			WSAGetLastError();
			DCERROR("WSAStartup failed: " + to_string(WSAGetLastError()));
			return;
		}
		WSA_INIT_SUCCESSED = true;
	}

	void WSA_UNINIT()
	{
		if (WSA_INIT_SUCCESSED)
		{
			if (0 != WSACleanup())
			{
				DCERROR("WSACleanup failed:" + to_string(WSAGetLastError()));
			}
		}
	}
}

DcSocket * DcSocket::m_dcSocket = NULL;

DcSocket::DcSocket()
{
	WSA_INIT();
}

DcSocket::~DcSocket()
{
	WSA_UNINIT();
}

DcSocket* DcSocket::createSocket()
{
	if (!m_dcSocket)
	{
		m_dcSocket = new DcSocket;
	}
	return m_dcSocket;
}

