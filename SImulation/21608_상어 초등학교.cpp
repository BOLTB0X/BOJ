#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct {
	int student_idx;
	int y, x;
	int love[4];
} Shark;

struct Heap {
	int y, x, blank_cnt, love_cnt;

	// 문제조건
	bool operator < (const Heap& h) const {
		if (love_cnt == h.love_cnt) {
			if (blank_cnt == h.blank_cnt) {
				if (y == h.y)
					return x > h.x;
				return y > h.y;
			}
			return blank_cnt > h.blank_cnt;
		}
		return love_cnt > h.love_cnt;
	}
};

int n, result;
vector<Shark> student;
int board[21][21];

// 상하좌우
const int dy[4] = { 1, -1, 0, 0 };
const int dx[4] = { 0, 0, -1, 1 };
// 만족도
const int satisfy[5] = { 0, 1, 10, 100, 1000 };

void setting_sit(void) {
	// 순회
	for (int i = 1; i <= n * n; ++i) {
		vector<Heap> h;

		for (int y = 0; y < n; ++y) {
			for (int x = 0; x < n; ++x) {
				// 빈공간 발견
				if (board[y][x] == 0) {
					int blank = 0, love = 0;

					// 상하좌우 확인
					for (int dir = 0; dir < 4; ++dir) {
						int ny = y + dy[dir];
						int nx = x + dx[dir];

						if (ny < 0 || nx < 0 || ny >= n || nx >= n)
							continue;

						// 빈공간이면
						if (board[ny][nx] == 0)
							blank++; // 카운트

						else {
							// 선호도 검사
							for (int l = 0; l < 4; ++l) {
								if (board[ny][nx] == student[i].love[l]) {
									love++;
									break;
								}
							}
						}
					}
					h.push_back({ y,x,blank, love });
					sort(h.begin(), h.end()); // 정렬
				}
			}
		}
		// 만약 h = 대기석에 뭔가가 들어있다먄
		if (!h.empty()) {
			Heap cur = h[0];

			int cy = cur.y;
			int cx = cur.x;

			board[cy][cx] = student[i].student_idx;
			student[i].y = cy;
			student[i].x = cx;
		}
	}

	return;
}

// 점수 득점
int get_score(void) {
	int score = 0;
	for (int i = 1; i <= n * n; ++i) {
		int cy = student[i].y;
		int cx = student[i].x;

		int love = 0;
		for (int dir = 0; dir < 4; ++dir) {
			int ny = cy + dy[dir];
			int nx = cx + dx[dir];

			if (ny >= n || nx >= n || ny < 0 || nx < 0)
				continue;

			// 학생이 존재 한다면
			if (board[ny][nx] != 0) {
				for (int l = 0; l < 4; ++l) {
					if (board[ny][nx] == student[i].love[l]) {
						love++;
						break;
					}
				}
			}
		}
		score += satisfy[love];
	}

	return score;
}

int solution(void) {
	int answer = 0;

	setting_sit(); // 자리 배치
	answer = get_score(); // 만족도 계산
	return answer;
}

int main(void) {
	cin >> n;
	student.resize((n * n) + 1);
	for (int i = 1; i <=  n * n; ++i) {
		int a, b, c, d, e;

		cin >> a >> b >> c >> d >> e;
		
		student[i].student_idx = a;
		student[i].love[0] = b;
		student[i].love[1] = c;
		student[i].love[2] = d;
		student[i].love[3] = e;
	}

	int ret = solution();
	cout << ret;
	return 0;
}