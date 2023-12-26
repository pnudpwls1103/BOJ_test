#include <bits/stdc++.h>
using namespace std;
int paper[2200][2200];
int results[3] = {0, 0, 0};

bool checkAllEqual(int x, int y, int n)
{
	for (int i = x; i < x + n; i++)
	{
		for (int j = y; j < y + n; j++)
		{
			if (paper[x][y] != paper[i][j])
			{
				return false;
			}
		}
	}
	
	return true;
}

void count_paper(int x, int y, int n)
{
	if (checkAllEqual(x, y, n))
	{
		results[paper[x][y] + 1] += 1;
		return;
	}
	
	int N = n / 3;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			count_paper(x + i * N, y + j * N, N);
		}
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> paper[i][j];
		}
	}
	
	count_paper(0, 0, n);
	
	for (int i = 0; i < 3; i++)
	{
		cout << results[i] << '\n';
	}
	
	return 0;
}