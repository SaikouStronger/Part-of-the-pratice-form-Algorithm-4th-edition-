#pragma once

#include "memory"
#include "string"
using namespace std;

#define R 256
class BM
{
private:
	unique_ptr<int> right;	//�ƶ�����
	string pat;				//ģʽ
public:
	BM(string _pat);
	int search(string txt);
};