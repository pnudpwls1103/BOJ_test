#include <bits/stdc++.h>
using namespace std;

int n, k;
int dot[100001];
int dx[] = {-1, 1, 2};
queue<int> Q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	fill(dot, dot+100001, -1);
	cin >> n >> k;
	Q.push(n);
	
	while(!Q.empty()) {
		int cur = Q.front();
		Q.pop();
		if(cur == k) {
			cout << dot[k]+1;
			return 0;
		}
		
		for(int dir = 0; dir < 3 ; dir++) {
			int nx;
			if(dx[dir] == 2) nx = cur * dx[dir];
			else nx = cur + dx[dir];
			
			if(nx < 0 || nx >= 100001) continue;
			if(dot[nx] >= 0) continue;
			
			dot[nx] = dot[cur] + 1;
			Q.push(nx);
		}
	}
	
	cout << dot[k]+1;
}