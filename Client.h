#pragma once
#ifndef CLIENT
#define CLIENT
#include <winsock2.h>
#include <string>
using namespace std;

class Client
{
/* 客户端与服务端沟通的窗口，打开一个tcp链接，链接上服务器
* 是单例模式，无法直接new出来，只能通过GetInstance来获取全局单例，避免单机产生多个链接
*/
private:
	WSADATA wsaData;
	SOCKET sock;
	Client();
	~Client();
	bool connected = false;
	static Client* instance;
	void Connect(const char adresseServeur[], const short portServeur);

public:
	void Send(char * msg);
	void Send(string & msg);
	void DisConnect();
	static Client* GetInstance();

	/* 向服务端发送保存和读取图形的指令，图形就会在服务端被保存
	*/
	void SaveGraphics();
	void LoadGraphics();
};

#endif
