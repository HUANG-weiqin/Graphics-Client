#pragma once
#include "Visitor.h"

class TCP_visitor : public Visitor
{
/* visitor 模式 子类，visitor模式用来 将 图形内容(形状，大小，顶点，边长等)
与 表现方式(tcp 发送 或 图形api绘制，等) 解耦，这样当我们需要更换表现方式的时候不用动任何的图形有关代码，
只需要更改对应的visitor即可，目前只有tcp visitor即TCP_visitor
*/
public:
	virtual void visit(GeomCircle* geom);
	virtual void visit(GeomCompos* geom);
	virtual void visit(GeomPolygone* geom);
	virtual void visit(GeomLine* geom);
	void sendTcpReqest(const char * cmd,GeomSimple* geom);
};
