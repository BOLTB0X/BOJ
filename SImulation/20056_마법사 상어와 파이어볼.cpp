#include <iostream>
#include <vector>

using namespace std;

typedef struct {
	int y, x, mess, speed, d;
}FireBall;

vector<FireBall> board[51][51];
vector<FireBall> fv; // ���̾ ����

const int dy[8] = { -1,-1,0,1,1,1,0,-1 };
const int dx[8] = { 0,1,1,1,0,-1,-1,-1 };

// �ʱ�ȭ
void init(int n) {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j)
			board[i][j].clear();
	}
	return;
}

int is_All_odd_even(int y, int x) {
	int odd_flag = 0;
	int even_flag = 0;

	for (int i = 0; i < board[y][x].size(); i++) {
		if (board[y][x][i].d % 2 == 0)
			even_flag = 1;
		else
			odd_flag = 1;
	}

	// �� Ȧ �Ǵ� �� ¦�̸� ������ �� �̾����
	if (even_flag == 1 && odd_flag == 0) 
		return 1;
	else if (even_flag == 0 && odd_flag == 1) 
		return 1;
	else 
		return 0;
}

// ���̾ �̵�
void fire_move(int n) {
	// �ϳ���
	for (FireBall& f : fv) {
		int ny = f.y + dy[f.d] * f.speed;
		int nx = f.x + dx[f.d] * f.speed;

		// ���� ����
		while (ny < 1)	ny += n;
		while (ny > n)	ny -= n;
		while (nx < 1)	nx += n;
		while (nx > n)	nx -= n;

		board[ny][nx].push_back({ ny,nx,f.mess,f.speed, f.d });
	}

	return;
}

void fire_update(int n) {
	vector<FireBall> uf; // ������Ʈ ����

	// 2������ �ִ� ���̾ ĭ
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			// ���ٸ�
			if (board[i][j].size() == 0)
				continue;

			// �ϳ��� ���
			else if (board[i][j].size() == 1)
				uf.push_back({ board[i][j][0] });

			else {
				int tot_m = 0, tot_s = 0;
				// ���� ĭ�� �ִ� ���̾�� ��� �ϳ��� ��ħ
				for (FireBall& f : board[i][j]) {
					tot_m += f.mess;
					tot_s += f.speed;
				}

				int avg_m = tot_m / 5;
				// ������ 0�� ���̾�� �Ҹ�Ǿ� ��������.
				if (avg_m == 0)
					continue;

				int avg_s = tot_s / board[i][j].size();

				// �������� ���̾ ���� Ȧ¦���� �˻�
				// ���� Ȧ�̰ų� ¦�� ���
				if (is_All_odd_even(i, j) == 1) {
					uf.push_back({ i,j,avg_m, avg_s, 0 });
					uf.push_back({ i,j,avg_m, avg_s, 2 });
					uf.push_back({ i,j,avg_m, avg_s, 4 });
					uf.push_back({ i,j,avg_m, avg_s, 6 });
				}
				// �� ��
				else {
					uf.push_back({ i,j,avg_m, avg_s, 1 });
					uf.push_back({ i,j,avg_m, avg_s, 3 });
					uf.push_back({ i,j,avg_m, avg_s, 5 });
					uf.push_back({ i,j,avg_m, avg_s, 7 });
				}
			}
		}
		// ���� ��ü
		fv = uf;
	}
	return;
}

int solution(int n, int m, int k) {
	int answer = 0;

	// �ùķ��̼� ����
	for (int t = 0; t < k; ++t) {
		//�� �ʱ�ȭ
		init(n);
		fire_move(n);
		fire_update(n);
	}

	// �����ִ� ���̾ ������ ��
	for (FireBall& f : fv)
		answer += f.mess;
	return answer;
}

int main(void) {
	int n, m, k;
	int y, x, mess, speed, d;

	cin >> n >> m >> k;

	for (int i = 0; i < m; ++i) {
		cin >> y >> x >> mess >> speed >> d;
		fv.push_back({ y,x,mess,speed,d });
	}

	int ret = solution(n, m, k);
	cout << ret;

	return 0;
}