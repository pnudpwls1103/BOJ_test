#include <bits/stdc++.h>
using namespace std;

int result = 0;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	string str;
	while(n--) {
		cin >> str;
		bool flag = false;
		stack<int> S;
		int cntA = 0, cntB = 0;
		
		for(char c : str) {
			if(S.empty()) S.push(c);
			else if(S.top() != c) S.push(c);
			else S.pop();
		}
		if(S.empty()) result++;
	}
	cout << result;
}