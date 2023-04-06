#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#define X first
#define Y second
using namespace std;

struct PLACE {
	int x = 0;
	int y = 0;
	int dist = 0;

	PLACE(int _x, int _y, int _dist) {
		x = _x;
		y = _y;
		_dist = dist;
	}
};

int n, m, answer;
int board[55][55];
vector<PLACE> house;
vector<pair<int, int>> chicken;
deque<pair<int, int>> choose;
int vis[55][55];

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1) {
				PLACE place = PLACE(i, j, 0);
				house.push_back(place);
			}
			if (board[i][j] == 2) {
				chicken.push_back({ i, j });
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

	for (int i = 0; i < choose.size(); i++) {
		pair<int, int> cur = choose[i];

		for (int j = 0; j < house.size(); j++) {
			PLACE h = house[j];
			int temp = abs(h.x, cur.X) + abs(h.y, cur.Y);

			if (house[j].dist == 0 || house[j].dist > temp)
				house[j].dist = temp;
		}
	}
}

void getMinDistance() {
	int temp = 0;
	for (int i = 0; i < house.size(); i++) {
		temp += house[i].dist;
	}

	if (answer == 0 || answer > temp) answer = temp;
}

void dfs(int start, int cnt) {
	if (cnt == m) {
		calDist();
		getMinDistance();
		return;
	}

	pair<int, int> cur;
	for (int i = start; i < chicken.size(); i++) {
		cur = chicken[i];
		if (vis[cur.X][cur.Y]) continue;
		choose.push_back(cur);
		vis[cur.X][cur.Y] = 1;
		dfs(i, cnt + 1);
		vis[cur.X][cur.Y] = 0;
		choose.pop_back();
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