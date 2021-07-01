#include <iostream> 
#include <string> 
using namespace std; 

int main(void) { 
	int t, tot, len; 
	cin >> t; 
	for (int i = 0; i < t; i++) {
		string s; 
		bool check[26] = { false, }; 

		cin >> s; 
		tot = 0; 
		len = s.length();
		for (int j = 0; j < len; j++) 
			check[(char)s[j] - 'A'] = true; 
		for (int j = 0; j < 26; j++) 
			if (!check[j]) 
				tot += (j + 65); 

		cout << tot << '\n'; 
	}
	return 0;
}
