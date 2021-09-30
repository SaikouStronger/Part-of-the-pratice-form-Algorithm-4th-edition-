#pragma once
#include <vector>
#include <queue>
#include "Minpq.h"
#include "EdgeWeightGraph.h"
using namespace std;
class KruskalMST
{
private:
	queue<Edge> mst;
public:
	KruskalMST(EdgeWeightGraph G)
	{
		Minpq<Edge> pq;
		for (Edge e : G.edges())
		{
			pq.Insert(e);
		}

		Uf uf(G.GetV());				//����Union-find�㷨
		while (!pq.isEmpty() && mst.size() < G.GetV() - 1)
		{
			Edge e = pq.Delete_Min();
			int v = e.either(), w = e.other(v);
			if (uf.connected(v, w))		//����������Ƿ񱻺ϲ�,�����������ߣ���ֹ�ɻ� 
				continue;
			uf.Union(v, w);				//�ϲ�����
			mst.push(e);
		}
	}
	queue<Edge> edges()
	{
		return mst;
	}
};
