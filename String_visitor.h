#pragma once
#include "Visitor.h"
#include <string>

class String_visitor : public Visitor
{
	/* visitor ģʽ ���࣬visitorģʽ���� �� ͼ������(��״����С�����㣬�߳���)
	�� ���ַ�ʽ(tcp ���� �� ͼ��api���ƣ���) ���������������Ҫ�������ַ�ʽ��ʱ���ö��κε�ͼ���йش��룬
	ֻ��Ҫ���Ķ�Ӧ��visitor���ɣ�Ŀǰֻ��tcp visitor��TCP_visitor
	*/
public:
	virtual void visit(GeomCircle* geom);
	virtual void visit(GeomCompos* geom);
	virtual void visit(GeomPolygone* geom);
	virtual void visit(GeomLine* geom);
	string getString();
private:
	string result;

};