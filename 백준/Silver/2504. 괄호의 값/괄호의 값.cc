#include <bits/stdc++.h>
using namespace std;

bool flag = true;
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
					flag = false;
					break;
				}
				
				S.pop();
				num += temp;
			}
			
			if(S.empty() || !flag){
				flag = false;
				break;
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
					flag = false;
					break;
				}
				
				S.pop();
				num += temp;
			}
			
			if(S.empty() || !flag){
				flag = false;
				break;
			}
			
			S.pop();
			if(num == 0) num = -1;
			S.push(num * 3);
		}
		else {
			flag = false;
			break;
		}
	}
	
	
	while(flag && S.size()) {
		if(S.top() == '(' || S.top() == '[') {
			result = 0;
			break;
		}
		
		result += S.top();
		S.pop();
	}

	cout << -result;
}