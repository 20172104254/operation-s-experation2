// operation's    experation2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"iostream"
using namespace std;
class CFeet
{
private:
	int feet;
	int inches;
public:
	void setvalue(int f, int i);
	void display();
	CFeet operator-(CFeet &a);
};
void CFeet::setvalue(int f, int i)
{
	feet = f + i / 12;
	inches = i % 12;
}
void CFeet::display()
{
	cout << feet << "英尺" << inches << "英寸" << endl;
}
CFeet CFeet::operator-(CFeet&a)
{
	CFeet temp;
	if (feet>0&&inches>a.inches)
	{
		temp.setvalue((feet * 12 + inches - a.feet * 12 - a.inches) / 12, (feet * 12 + inches - a.feet * 12 - a.inches) % 12);
	}
	if (feet<0&&feet<a.feet)
	{
		temp.setvalue((feet * 12 - inches - a.feet * 12 - a.inches)/12,-(feet * 12 - inches - a.feet * 12 - a.inches) %12);
	}
	if (feet<0 && feet>a.feet)
	{
		temp.setvalue((feet * 12 - inches - a.feet * 12 - a.inches) / 12, (feet * 12 - inches - a.feet * 12 - a.inches) % 12);
	}
	if (feet > 0 && feet < a.feet)
	{
		temp.setvalue((feet * 12 + inches - a.feet * 12 - a.inches) / 12, -(feet * 12 + inches - a.feet * 12 - a.inches) % 12);
	}
	if (feet > 0 && feet > a.feet)
	{
		temp.setvalue(feet-a.feet, inches-a.inches);
	}
	if (feet > 0 && inches < a.inches)
	{
		temp.setvalue((feet * 12 + inches - a.feet * 12 - a.inches) / 12, -(feet * 12 + inches - a.feet * 12 - a.inches) % 12);
	}
	return temp;
}

int main()
{
	CFeet A, B, C;
	A.setvalue(1,3);
	B.setvalue(-2,5);
	C = B - A;
	C.display();
	return 0;
}
