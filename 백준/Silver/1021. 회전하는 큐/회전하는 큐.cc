#include <bits/stdc++.h>
using namespace std;

int n, m;
int idx[50];
int curidx[50];
deque<int> DQ;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i = 0; i < m; i++)
		cin >> idx[i];
	copy(begin(idx), idx+m, begin(curidx));
	
	for(int i = 1; i <= n; i++) {
		DQ.push_back(i);
	}
	
	int index = 0, sum = 0;
	while(index < m) {
		if(DQ.front() == idx[index]) {
			DQ.pop_front();
			index++;
			for(int i = index; i < m; i++) {
				curidx[i]--;
			}
			continue;
		}
		
		if(curidx[index] <= DQ.size()/2+1){
			int temp = DQ.front();
			DQ.pop_front();
			DQ.push_back(temp);
			for(int i = index; i < m; i++) {
				curidx[i]--;
				if(curidx[i] <= 0) curidx[i] += DQ.size();
			}
		}
		else {
			int temp = DQ.back();
			DQ.pop_back();
			DQ.push_front(temp);
			for(int i = index; i < m; i++) {
				curidx[i]++;
				if(curidx[i] > DQ.size()) curidx[i] %= DQ.size();
			}
		}
		sum++;
	}

	cout << sum;
	
	return 0;
}