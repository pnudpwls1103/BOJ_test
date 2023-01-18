#include <bits/stdc++.h>
using namespace std;

int n, k;
int dist[1000002];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	fill(dist, dist+1000002, -1);
	
	queue<int> Q;
	dist[n] = 0;
	Q.push(n);
	
	while(dist[k] == -1) {
		int cur = Q.front(); Q.pop();
		
		for(int nxt : {2*cur, cur-1, cur+1}) {
			if(nxt < 0 || nxt > 1000000) continue;
			if(dist[nxt] != -1) continue;
			
			if(nxt != 2*cur) dist[nxt] = dist[cur] + 1;
			else if(dist[nxt] == -1) dist[nxt] = dist[cur];
			Q.push(nxt);
		}
	}
	
	cout << dist[k];
	return 0;
}