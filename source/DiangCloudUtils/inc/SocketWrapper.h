
#ifndef _SOCKET_WRAPPER_H_H_
#define _SOCKET_WRAPPER_H_H_

class DcSocket
{
private:
	DcSocket();
	~DcSocket();
	DcSocket(const DcSocket &) {}
	DcSocket& operator=(const DcSocket &) {}

public:
	static DcSocket* createSocket();

private:
	static DcSocket *m_dcSocket;
};

#endif //_SOCKET_WRAPPER_H_H_