#pragma once

#include "DirectedEdge.h"
#include <vector>
#include <iostream>
using namespace std;


class EdgeWeightedDigraph
{
private:
	int V;	//��������
	int E;	//�ߵ�����
	vector<vector<DirectedEdge>> adj;
public:
	EdgeWeightedDigraph(int V);

	EdgeWeightedDigraph(istream& in);	//����������ͼ
	void addEdge(DirectedEdge e);
	int GetV();
	int GetE();
	vector<DirectedEdge> edges();
	vector<DirectedEdge> Getadj(int v);
};