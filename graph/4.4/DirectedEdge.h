#pragma once
#include <string>
using namespace std;
class DirectedEdge
{
private:
	int v;	//���
	int w;	//�յ�
	double weight;	//Ȩ��
public:
	DirectedEdge(int v, int w, double weight);

	double Getweight();

	int from();	//��ñߵ����

	int to();	//��ñߵ��յ�
	

	string toString();		//�ַ������
};


extern DirectedEdge null;