#include <bits/stdc++.h>
using namespace std;

int nums[500000];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	stack<pair<int, int>> S;
	for(int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	
	int cur;
	for(int i = 0; i < n; i++) {
		cur = nums[i];
		
		if(S.empty()) cout << "0 ";
		else {
			while(S.size() && S.top().second < cur)
				S.pop();
			
			if(S.empty()) cout << "0 ";
			else cout << S.top().first << " ";
		}
		S.push({i + 1, cur});
	}
}