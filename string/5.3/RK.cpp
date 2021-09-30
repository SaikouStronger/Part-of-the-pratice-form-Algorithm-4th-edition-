#include "RK.h"

long RK::hash(string key, int M)
{
	long h = 0;
	for (int j = 0; j < M; j++)
		h = (R * h + key[j]) % Q;
	return h;
}

RK::RK(string pat)
{
	this->pat = pat;
	M = pat.length();
	Q = 9999991;
	RM = 1;

	for (int i = 1; i <= M - 1; i++)
		RM = (R * RM) % Q;		//���ڼ�ȥ��һ�����ֵĽ��
	patHash = hash(pat, M);
}

bool RK::check(int i)
{
	return true;
}

int RK::search(string txt)
{
	int N = txt.length();
	long txtHash = hash(txt, M);
	if (patHash == txtHash && check(0))
		return 0;	//��ʼ��ƥ��ɹ�
	for (int i = M; i < N; i++)
	{
		//��ȥ��һ�����֣��ټ������һ������
		txtHash = (txtHash + Q - RM * txt[i - M] % Q) % Q;	//����Q��Ϊ�˱�����������Ӱ��
		txtHash = (txtHash * R + txt[i]) % Q;
		if (patHash == txtHash)
			if (check(i - M + 1))
				return i - M + 1;
	}
	return N;
}