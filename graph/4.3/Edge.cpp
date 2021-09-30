#include "Edge.h"


Edge::Edge(int v, int w, double weight)
{
	if (v < 0 || w < 0)
		throw string("vertex index must "
			"be a non-negative integer");
	this->v = v;
	this->w = w;
	this->weight = weight;
}
Edge::Edge()
{

}
double Edge::Getweight()
{
	return weight;
}

int Edge::either()	//����һ������
{
	return v;
}

int Edge::other(int vertex)//������һ������
{
	if (vertex == v)
		return w;
	else if (vertex == w)
		return v;
	else
	{
		throw "Inconsistent edge";
	}
}

int Edge::compareTo(Edge that)//����һ���߱Ƚ�Ȩֵ
{
	if (this->Getweight() < that.Getweight())
		return -1;
	else if (this->Getweight() > that.Getweight())
		return +1;
	else
		return 0;
}

string Edge::toString()		//�ַ������
{
	char str[50];
	sprintf(str, "%d-%d %.2f", v, w, weight);
	return string(str);
}