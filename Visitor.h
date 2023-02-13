#pragma once
#include "GeomCompos.h"
#include "GeomCircle.h"
#include "GeomPolygone.h"
#include "GeomLine.h"
class Visitor
{
/* visitor 模式 父类，visitor模式用来 将 图形内容(形状，大小，顶点，边长等) 
与 表现方式(tcp 发送 或 图形api绘制，等) 解耦，这样当我们需要更换表现方式的时候不用动任何的图形有关代码，
只需要更改对应的visitor即可，目前只有tcp visitor即TCP_visitor
*/
public:	
	virtual void visit(GeomCircle * geom) = 0;
	virtual void visit(GeomCompos * geom) = 0;
	virtual void visit(GeomPolygone * geom) = 0;
	virtual void visit(GeomLine* geom) = 0;

};
