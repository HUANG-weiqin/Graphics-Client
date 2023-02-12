#pragma once
using namespace std;
class Visitor;
class Geometric
{
public:
	virtual ~Geometric() {};
	virtual void accept(Visitor* v) = 0;
};