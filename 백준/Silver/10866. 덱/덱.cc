#include <bits/stdc++.h>
using namespace std;

int n;
deque<int> DQ;
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  string cmd;
  int num;
  cin >> n;
  while(n--) {
  	cin >> cmd;
  	if(cmd == "push_front") {
  		cin >> num;
  		DQ.push_front(num);
  	} else if(cmd == "push_back") {
  		cin >> num;
  		DQ.push_back(num);
  	} else if(cmd == "pop_front") {
  		if(DQ.empty()) {
  			cout << -1 << '\n';
  			continue;
  		}
  		cout << DQ.front() << '\n';
  		DQ.pop_front();
  	} else if(cmd == "pop_back") {
  		if(DQ.empty()) {
  			cout << -1 << '\n';
  			continue;
  		}
  		cout << DQ.back() << '\n';
  		DQ.pop_back();
  	} else if(cmd == "size") {
  		cout << DQ.size() << '\n';
  	} else if(cmd == "empty") {
  		cout << DQ.empty() << '\n';
  	} else if(cmd == "front") {
  		if(DQ.empty()) {
  			cout << -1 << '\n';
  			continue;
  		}
  		cout << DQ.front() << '\n';
  	} else if(cmd == "back") {
  		if(DQ.empty()) {
  			cout << -1 << '\n';
  			continue;
  		}
  		cout << DQ.back() << '\n';
  	}
  }
}