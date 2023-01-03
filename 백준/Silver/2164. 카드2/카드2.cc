#include <bits/stdc++.h>
using namespace std;

int n;
queue<int> Q;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	for(int i = 1; i <= n; i++) {
		Q.push(i);
	}
	
	while(Q.size() != 1) {
		Q.pop();
		if(Q.size() == 1) {
			break;
		}
		Q.push(Q.front());
		Q.pop();
	}
	
	cout << Q.front();
}