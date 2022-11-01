#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	stack<int> S;
	
	cin >> n;
	
	int tmp;
	while(n--) {
		cin >> tmp;
		if(tmp == 0)
			S.pop();
		else
			S.push(tmp);
	}
	
	int sum = 0;
	int len = S.size();
	for(int i = 0; i < len; i++) {
		sum += S.top();
		S.pop();
	}
	
	cout << sum;
	
}