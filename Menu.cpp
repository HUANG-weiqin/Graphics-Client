#include "Menu.h"
#include "GeomCircle.h"
#include "GeomPolygone.h"
#include "GeomLine.h"
Menu::Menu(GeomCompos* g, Visitor* v) {
	G = g;
	V = v;
}

void Menu::run(){
	while (true)
	{
		cout << "############# " << endl;
		cout << "请选择 " << endl;
		cout << "1 绘制圆形 " << endl;
		cout << "2 绘制多边形 " << endl;
		cout << "3 绘制线段 " << endl;
		cout << "4 平移 " << endl;
		cout << "5 旋转" << endl;
		cout << "6 缩放 " << endl;
		cout << "0 退出 " << endl;
		cout << "############# " << endl;
		int choice;
		cin >> choice;
			switch (choice)
			{
			case 1:
				createCircle();
				break;
			case 2:
				createPolygone();
				break;
			case 3:
				createLine();
				break;
			case 4:
				move();
				break;
			case 5:
				rotate();
				break;
			case 6:
				zoom();
				break;
			default:
				return;
			}
	}
}
void Menu::createCircle() {
	int x, y, r;
	cout << "输入圆心坐标 x y" << endl;
	cin >> x >> y;
	cout << "半径" << endl;
	cin >> r;
	GeomCircle* c = new GeomCircle(x,y,r);
	G->add(c);
	updat();
	
}
void Menu::createPolygone() {
	vector<int> points;
	int nb;
	cout << "输入多边形顶点数量" << endl;
	cin >> nb;
	for (int i = 0; i < nb; ++i) {
		int x, y;
		cout << "输入顶点坐标 x y" << endl;
		cin >> x >> y;
		points.push_back(x);
		points.push_back(y);
	}
	GeomPolygone *p = new GeomPolygone(points);
	G->add(p);
	updat();
}
void Menu::createLine() {
	int x, y,x1,y1;
	cout << "输入顶点1坐标 x y" << endl;
	cin >> x >> y;
	cout << "输入顶点2坐标 x y" << endl;
	cin >> x1 >> y1;
	GeomLine* l = new GeomLine(x, y, x1, y1);
	G->add(l);
	updat();
 }

void Menu::move() {
	int x, y;
	cout << "输入平移向量的 x y" << endl;
	cin >> x >> y;
	Vector2d v(x, y);
	G->moveBy(v);
	updat();
}

void Menu::zoom() {
	float z;
	int x, y;
	cout << "输入缩放中心 x y" << endl;
	cin >> x >> y;
	cout << "输入缩放倍数 z " << endl;
	cin >> z;
	Point p(x, y);
	G->zoomBy(&p, z);
	updat();
}

void Menu::rotate() {
	float rd;
	int x, y;
	cout << "输入旋转中心 x y" << endl;
	cin >> x >> y;
	cout << "输入旋转弧度 r " << endl;
	cin >> rd;
	Point p(x, y);
	G->rotateBy(&p,rd);
	updat();
}

void Menu::updat() {
	V->visit(Menu::G);
}