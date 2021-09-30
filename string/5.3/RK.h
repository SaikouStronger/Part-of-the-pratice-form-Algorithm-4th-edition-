#pragma once
#include "string"
using namespace std;

class RK
{
private:
	string pat;
	long patHash;	//ģʽ��ɢ��ֵ
	int M;			//ģʽ����
	long Q;			//�ܴ������
	const static int R = 256;	//����
	long RM;		// R^M-1 % Q

	long hash(string key, int M);
public:
	RK(string pat);
	bool check(int i);
	int search(string txt);
};