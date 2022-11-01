#include <bits/stdc++.h>
using namespace std;

int nums[100000];
int main() {
	int n;
	cin >> n;
	
	for(int i = 0; i < n; i++)
		cin >> nums[i];
		
	int cur = 0, i = 1;
	stack<int> S;
	queue<char> q;
	
	while(cur < n) {
		if(i <= nums[cur]) {
			while(i <= nums[cur]) {
				S.push(i++);
				q.push('+');
			}
		} else if (S.size() && S.top() == nums[cur]) {
			S.pop();
			q.push('-');
			cur++;
		} else {
			cout << "NO" << '\n';
			return 0;
		}
	}
	
	while(q.size()) {
		cout << q.front() << '\n';
		q.pop();
	}
}