#include <bits/stdc++.h>
using namespace std;
string video[65];
string result = "";

bool check(int x, int y, int n)
{
	for (int i = x; i < x + n; i++)
	{
		for (int j = y; j < y + n; j++)
		{
			if (video[x][y] != video[i][j])
			{
				return false;
			}
		}
	}
	
	return true;
}

void tree(int x, int y, int n)
{
	if (check(x, y, n))
	{
		cout << video[x][y];
		return;
	}
	
	cout << "(";	
	int N = n / 2;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			tree(x + i * N, y + j * N, N);
		}
	}
	
	cout << ")";
}

int main() {
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		video[i].reserve(65);
		for (int j = 0; j < n; j++)
		{
			cin >> video[i][j];
		}
	}
	
	tree(0, 0, n);
	cout << result;
	
	return 0;
}