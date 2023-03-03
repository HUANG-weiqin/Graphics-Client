#include "Menu.h"
#include "GeomCircle.h"
#include "GeomPolygone.h"
#include "GeomLine.h"
#include "Client.h"
#include "CmdForServer.h"
#include <fstream>
#include <iostream>
#include "String_visitor.h"
#include <vector>
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
		cout << "7 ���� " << endl;
		cout << "8 ��ȡ" << endl;
		cout << "9 ������� " << endl;
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
			case 7:
				save();
				break;
			case 8:
				load();
				break;
			case 9:
				surface();
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
	char cmd_clear[] = CMD_CLEAR;
	Client::GetInstance()->Send(cmd_clear); //�����Ļ�����е�ͼ��
	V->visit(G);
}

void Menu::save() {
	ofstream outfile;
	char name[255];
	cout << "���뱣���ļ���" << endl;
	cin >> name;
	outfile.open(name);
	String_visitor st;
	st.visit(G);
	outfile << st.getString();
	outfile.close();
}

void Menu::load() {
	ifstream infile;
	char name[255];
	cout << "�����ȡ�ļ���" << endl;
	cin >> name;
	infile.open(name);
	string line;
	stringstream ss;
	while (getline(infile,line))
	{
		ss << line;
		int type;
		ss >> type;
		vector<int> p;
		int x, y, x1, y1, r;
		int cr, cg, cb;
		GeomCircle* res1;
		GeomPolygone* res2;
		GeomLine * res3;
		switch (type)
		{
			case ID_CIRCLE:
				ss >> x >> y >> r >> cr >> cg >> cb;
				res1 = new GeomCircle(x, y, r);
				res1->setColor(cr, cg, cb);
				G->add(res1);
				break;
			case ID_POLYGONE:
				while (!ss.eof())
				{
					int var;
					ss >> var;
					p.push_back(var);
				}
				cb = p.back();
				p.pop_back();
				cg = p.back();
				p.pop_back();
				cr = p.back();
				p.pop_back();
				res2 = new GeomPolygone(p);
				res2->setColor(cr, cg, cb);
				G->add(res2);
				break;
			case ID_LINE:
				
				ss >> x >> y >> x1 >> y1 >> cr >> cg >> cb;
				res3 = new GeomLine(x, y, x1, y1);
				res3->setColor(cr, cg, cb);
				G->add(res3);
				break;
			default:
				break;
		}
	}
	updat();
	infile.close();
}

void Menu::surface() {
	cout << "�����Ϊ " << G->surface() << endl;
}