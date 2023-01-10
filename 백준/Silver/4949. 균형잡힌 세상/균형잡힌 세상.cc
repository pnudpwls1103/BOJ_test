#include <bits/stdc++.h>
using namespace std;

bool flag = true;
stack<int> S;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string str(" ");
	while(true) {
		getline(cin, str);
		if(str == ".") break;
		
		flag = true;
		while(!S.empty())
			S.pop();
		
		for(int i = 0; i < str.length() && flag; i++) {
			char c = str[i];
			if(c=='(' || c=='[') {
				S.push(c);
			}
			else if(c==')' || c==']') {
				if(S.empty()) flag = false;
				else if(c==')' && S.top()!='(') flag = false;
				else if(c==']' && S.top()!='[') flag = false;
				else S.pop();
			}
		}
		
		if(!S.empty()) flag = false;
		
		if(flag) cout << "yes" << '\n';
		else cout << "no" << '\n';
	}
}