#include <iostream>
#define MAX 500
#define X first
#define Y second
using namespace std;

int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };
float sand[] = { 0.05, 0.1, 0.1, 0.02, 0.07, 0.07, 0.02, 0.01, 0.01 };
int sx[4][9] = {
	{ 0, 1, -1, 2, 1, -1, -2, 1, -1 },
	{ 2, 1, 1, 0, 0, 0, 0, -1, -1 },
	{ 0, -1, 1, -2, -1, 1, 2, -1, 1 },
	{ -2, -1, -1, 0, 0, 0, 0, 1, 1 }
};
int sy[4][9] = {
	{ -2, -1, -1, 0, 0, 0, 0, 1, 1 },
	{ 0, -1, 1, -2, -1, 1, 2, -1, 1 },
	{ 2, 1, 1, 0, 0, 0, 0, -1, -1 },
	{ 0, 1, -1, 2, 1, -1, -2, 1, -1}
};

int n, answer;
int board[MAX][MAX];

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
}

void solution() {
	int dir = 0;
	int length = 1;
	int moveCnt = 0;
	int x = n / 2, y = n / 2;
	while (true) {
		moveCnt++;
		for (int i = 0; i < length; i++) {
			x += dx[dir];
			y += dy[dir];

			if (x == 0 && y == -1) return;

			int base = board[x][y];
			for (int j = 0; j < 9; j++) {
				int nx = x + sx[dir][j];
				int ny = y + sy[dir][j];
				int s = board[x][y] * sand[j];
				base -= s;

				if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
					answer += s;
				}
				else {
					board[nx][ny] += s;
				}
			}

			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
				answer += base;
			}
			else {
				board[nx][ny] += base;
			}
			board[x][y] = 0;
		}

		if (moveCnt == 2) {
			length++;
			moveCnt = 0;
		}
		dir = (dir + 1) % 4;
	}
}

void solve() {
	input();
	solution();
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	solve();
	cout << answer << '\n';
}