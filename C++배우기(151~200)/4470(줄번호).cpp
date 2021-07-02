#include <iostream>
#include <string>
using namespace std;

int n;
int idx=1;


int main() {
	cin >> n;
	cin.ignore();
	while (n!=0)
	{
		string st;
		getline(cin, st);
		cout << idx << ". " << st << "\n";
		idx += 1;
		n -= 1;
		cin.clear();
	}
}