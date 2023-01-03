#include <bits/stdc++.h>
using namespace std;

int n;
queue<int> Q;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	string cmd;
	int num;
	while(n--) {
		cin >> cmd;
		if(cmd == "push") {
			cin >> num;
			Q.push(num);
		} else if(cmd == "pop") {
			if(Q.empty()) {
				cout << -1 << '\n';
				continue;
			}
			cout << Q.front() << '\n';
			Q.pop();
		} else if(cmd == "size") {
			cout << Q.size() << '\n';
		} else if(cmd == "empty") {
			cout << Q.empty() << '\n';
		} else if(cmd == "front") {
			if(Q.empty()) {
				cout << -1 << '\n';
				continue;
			}
			cout << Q.front() << '\n';
		} else if(cmd == "back") {
			if(Q.empty()) {
				cout << -1 << '\n';
				continue;
			}
			cout << Q.back() << '\n';
		} else {
			 cout << "Wrong" << '\n';
		}
	}
}