#include <iostream>
#include <cstring>
#include <deque>
#include <vector>
#define X first
#define Y second
using namespace std;

struct BLOCK {
	int size;
	int rainbow;
	int x;
	int y;
	vector<pair<int, int>> blockPos;
};

int n, m, answer;
int board[25][25];
int vis[25][25];
int r_vis[25][25];

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
}

void debug() {
	cout << '\n';

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << board[i][j] << ' ';
		}
		cout << '\n';
	}
}

BLOCK BFS(int x, int y, int color) {
	memset(r_vis, 0, sizeof(r_vis));
	
	int sx = x, sy = y;
	int rainbowCnt = 0;
	vector<pair<int, int>> pos;
	pos.push_back({ x, y });
	
	deque<pair<int, int>> q;
	vis[x][y] = 1;
	q.push_back({ x, y });

	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop_front();

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (board[nx][ny] == 0 && r_vis[nx][ny] == 0) {
				rainbowCnt++;
				pos.push_back({ nx, ny });
				r_vis[nx][ny] = 1;
				q.push_back({ nx, ny });
			}
			else if (board[nx][ny] == color && vis[nx][ny] == 0) {
				if (sx > x || sx == x && sy > y) {
					sx = x, sy = y;
				}

				pos.push_back({ nx, ny });
				vis[nx][ny] = 1;
				q.push_back({ nx, ny });
			}
		}
	}

	BLOCK result;
	result.size = pos.size();
	result.rainbow = rainbowCnt;
	result.x = sx;
	result.y = sy;
	result.blockPos = pos;
	return result;
}

bool compareBlock(BLOCK b1, BLOCK b2) {
	bool result = false;
	if (b1.size > b2.size) 
		result = true;
	else if (b1.size == b2.size && b1.rainbow > b2.rainbow) 
		result = true;
	else if (b1.size == b2.size && b1.rainbow == b2.rainbow && b1.x > b2.x) 
		result = true;
	else if (b1.size == b2.size && b1.rainbow == b2.rainbow && b1.x == b2.x && b1.y > b2.y) 
		result = true;

	return result;
}

// 그룹화
BLOCK getLargestBlock() {
	memset(vis, 0, sizeof(vis));

	BLOCK result;
	result.size = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (vis[i][j] || board[i][j] <= 0) continue;
			BLOCK temp = BFS(i, j, board[i][j]);

			if (result.size == 0) result = temp;
			else if (compareBlock(temp, result)){
					result = temp;
			}
		}
	}

	return result;
}

// 블록 제거
void removing(BLOCK block) {
	vector<pair<int, int>> pos = block.blockPos;
	for (int i = 0; i < pos.size(); i++) {
		int x = pos[i].X;
		int y = pos[i].Y;
		board[x][y] = -2;
;	}

	answer += block.size * block.size;
}

void moving() {
	int bx = 0;
	for (int i = n - 2; i >= 0; i--) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] < 0) continue;
			bx = i;
			while (bx + 1 < n && board[bx + 1][j] == -2) {
				bx++;
			}

			if (bx == i) continue;
			board[bx][j] = board[i][j];
			board[i][j] = -2;
		}
	}
}

void rotating() {
	int copy[25][25];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			copy[i][j] = board[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			board[i][j] = copy[j][n - 1 - i];
		}
	}
}

void solution() {
	while (true) {
		BLOCK largestBlock = getLargestBlock();
		if (largestBlock.size < 2) break;
		removing(largestBlock);
		moving();
		rotating();
		moving();
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