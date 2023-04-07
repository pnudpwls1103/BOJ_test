#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int n, answer;
int board[500][500];
int temp[500][500];

int dir = 0;
int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };
int sx[4][9] = {
	{ 0, -1, 1, -2, -1, 1, 2, -1, 1 },
	{ 2, 1, 1, 0, 0, 0, 0, -1, -1 },
	{ 0, -1, 1, -2, -1, 1, 2, -1, 1 },
	{ -2, -1, -1, 0, 0, 0, 0, 1, 1}
};

int sy[4][9] = {
	{ -2, -1, -1, 0, 0, 0, 0, 1, 1 },
	{ 0, -1, 1, -2, -1, 1, 2, -1, 1},
	{ 2, 1, 1, 0, 0, 0, 0, -1, -1 },
	{ 0, 1, -1, 2, 1, -1, -2, 1, -1}
};

float sand[] = { 0.05, 0.1, 0.1, 0.02, 0.07, 0.07, 0.02, 0.01, 0.01 };

void debug() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << temp[i][j] << ' ';
		}
		cout << '\n';
	}
}

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
}

void solution() {
	int flag = false;
	int x = n / 2;
	int y = n / 2;
	int moveCnt = 0;
	int length = 1;

	while (true) {
		moveCnt++;
		for (int k = 0; k < length; k++) {
			x += dx[dir];
			y += dy[dir];

			int a = board[x][y];
			for (int i = 0; i < 9; i++) {
				int nx = x + sx[dir][i];
				int ny = y + sy[dir][i];
				int sandAdd = sand[i] * board[x][y];
				a -= sandAdd;

				if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
					answer += sandAdd;
				}
				else {
					board[nx][ny] += sandAdd;
				}
			}

			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
				answer += a;
			}
			else {
				board[nx][ny] += a;
			}
			board[x][y] = 0;

			if (x == 0 && y == 0) {
				flag = true;
				break;
			}
		}

		if (flag) break;

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