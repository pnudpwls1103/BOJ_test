#include <iostream>
#include <cstring>
#include <vector>
#define X first
#define Y second
using namespace std;

int n, m, answer;
int board[50][50];
int n_board[50][50];
int except[2500];
pair<int, int> coord[2500];
vector<pair<int, int>> blizzard;
int scores[] = { 0, 0, 0 };

int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };

void debug() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << board[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

int changeDir(int dir) {
	int result = dir;
	switch (dir) {
	case 0:
		result = 3;
		break;
	case 1:
		result = 1;
		break;
	case 2:
		result = 0;
		break;
	case 3:
		result = 2;
		break;
	}

	return result;
}

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	int d, s;
	for (int i = 0; i < m; i++) {
		cin >> d >> s;
		d = changeDir(d - 1);
		blizzard.push_back({ d, s });
	}
}

void remap() {
	int x = n / 2;
	int y = n / 2;

	int num = 0;
	int dir = 0;
	int length = 1;
	int moveCnt = 0;
	n_board[x][y] = num;
	while (true) {
		moveCnt++;

		for (int i = 0; i < length; i++) {
			x += dx[dir];
			y += dy[dir];

			if (x == 0 && y == -1) {
				return;
			}

			num++;
			n_board[x][y] = num;
			coord[num] = { x, y };
		}

		if (moveCnt == 2) {
			length++;
			moveCnt = 0;
		}
		dir = (dir + 1) % 4;
	}
}

void doBlizzard(int d, int s) {
	memset(except, 0, sizeof(except));

	int x = n / 2;
	int y = n / 2;

	for (int i = 0; i < s; i++) {
		x += dx[d];
		y += dy[d];

		if (x < 0 || x >= n || y < 0 || y >= n) continue;
		except[n_board[x][y]] = 1;
	}
}

void moveBall() {
	bool flag = false;
	int cnt = 0;
	for (int i = 1; i < n * n; i++) {
		if (except[i]) {
			flag = true;
			cnt++;
		}
		else {
			if (board[coord[i].X][coord[i].Y] == 0) {
				for (int j = 1; j <= cnt; j++) {
					board[coord[i - j].X][coord[i - j].Y] = 0;
				}
				flag = false;
				break;
			}
			else {
				board[coord[i - cnt].X][coord[i - cnt].Y] = board[coord[i].X][coord[i].Y];
			}
		}
	}

	if (flag) {
		int i = n * n - 1;
		for (int j = 0; j < cnt; j++, i--) {
			board[coord[i].X][coord[i].Y] = 0;
		}
	}
}

bool exploreBall() {
	memset(except, 0, sizeof(except));

	int flag = false;
	int color = board[coord[1].X][coord[1].Y];
	int cnt = 1;
	int start = 1;
	for (int i = 2; i < n * n; i++) {
		int next = board[coord[i].X][coord[i].Y];
		if (color == 0) break;

		if (color == next) {
			cnt++;
		}
		else {
			if (cnt >= 4) {
				flag = true;
				for (int j = start; j < i; j++) {
					except[j] = 1;
				}
				scores[color - 1] += cnt;
			}
			cnt = 1;
			start = i;
			color = next;
		}
	}

	return flag;
}

void changeBoard() {
	int temp[50][50] = { 0, };
	int color = board[coord[1].X][coord[1].Y];
	int cnt = 1;
	int tempPos = 1;
	for (int i = 2; i < n * n; i++) {
		int next = board[coord[i].X][coord[i].Y];
		if (color == 0) break;
		if (tempPos >= n * n) break;
		if (color == next) {
			cnt++;
		}
		else {
			temp[coord[tempPos].X][coord[tempPos].Y] = cnt;
			temp[coord[tempPos + 1].X][coord[tempPos + 1].Y] = color;

			cnt = 1;
			color = next;
			tempPos += 2;
		}
	}

	for (int i = 0; i < n; i++) {
		copy(temp[i], temp[i] + 50, board[i]);
	}
}

void calScore() {
	for (int i = 0; i < 3; i++) {
		answer += (i + 1) * scores[i];
	}
}

void solution() {
	remap();
	for (int i = 0; i < m; i++) {
		pair<int, int> curBliz = blizzard[i];
		doBlizzard(curBliz.first, curBliz.second);
		moveBall();
		while (exploreBall()) {
			moveBall();
		}
		changeBoard();
	}

	calScore();
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