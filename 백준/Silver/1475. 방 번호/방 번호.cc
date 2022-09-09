#include <bits/stdc++.h>
using namespace std;


int nums[10];

int main(){
	int n, e = 10;
	cin >> n;
	
	while(n > 0) {
		if((n % e == 6 || n % e == 9) && (nums[6] != nums[9])) {
			if(nums[6] < nums[9]) nums[6]++;
			else nums[9]++;
		} else nums[n % e]++;
		n /= e;
	}
	
	int max = -1;
	for(int i = 0; i < 10; i++) {
		if(max < nums[i]) max = nums[i];
	}
	cout << max;
}