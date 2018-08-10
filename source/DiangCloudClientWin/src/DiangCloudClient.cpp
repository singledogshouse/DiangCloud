
#include <WinSock2.h>
#include <stdio.h>
#include "DiangCloudBase.h"

#pragma comment (lib, "ws2_32.lib")

#define _WINSOCK_DEPRECATED_NO_WARNINGS 1

using namespace DC_BASE;

namespace
{
	bool WSA_INIT_SUCCESSED = false;

	void WSA_INIT()
	{
		WSADATA wsadata;
		if (0 != WSAStartup(MAKEWORD(2, 2), &wsadata))
		{
			ASSERT("WSAStartup failed!");
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
				ASSERT("WSAStartup failed!");
			}
		}
	}
}

#define CLIENT

int main(int args, char **argv)
{
	WSA_INIT();

#ifdef CLIENT
	SOCKET clientSock;
	if (INVALID_SOCKET == (clientSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)))
	{
		ASSERT("socket failed!");
		return 0;
	}

	sockaddr_in servAddr;
	servAddr.sin_addr.s_addr = inet_addr(DEFAULT_ADDRESS);
	servAddr.sin_port = htons(DEFAULT_SERVER_PORT);
	servAddr.sin_family = AF_INET;

	if (0 != connect(clientSock, (const sockaddr *)(&servAddr), sizeof(servAddr)))
	{
		ASSERT("connect failed!");
		return 0;
	}

	char buff[1024] = "hello diang";
	send(clientSock, buff, sizeof(buff), 0);

	closesocket(clientSock);
#endif // CLIENT

	WSA_UNINIT();
	return 0;
}