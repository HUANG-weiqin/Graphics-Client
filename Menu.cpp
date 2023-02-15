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
		cout << "��ѡ�� " << endl;
		cout << "1 ����Բ�� " << endl;
		cout << "2 ���ƶ���� " << endl;
		cout << "3 �����߶� " << endl;
		cout << "4 ƽ�� " << endl;
		cout << "5 ��ת" << endl;
		cout << "6 ���� " << endl;
		cout << "0 �˳� " << endl;
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
	cout << "����Բ������ x y" << endl;
	cin >> x >> y;
	cout << "�뾶" << endl;
	cin >> r;
	GeomCircle* c = new GeomCircle(x,y,r);
	G->add(c);
	updat();
	
}
void Menu::createPolygone() {
	vector<int> points;
	int nb;
	cout << "�������ζ�������" << endl;
	cin >> nb;
	for (int i = 0; i < nb; ++i) {
		int x, y;
		cout << "���붥������ x y" << endl;
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
	cout << "���붥��1���� x y" << endl;
	cin >> x >> y;
	cout << "���붥��2���� x y" << endl;
	cin >> x1 >> y1;
	GeomLine* l = new GeomLine(x, y, x1, y1);
	G->add(l);
	updat();
 }

void Menu::move() {
	int x, y;
	cout << "����ƽ�������� x y" << endl;
	cin >> x >> y;
	Vector2d v(x, y);
	G->moveBy(v);
	updat();
}

void Menu::zoom() {
	float z;
	int x, y;
	cout << "������������ x y" << endl;
	cin >> x >> y;
	cout << "�������ű��� z " << endl;
	cin >> z;
	Point p(x, y);
	G->zoomBy(&p, z);
	updat();
}

void Menu::rotate() {
	float rd;
	int x, y;
	cout << "������ת���� x y" << endl;
	cin >> x >> y;
	cout << "������ת���� r " << endl;
	cin >> rd;
	Point p(x, y);
	G->rotateBy(&p,rd);
	updat();
}

void Menu::updat() {
	V->visit(Menu::G);
}