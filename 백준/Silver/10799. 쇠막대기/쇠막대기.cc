#include <bits/stdc++.h>
using namespace std;

int result;
string str;
stack<char> S;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> str;
	
	int stick = 0;
	char prev = str[0];
	for(char c : str) {
		if(S.empty() || c == '(') S.push(c);
		else if (c == ')' && c == prev) {
			S.pop();
			stick++;
		}
		else if (c == ')' && c != prev) {
			S.pop();
			result += S.size() + stick;
			stick = 0;
		}
		prev = c;
	}
	
	cout << result + stick;
}