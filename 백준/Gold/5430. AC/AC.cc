#include <bits/stdc++.h>
using namespace std;

int n;
string func;
int len;
string arr;
deque<string> DQ;

deque<string> split(string str, char delimiter) {
	int previous = 0, current = 0;
	deque<string> x;
	x.clear();
	
	current = str.find(delimiter);
	while(current != string::npos) {
		string substring = str.substr(previous, current-previous);
		x.push_back(substring);
		previous = current + 1;
		current = str.find(delimiter, previous);
	}
	x.push_back(str.substr(previous, current-previous));
	
	return x;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	int head, tail;
	for(int i = 0; i < n; i++) {
		bool flag = true;
		bool reverse = false;
		DQ.clear();
		cin >> func >> len >> arr;
		
		if(arr.length() > 2) {
			DQ = split(arr.substr(1, arr.length()-2), ',');
		}
		
		for(int j = 0; j < func.length(); j++) {
			if(func[j] == 'R') {
				reverse = (reverse) ? false : true;
			} 
			else if(func[j] == 'D') {
				if(DQ.empty()) {
					flag = false;
					continue;
				}
				
				if(reverse) {
					DQ.pop_back();
				} 
				else {
					DQ.pop_front();
				}
			}
		}
		
		head = 0;	tail = DQ.size()-1;

		if(flag) {
			cout << '[';
			if(reverse) {
				for(int j = DQ.size()-1; j >= 0; j--) {
					cout << DQ[j];
					if(j != 0) {
						cout << ',';
					}
				}	
			}
			else {
				for(int j = 0; j < DQ.size(); j++) {
					cout << DQ[j];
					if(j != DQ.size()-1) {
						cout << ',';
					}
				}
			}
			cout << "]\n";
		} else {
			cout << "error\n";
		}
	}
}