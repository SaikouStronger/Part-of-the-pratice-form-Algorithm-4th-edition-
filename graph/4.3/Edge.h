#pragma once

#include <iostream>
#include <string>
#include <atlstr.h>
using namespace std;

class Edge
{
private:
	double weight;
	int v;
	int w;
public:
	Edge(int v, int w, double weight);

	Edge();
	double Getweight();
	

	int either();	//����һ������
	

	int other(int vertex);//������һ������
	

	int compareTo(Edge that);//����һ���߱Ƚ�Ȩֵ
	
	
	string toString();		//�ַ������
	
};