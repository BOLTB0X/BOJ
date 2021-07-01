#include <iostream>
using namespace std;

int t,n; //가위 바위 보 횟수
char player1, player2;
int p1_cnt, p2_cnt;

int main(void) {
	cin >> t;
	while (t != 0) {
		cin >> n;
		p1_cnt = 0;
		p2_cnt = 0;
		// R가위 P바위 S보
		for (int i = 0; i < n; i++) {
			cin >> player1 >> player2;
			if (player1 == player2)
				continue;
			else if (player1 == 'R' && player2 == 'P') p2_cnt += 1;
			else if (player1 == 'R' && player2 == 'S') p1_cnt += 1;
			else if (player1 == 'P' && player2 == 'R') p1_cnt += 1;
			else if (player1 == 'P' && player2 == 'S') p2_cnt += 1;
			else if (player1 == 'S' && player2 == 'R') p2_cnt += 1;
			else if (player1 == 'S' && player2 == 'P') p1_cnt += 1;
		}
		if (p1_cnt > p2_cnt) cout << "player 1" << '\n';
		else if (p1_cnt < p2_cnt) cout << "player 2" << '\n';
		else cout << "TIE" << '\n';

		t -= 1;
	}
		return 0;
}