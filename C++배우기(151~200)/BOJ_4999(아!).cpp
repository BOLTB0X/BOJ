#include <iostream>
#include <string>
using namespace std;
string jh;
string doc;

int main() {
	cin >> jh;
	cin >> doc;

	cout << (jh.size() < doc.size() ? "no" : "go");
}