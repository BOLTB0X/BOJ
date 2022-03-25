#include <iostream>
#include <vector>
#include <cmath> // sqrt

using namespace std;

typedef struct {
	double y, x;
} Pair;

int get_Score(double y, double x) {
	double len = sqrt((y * y) + (x * x));

	if (len <= 3)
		return 100;
	else if (len <= 6)
		return 80;
	else if ( len <= 9)
		return 60;
	else if (len <= 12)
		return 40;
	else if (len <= 15)
		return 20;
	return 0;
}

void solution(vector<Pair>& v) {
	int tot_A = 0;
	int tot_B = 0;

	for (int i = 0; i < 6; ++i) {
		if (i < 3)
			tot_A += get_Score(v[i].y, v[i].x);
		else
			tot_B += get_Score(v[i].y, v[i].x);
	}

	if (tot_A > tot_B)
		cout << "SCORE: " << tot_A << " to " << tot_B << ", PLAYER 1 WINS." << '\n';
	else if (tot_A < tot_B)
		cout << "SCORE: " << tot_A << " to " << tot_B << ", PLAYER 2 WINS." << '\n';
	else
		cout << "SCORE: " << tot_A << " to " << tot_B << ", TIE." << '\n';

	return;
}

int main(void) {
	int T;

	cin >> T;
	while (T--) {
		vector<Pair> v(6);
		for (int i = 0; i < 6; ++i)
			cin >> v[i].y >> v[i].x;

		solution(v);
	}

	return 0;
}