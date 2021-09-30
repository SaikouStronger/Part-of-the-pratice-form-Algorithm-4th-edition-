#include "BM.h"

BM::BM(string pat)
{
	this->pat = pat;
	int M = pat.length();
	right.reset(new int[R + 1]);

	for (int c = 0; c <= R; c++)
		right.get()[c] = -1;		//ģʽû�е���Ϊ-1
	for (int j = 0; j < M; j++)
		right.get()[pat[j]] = j;	//ģʽ�еģ���Ϊ���ҵ�λ��
}

int BM::search(string txt)
{
	int N = txt.length();
	int M = pat.length();
	
	int skip;	//�ƶ�����
	for (int i = 0; i <= N - M; i += skip)
	{
		skip = 0;
		for (int j = M - 1; j >= 0; j--)
		{
			if (pat[j] != txt[i + j])
			{
				skip = j - right.get()[txt[i + j]];
				if (skip < 1)
					skip = 1;	//������ǰ�ƶ�һλ
				break;
			}
		}
		if (skip == 0)
			return i;	//�ҵ�
	}
	return N;	//δ�ҵ�
}