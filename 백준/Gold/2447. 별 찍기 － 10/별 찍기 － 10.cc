#include <bits/stdc++.h>
using namespace std;
char results[6600][6600];

void draw_blank(int x, int y, int n)
{
	for(int bi = x; bi < x + n; bi++)
	{
		for(int bj = y; bj < y + n; bj++)
		{
			results[bi][bj] = ' ';	
		}
	}
}

void draw(int x, int y, int n)
{
	if (n == 3)
	{
		for (int i = x; i < x+3; i++)
		{
			for (int j = y; j < y+3; j++)
			{
				results[i][j] = '*';
			}
		}
		
		results[x+1][y+1] = ' ';
		return;
	}
	
	int N = n / 3;
	for (int i = 0; i < 3; i++)
	{
		int newX = x + i * N;
		for (int j = 0; j < 3; j++)
		{
			int newY = y + j * N;
			if (N + x <= newX && newX < 2 * N + x && N + y <= newY && newY < 2 * N + y)
			{
				draw_blank(newX, newY, N);
			}
			else
			{
				draw(newX, newY, N);
			}
		}
	}
}

int main() {
	int n;
	cin >> n;
	
	draw(0, 0, n);
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << results[i][j];
		}
		cout << '\n';
	}
	return 0;
}