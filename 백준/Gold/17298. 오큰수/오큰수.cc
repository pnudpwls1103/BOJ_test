#include <bits/stdc++.h>
using namespace std;

int nums[1000000];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	for(int i = 0; i < n; i++)
		cin >> nums[i];
	
	int cur;
	stack<int> S;
	stack<int> result;
	for(int i = n - 1; i >= 0; i--) {
		cur = nums[i];
		while(S.size() && S.top() <= cur)
			S.pop();
		
		if(S.empty()) result.push(-1);
		else result.push(S.top());
		S.push(cur);
	}
	
	while(result.size()) cout << result.top() << " ", result.pop();
}