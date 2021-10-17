#include <iostream>
#include <cmath>

using namespace std;

int get_score(double x, double y) {
	int score = 0;
	double len = sqrt((x * x) + (y * y));

	if (len <= 3)
		score += 100;
	else if (len <= 6)
		score += 80;
	else if (len <= 9)
		score += 60;
	else if (len <= 12)
		score += 40;
	else if (len <= 15)
		score += 20;

	return score;
}

int main(void) {
	//ÃÊ±âÈ­
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	
	cin >> T;
	while (T--) {
		int player_1 = 0;
		int player_2 = 0;

		for (int i = 0; i < 6; ++i) {
			double x, y;
			cin >> x >> y;

			if (i < 3) 
				player_1 += get_score(x, y);
			else
				player_2 += get_score(x, y);
		}

		cout << "SCORE: " << player_1 << " to " << player_2 << ", ";
		if (player_1 > player_2)
			cout << "PLAYER 1 WINS.\n";
		else if (player_1 < player_2)
			cout << "PLAYER 2 WINS.\n";
		else
			cout << "TIE.\n";
	}
	return 0;
}