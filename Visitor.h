#pragma once
#include "GeomCompos.h"
#include "GeomCircle.h"
#include "GeomPolygone.h"
#include "GeomLine.h"
class Visitor
{
/* visitor ģʽ ���࣬visitorģʽ���� �� ͼ������(��״����С�����㣬�߳���) 
�� ���ַ�ʽ(tcp ���� �� ͼ��api���ƣ���) ���������������Ҫ�������ַ�ʽ��ʱ���ö��κε�ͼ���йش��룬
ֻ��Ҫ���Ķ�Ӧ��visitor���ɣ�Ŀǰֻ��tcp visitor��TCP_visitor
*/
public:	
	virtual void visit(GeomCircle * geom) = 0;
	virtual void visit(GeomCompos * geom) = 0;
	virtual void visit(GeomPolygone * geom) = 0;
	virtual void visit(GeomLine* geom) = 0;

};
