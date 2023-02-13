#include <winsock2.h>
#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include "Erreur.h"
#include "Client.h"
#include "CmdForServer.h"

#pragma comment(lib, "ws2_32.lib") // sp¨¦cifique ¨¤ VISUAL C++

Client*  Client::instance = NULL;

Client * Client::GetInstance() {
	if (!Client::instance)Client::instance = new Client();
	return Client::instance;
}

Client::Client() {
	int r;
	WSADATA wsaData;        // structure contenant les donn¨¦es de la librairie winsock ¨¤ initialiser

	r = WSAStartup(MAKEWORD(2, 0), &wsaData);       // MAKEWORD(2,0) sert ¨¤ indiquer la version de la librairie ¨¤ utiliser : 1 pour winsock et 2 pour winsock2

	/* en cas de succ¨¨s, wsaData a ¨¦t¨¦ initialis¨¦e et l'appel a renvoy¨¦ la valeur 0 */

	if (r) throw Erreur("L'initialisation a ¨¦chou¨¦");

	cout << "client vers le serveur de majuscule" << endl;
	cout << "initialisation effectu¨¦e" << endl;

	//---------------------- cr¨¦ation socket -------------------------------------------------

	int familleAdresses = AF_INET;         // IPv4
	int typeSocket = SOCK_STREAM;           // mode connect¨¦ TCP
	int protocole = IPPROTO_TCP;            // protocole. On peut aussi mettre 0 et la fct choisit le protocole en fct des 2 1ers param¨¨tres
											// pour les valeurs des param¨¨tres : cf. fct socket dans la doc sur winsock

	this->sock = socket(familleAdresses, typeSocket, protocole);

	if (this->sock == INVALID_SOCKET)
	{
		ostringstream oss;
		oss << "la cr¨¦ation du socket a ¨¦chou¨¦ : code d'erreur = " << WSAGetLastError() << endl;	// pour les valeurs renvoy¨¦es par WSAGetLastError() : cf. doc r¨¦f winsock
		throw Erreur(oss.str().c_str());
	}

	cout << "socket cr¨¦¨¦" << endl;

	char addr[] = ADDRESS;
	short port = PORT;
	this->Connect(addr, port);
}

Client::~Client() {
	int r = shutdown(this->sock, SD_BOTH);							// on coupe la connexion pour l'envoi et la r¨¦ception

	DisConnect();
		// renvoie une valeur non nulle en cas d'¨¦chec. Le code d'erreur peut ¨ºtre obtenu par un appel ¨¤ WSAGetLastError()

	if (r == SOCKET_ERROR)
		throw Erreur("la coupure de connexion a ¨¦chou¨¦");


	r = closesocket(this->sock);                          // renvoie une valeur non nulle en cas d'¨¦chec. Le code d'erreur peut ¨ºtre obtenu par un appel ¨¤ WSAGetLastError()
	if (r) throw Erreur("La fermeture du socket a ¨¦chou¨¦");

	WSACleanup();
	cout << "arr¨ºt normal du client" << endl;
}

void Client::Send(char * requete) {
	int r;
	int len = strlen(requete);
	
	r = send(this->sock, requete, len, 0);
	char end[] = MSGEND;
	r = send(this->sock, end, 1, 0);
	if (r == SOCKET_ERROR)
		throw Erreur("¨¦chec de l'envoi de la requ¨ºte");
}

void Client::Send(string & requete) {
	int r;
	r = send(this->sock, requete.c_str(), requete.length(), 0);
	char end[] = MSGEND;
	r = send(this->sock, end, 1, 0);
	if (r == SOCKET_ERROR)
		throw Erreur("¨¦chec de l'envoi de la requ¨ºte");
}

void Client::Connect(const char adresseServeur[], short portServeur) {
	int r;
	SOCKADDR_IN sockaddr; // informations concernant le serveur avec lequel on va communiquer

	sockaddr.sin_family = AF_INET;
	sockaddr.sin_addr.s_addr = inet_addr(adresseServeur);   // inet_addr() convertit de l'ASCII en entier
	sockaddr.sin_port = htons(portServeur);                 //htons() assure que le port est bien inscrit dans le format du r¨¦seau (little-endian ou big-endian)

	//-------------- connexion du client au serveur ---------------------------------------

	r = connect(this->sock, (SOCKADDR*)&sockaddr, sizeof(sockaddr));     // renvoie une valeur non nulle en cas d'¨¦chec.
																	// Le code d'erreur peut ¨ºtre obtenu par un appel ¨¤ WSAGetLastError()

	if (r == SOCKET_ERROR)
		throw Erreur("La connexion a ¨¦chou¨¦");
	this->connected = true;
}

void Client::DisConnect() {
	if (this->connected) {
		char reques[] = CMD_QUIT;
		this->Send(reques);
		this->connected = false;
	}
}

void Client::SaveGraphics() 
{
	char save[] = CMD_SAVE;
	Send(save);
}
void Client::LoadGraphics() 
{
	char load[] = CMD_LOAD;
	Send(load);
}