#include <iostream>

using namespace std;

int main(void) {
	int T;
	cin >> T;
	
	for (int t=1;t<=T;t++) {
		
		int months, days_of_month, days_of_week;
		
		cin >> months >> days_of_month >> days_of_week;
		int result = 0;
		int ir = 0;
		for (int i = 0; i < months; i++) {
			result += (days_of_month + ir) / days_of_week;
			
			if ((days_of_month + ir) % days_of_week != 0) {
				result++;
				ir = (days_of_month + ir) % days_of_week;
			}
			else
				ir = 0;
		}
		cout << "Case #" << t << ": " << result << '\n';
	}
	return 0;
}