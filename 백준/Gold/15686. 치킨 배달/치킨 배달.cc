#include <iostream>
#include <vector>
#include <deque>
#define MAX 50
#define X first
#define Y second
using namespace std;

struct PLACE {
	int x;
	int y;
	int dist;

	PLACE(int _x, int _y, int _dist) {
		x = _x;
		y = _y;
		dist = _dist;
	}
};

int n, m, answer;
int vis[13];
int board[MAX][MAX];
vector< pair<int, int> > chicken;
vector<PLACE> house;

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];

			if (board[i][j] == 2) {
				chicken.push_back({ i, j });
			}
			else if (board[i][j] == 1) {
				house.push_back(PLACE(i, j, 0));
			}
		}
	}
}

int abs(int a, int b) {
	return (a > b) ? a - b : b - a;
}

void calDist() {
	for (int i = 0; i < house.size(); i++) {
		house[i].dist = 0;
	}

	for (int i = 0; i < chicken.size(); i++) {
		if (!vis[i]) continue;

		pair<int, int> ch = chicken[i];
		for (int j = 0; j < house.size(); j++) {
			PLACE h = house[j];
			int temp = abs(ch.X, h.x) + abs(ch.Y, h.y);

			if (h.dist == 0 || h.dist > temp) {
				house[j].dist = temp;
			}
		}
	}
}

void calAns() {
	int temp = 0;
	for (int i = 0; i < house.size(); i++) {
		temp += house[i].dist;
	}

	if (answer == 0 || answer > temp)
		answer = temp;
}

void dfs(int start, int cnt) {
	if (cnt == m) {
		calDist();
		calAns();
		return;
	}

	for (int i = start; i < chicken.size(); i++) {
		if (vis[i]) continue;		
		vis[i] = 1;
		dfs(i, cnt + 1);
		vis[i] = 0;
	}
}

void solution() {
	dfs(0, 0);
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