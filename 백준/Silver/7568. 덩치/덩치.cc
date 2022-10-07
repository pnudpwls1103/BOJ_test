#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	vector<pair<int, int>> v;
	vector<int> rank;
	int temp = 1;
	
	cin >> n;
	int x, y;
	for(int i = 0; i < n; i++) {
		cin >> x >> y;
		v.push_back(make_pair(x, y));
	}
	
	
	pair<int, int> v1, v2;
	for(int i = 0; i < n; i++) {
		temp = 1;
		v1 = v[i];
		for(int j = 0; j < n; j++) {
			v2 = v[j];
			if(v1.first < v2.first && v1.second < v2.second) {
				temp++;
			}
			
		}
		rank.push_back(temp);
	}
	
	for(int r : rank)
		cout << r << " ";
	
}