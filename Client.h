#pragma once
#ifndef CLIENT
#define CLIENT
#include <winsock2.h>
#include <string>
using namespace std;

class Client
{
/* �ͻ��������˹�ͨ�Ĵ��ڣ���һ��tcp���ӣ������Ϸ�����
* �ǵ���ģʽ���޷�ֱ��new������ֻ��ͨ��GetInstance����ȡȫ�ֵ��������ⵥ�������������
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

	/* �����˷��ͱ���Ͷ�ȡͼ�ε�ָ�ͼ�ξͻ��ڷ���˱�����
	*/
	void SaveGraphics();
	void LoadGraphics();
};

#endif
