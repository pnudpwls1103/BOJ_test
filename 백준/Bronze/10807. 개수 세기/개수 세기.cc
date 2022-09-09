#include <bits/stdc++.h>
using namespace std;

int input[201] = { };
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, v;
	cin >> n;
	
	// v 범위가 -100~100이라서 +100으로 인덱스를 조절함
	int temp;
	for(int i = 0; i < n; i++) {
		cin >> temp;
		input[temp+100]++;
	}
	cin >> v;
	
	cout << input[v+100];
	
}
