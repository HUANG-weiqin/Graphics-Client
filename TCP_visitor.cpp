#include "TCP_visitor.h"
#include "Client.h"
#include "CmdForServer.h"
void TCP_visitor::visit(GeomCircle* geom) {
	sendTcpReqest(CMD_CIRCLE, geom); 
}

void TCP_visitor::visit(GeomCompos* geom) {
	geom->accept(this);
}

void TCP_visitor::visit(GeomPolygone* geom) {
	sendTcpReqest(CMD_POLYGONE, geom);
}
void TCP_visitor::visit(GeomLine* geom) {
	sendTcpReqest(CMD_LINE, geom);
}
void TCP_visitor::sendTcpReqest(const char* cmd, GeomSimple* geom) {
	stringstream ss;
	ss<< cmd <<" "<<geom->toString();
	string request = ss.str();
	Client::GetInstance()->Send(request);
}