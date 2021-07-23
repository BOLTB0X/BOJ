#include <iostream>
#include <string>
using namespace std;
//n이 홀수면 비트가 달라야 하고
//n이 짝수는 비트가 같아야 함
int main(void) {
	int n;
	string st1, st2;

	cin >> n;
	cin >> st1 >> st2;

	if (n % 2 != 0)
		for (int i = 0; i < st1.size(); i++)
			if (st1[i] == '0')
				st1[i] = '1';
			else
				st1[i] = '0';
	if (st1 == st2)
		cout << "Deletion succeeded" << endl;
	else
		cout << "Deletion failed" << endl;

	return 0;
}