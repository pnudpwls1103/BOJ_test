#include <bits/stdc++.h>
using namespace std;
int paper[130][130];
int results[2] = {0, 0};

bool check(int x, int y, int n)
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

void count(int x, int y, int n)
{
	if (check(x, y, n))
	{
		results[paper[x][y]]++;
		return;
	}
	
	int N = n / 2;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			count(x + i * N, y + j * N, N);
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
	
	count(0, 0, n);
	
	for (int i = 0; i < 2; i++)
	{
		cout << results[i] << '\n';
	}
	
	return 0;
}