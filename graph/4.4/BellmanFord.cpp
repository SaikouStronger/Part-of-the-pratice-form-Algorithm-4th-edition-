
#include <vector>
#include <queue>
#include "DirectedEdge.h"
#include "EdgeWeightedDigraph.h"
using namespace std;
class BellmanFord
{
private:
	vector<double> distTo;			//����㵽ĳ�������·������
	vector<DirectedEdge> edgeTo;	//����㵽ĳ����������һ����
	vector<bool> onQ;				//�ö����Ƿ�����ڶ�����
	queue<int> Queue;				//���ڱ����ɵĶ���
	int cost;						//relax�����õĴ���
	vector<DirectedEdge> cycle;		//edgeTo���Ƿ��и�Ȩ�ػ�

	void relax(EdgeWeightedDigraph G, int v);
	void findNegtiveCycle();
public:
	BellmanFord(EdgeWeightedDigraph G, int s);
	bool hasNegativeCycle();
	vector<DirectedEdge> negativeCycle();

};


BellmanFord::BellmanFord(EdgeWeightedDigraph G, int s)
{
	distTo.resize(G.GetV());
	edgeTo.resize(G.GetV());
	onQ.resize(G.GetV());
	for (int v = 0; v < G.GetV(); v++)
	{
		distTo[v] = DBL_MAX;
	}
	distTo[0] = 0.0;
	Queue.push(s);
	onQ[0] = true;
	edgeTo[s] = null;
	while (!Queue.empty() && !hasNegativeCycle())
	{
		int v = Queue.front();
		Queue.pop();
		onQ[v] = false;
		relax(G, v);
	}
}

void BellmanFord::relax(EdgeWeightedDigraph G, int v)
{
	for (DirectedEdge e : G.Getadj(v))
	{
		int w = e.to();
		if (distTo[w] > distTo[v] + e.Getweight())
		{
			distTo[w] = distTo[v] + e.Getweight();
			edgeTo[w] = e;
			if (!onQ[w])
			{
				Queue.push(w);
				onQ[w] = true;
			}
		}
	}
	if (cost++ % G.GetV() == 0)
		findNegtiveCycle();
}


void BellmanFord::findNegtiveCycle()
{
	int V = edgeTo.size();
	EdgeWeightedDigraph spt(V);
	for (int v = 0; v < V; v++)
	{
		if (edgeTo[v] != null)
		{
			spt.addEdge(edgeTo[v]);
		}
		EdgeWeightedCycleFinder cf(spt);
		cycle = cf.cycle();
	}
}

bool BellmanFord::hasNegativeCycle()
{
	return (cycle.size() != 0);
}
vector<DirectedEdge> BellmanFord::negativeCycle()
{
	return cycle;
}
