#include <bits/stdc++.h>
using namespace std;

int alpha1[26] = { };
int alpha2[26] = { };
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	string a, b;
	bool flag = true;
	
	for(int i = 0; i < n; i++) {
		cin >> a >> b;
		if(a.size() != b.size()) {
			cout << "Impossible\n";
			continue;
		}
		
		// 하나의 문자열이 끝나면 배열 초기화를 해야 함
		flag = true;
		for(int i = 0; i < 26; i++) {
			alpha1[i] = 0;
			alpha2[i] = 0;
		}
		
		for(int i = 0; i < a.size(); i++) alpha1[a[i]-'a']++;
		for(int i = 0; i < b.size(); i++) alpha2[b[i]-'a']++;
		for(int i = 0; i < 26; i++) {
			if(alpha1[i] != alpha2[i]) {
				flag = false;
				cout << "Impossible\n";
				break;
			}
		}
		if(flag) cout << "Possible\n";
		
		a.clear();
		b.clear();
	}
}
