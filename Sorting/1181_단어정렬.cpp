#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool compare(string a, string b) {
	//길이
	if (a.length() < b.length())
		return 1;
	else if (b.length() < a.length())
		return 0;
	else
		return a < b; //사전순
}

int main(void) {
	int n;
	cin >> n;
	vector<string> str;

	for (int i = 0; i < n; i++) {
		string word;
		cin >> word;
		str.push_back(word);
	}
	sort(str.begin(),str.end(),compare);

	for (int i = 0; i < n; i++) {
		if (i>0 && str[i - 1] == str[i])
			continue;
		cout << str[i] << '\n';
	}
	return 0;
}