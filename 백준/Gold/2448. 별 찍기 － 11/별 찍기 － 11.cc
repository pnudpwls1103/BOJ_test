#include <bits/stdc++.h>
using namespace std;

const int MAX = 1024 * 3 + 2;
char board[MAX][MAX * 2 - 1];

void fill_star(int n, int x, int y)
{
	board[x][y] = '*';
	board[x+1][y-1] = '*'; board[x+1][y+1] = '*';
	for (int i = y-2; i <= y+2; i++)
	{
		board[x+2][i] = '*';
	}
}

void solve(int n, int x, int y)
{
	if (n == 3)
	{
		fill_star(n, x, y);
		return;
	}
	
	int d = n / 2;
	solve(d, x, y);
	solve(d, x+d, y-d);
	solve(d, x+d, y+d);
}

int main() {
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		fill(board[i], board[i]+(n * 2), ' ');
	}
	
	solve(n, 0, n-1);
	for(int i = 0; i < n; i++)
	{
		cout << board[i] << '\n';
	}
	
	return 0;
}