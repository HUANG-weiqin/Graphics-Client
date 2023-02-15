#pragma once
#include "Geometric.h"
#include <vector>

using namespace std;
class Visitor;
class GeomCompos : public Geometric
{
/* ���ͼ�� �� ��ͼ����ԣ������ɶ����ͼ�λ��� ���ͼ����ϳɵ�ͼ�μ��ϣ��Ͱ�������һ�����Ͼͺ���
* �� move rotate ��zoom ��Ӧ���������ϵ�ʱ����ʵ����Ӧ�������������ڲ���ͼ���ϣ������������ͼ�����֮��
*/
public:
	virtual ~GeomCompos();
	virtual void accept(Visitor* v);
	virtual void add(Geometric* g);
	virtual void moveBy(Vector2d& v);
	virtual void rotateBy(Point* pivot, float radian);
	virtual void zoomBy(Point* pivot, float factor);
	virtual float surface();
	virtual string toString();
private:
	vector<Geometric * > geoms;
};
