#include <bits/stdc++.h>
using namespace std;

int building[80000];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	for(int i = 0; i < n; i++)
		cin >> building[i];
	
	int cur;
	long long result = 0;
	stack<int> S;
	for(int i = 0; i < n; i++) {
		cur = building[i];
		
		while(S.size() && S.top() <= cur)
			S.pop();
		
		result += S.size();
		
		S.push(cur);
	}
	
	cout << result;
}