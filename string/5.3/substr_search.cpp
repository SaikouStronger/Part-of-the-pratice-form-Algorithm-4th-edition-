#include "substr_search.h"

int normal_subsearch(string pat, string txt)
{
	int m = pat.length();
	int n = txt.length();

	for (int i = 0; i <= n - m; i++)
	{
		int j = 0;
		for (; j < m; j++)
		{
			if (pat[j] != txt[i + j])
				break;
		}
		if (j == m)
			return i;
	}
	return n;			// û�ҵ������ı�����
}


KMP::KMP(string _pat)
{
	pat = _pat;
	int R = 256;
	int M = _pat.length();
	dfa.resize(R);
	for (vector<int>& a : dfa)
		a.resize(M);
	dfa[_pat[0]][0] = 1;
	int X = 0;
	for (int j = 1; j < M; j++)
	{
		for (int c = 0; c < R; c++)
			dfa[c][j] = dfa[c][X];
		dfa[_pat[j]][j] = j + 1;
		X = dfa[_pat[j]][X];	//����Xʼ���Ƕ�Ӧj��Χ�ڵ��ǰ�󹫹����ַ�������
								//���j������һ�����ַ���������ǰ�󹫹����ַ�������+1

	}
}
int KMP::search(string txt)
{
	int N = txt.length();
	int M = pat.length();
	int i = 0, j = 0;
	for (; i < N && j < M; i++)
	{
		j = dfa[txt[i]][j];
	}
	if (j == M)
		return i - M;	//ʶ�𵽷���ģʽ���ı��п�ʼλ��
	else
		return N;
}