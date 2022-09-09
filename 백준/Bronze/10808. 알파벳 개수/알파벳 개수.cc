#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string str;
	int word[26];
	fill(word, word+26, 0);
	
	cin >> str;
	for(int i = 0; i < str.length(); i++) {
		word[str[i]-'a']++;
	}
	
	for(int i = 0; i < 26; i++) {
		cout << word[i] << " ";
	}
}