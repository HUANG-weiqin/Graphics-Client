#include <winsock2.h>
#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include "Erreur.h"
#include "Client.h"
#include "TCP_visitor.h"
#include <vector>
#include "CmdForServer.h"
#include <fstream>
#include <iostream>
#include "String_visitor.h"
using namespace std;

void save(GeomCompos *G, const char * name) {
	ofstream outfile;
	outfile.open(name);
	String_visitor st;
	st.visit(G);
	outfile << st.getString();
	outfile.close();
}

void load(GeomCompos* G, const char* name) {
	ifstream infile;
	infile.open(name);
	string line;
	
	while (getline(infile, line))
	{
		stringstream ss;
		ss << line;
		int type;
		ss >> type;
		vector<float> p;
		float x, y, x1, y1, r;
		int cr, cg, cb;
		GeomCircle* res1;
		GeomPolygone* res2;
		GeomLine* res3;
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
				float var;
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
	infile.close();
}

int main()
{
	try
	{
		GeomCompos g;


		GeomCircle* c = new GeomCircle(0, 0, 5); //创建中点 200 200 半径 100的圆形
		c->setColor(0, 15, 20); //设置rgb值
		g.add(c); //放入总图形中

		GeomLine* line = new GeomLine(0,0,4,4); //创建端点 0 0 到端点 400 400的线段
		line->setColor(200, 125, 200); //设置rgb值
		g.add(line); //放入总图形中

		vector<float> points = { 5,5, 7,2.5, 10,5, 10,10 ,5,-1 };// 多边形的顶点集合 x1 y1 x2 y2 .....
		GeomPolygone *pl = new GeomPolygone(points); //以该集合创建多边形
		pl->setColor(0, 0, 200); //设置rgb值
		g.add(pl); //放入总图形中
		
		Vector2d move = Vector2d(2.5, 5.0); //平移向量
		g.moveBy(move); //将所有的图形向move向量平移

		Point pivot = Point(0, 0);//中心
		g.rotateBy(&pivot,0.03);//以pivot为中心旋转1弧度，注意是弧度不是角度

		g.zoomBy(&pivot,0.5);//以pivot为中心，将图形变成原本的0.5倍大小

		cout << "surface is:" << g.surface() << endl;

		save(&g, "saved_data.txt");//保存所有图形到文件中

		//load(&g, "saved_data.txt");//将保存的图形读取到g中
		

		//visitor
		TCP_visitor tcpv;
		g.accept(&tcpv);
		Client::GetInstance()->DisConnect();
	}
	catch (Erreur erreur)
	{
		cerr << erreur << endl;
	}



	return 0;

}