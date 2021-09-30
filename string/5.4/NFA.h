#pragma once

#include "Digraph.h"
#include "string"
#include "memory"

using namespace std;
class NFA
{
private:
	string RE;		//������ʽ
	int M;			//ģʽ����
	unique_ptr<Digraph> graph;	//�����Զ����õ�ͼ
public:
	NFA(string RE);
	bool recognize(string txt);
};