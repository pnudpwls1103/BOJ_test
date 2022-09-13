#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	string str, temp;
	cin >> str >> n;
	list<char> chars(str.begin(), str.end());
	list<char>::iterator t = chars.end();
	cin.ignore();
	
	for(int i = 0; i < n; i++) {
		getline(cin, temp, '\n');
		if(temp[0] == 'L') {
			if(t != chars.begin()) t--;
		} else if(temp[0] == 'D') {
			if(t != chars.end()) t++;
		} else if(temp[0] == 'B') {
			if(t != chars.begin()) {
				t--;
				t = chars.erase(t);
			}
		} else if(temp[0] == 'P') {
			chars.insert(t, temp[2]);
		}
	}
	
	for(char c : chars) {
		cout << c;
	}
	
}