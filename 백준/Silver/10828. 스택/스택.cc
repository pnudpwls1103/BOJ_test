#include <bits/stdc++.h>
using namespace std;

int dat[10000];
int pos = 0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	string tmp;
	while(n--) {
		cin >> tmp;
		if(tmp == "push") {
			cin >> tmp;
			dat[pos++] = stoi(tmp);
		}
		else if(tmp == "pop") {
			if(!dat[pos-1]) cout << -1 << '\n';
			else cout << dat[--pos] << '\n';
		}
		else if(tmp == "top") {
			if(!dat[pos-1]) cout << -1 << '\n';
			else cout << dat[pos-1] << '\n';
		}
		else if(tmp == "empty") {
			if(pos) cout << 0 << '\n';
			else cout << 1 << '\n';
		}
		else if(tmp == "size") {
			cout << pos << '\n';
		}
	}
}