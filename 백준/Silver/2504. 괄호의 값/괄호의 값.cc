#include <bits/stdc++.h>
using namespace std;

int result = 0;
string str;
stack<int> S;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> str;

	for(int c : str) {
		int num = 0;
		if(c == '(' || c == '[') S.push(c);
		else if (c == ')') {
			while(!S.empty() && S.top() != '(') {
				int temp = S.top();
				if(temp == '(') break;
				if(temp == '[') {
					cout << 0;
					return 0;
				}
				
				S.pop();
				num += temp;
			}
			
			if(S.empty()){
				cout << 0;
				return 0;
			}
			S.pop();
			if(num == 0) num = -1;
			S.push(num * 2);
		}
		else if (c == ']') {
			while(!S.empty() && S.top() != '[') {
				int temp = S.top();
				if(temp == '[') break;
				if(temp == '(') {
					cout << 0;
					return 0;
				}
				
				S.pop();
				num += temp;
			}
			
			if(S.empty()){
				cout << 0;
				return 0;
			}
			
			S.pop();
			if(num == 0) num = -1;
			S.push(num * 3);
		}
		else {
			cout << 0;
            return 0;
		}
	}
	
	
	while(S.size()) {
		if(S.top() == '(' || S.top() == '[') {
			cout << 0;
			return 0;
		}
		
		result += S.top();
		S.pop();
	}

	cout << -result;
}