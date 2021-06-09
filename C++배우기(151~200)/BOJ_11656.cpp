#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	vector<string> v;
	string st;
	string su;
	cin >> st;
	for (int i = 0; i < st.size(); i++) {
		su = st.substr(i);
		v.push_back(su);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
	return 0;
}