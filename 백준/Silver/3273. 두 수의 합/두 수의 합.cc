#include <bits/stdc++.h>
using namespace std;

int input[100001]={};
bool nums[2000001];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, x, cnt = 0;
	cin >> n;
	for(int i = 0; i < n; i++) cin >> input[i];
	cin >> x;
	
	for(int i = 0; i < n; i++) {
		int e = input[i];
		if(x-e > 0 && nums[x-e]) cnt++;
		nums[e] = true;
	}
	
	cout << cnt;
	
}