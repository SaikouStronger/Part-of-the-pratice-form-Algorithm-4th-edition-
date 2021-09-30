#pragma once
#include <iostream>
#include "Edge.h"
#include <vector>
using namespace std;

class EdgeWeightGraph
{
private:
	int V;	//��������
	int E;	//�ߵ�����
	vector<vector<Edge>> adj;	//�ڽӱ�
public:
	EdgeWeightGraph(int V);

	EdgeWeightGraph(istream& in);	//����������ͼ

	int GetV();
	int GetE();
	
	void addEdge(Edge e);
	
	vector<Edge> Getadj(int v);

	vector<Edge> edges();	//�������б�
	
};