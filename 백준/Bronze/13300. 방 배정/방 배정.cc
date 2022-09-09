#include <bits/stdc++.h>
using namespace std;

int grooms[7] = { };
int brooms[7] = { };
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k, s, y;
	int cnt = 0;
	
	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		cin >> s >> y;
		if(s == 0) grooms[y]++;
		else brooms[y]++;
	}
	
	// s = 0 여학생, s = 1 남학생
	// 나머지가 있을 경우 cnt 하나 증가해야 함
	for(int i = 1; i <= 6; i++) {
		cnt += grooms[i] / k;
		if(grooms[i] % k) cnt++;
		cnt += brooms[i] / k;
		if(brooms[i] % k) cnt++;
	}
	
	cout << cnt;
}
