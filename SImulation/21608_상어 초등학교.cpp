#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

struct student {
	int idx;
	int love[4];
	int y, x;
};

struct Heap {
	int y, x, love, blank;

	bool operator <(const Heap& h) const {
		if (love == h.love) {
			if (blank == h.blank) {
				if (y == h.y)
					return x < h.x;
				return y < h.y;
			}
			return blank > h.blank;
		}
		return love > h.love;
	}
};

int N;
int board[21][21];
vector<student> students;

// 상하좌우
const int dy[4] = { -1,1,0,0 };
const int dx[4] = { 0,0,-1,1 };
// 만족도
const int satisfy[5] = { 0,1,10,100,1000 };

void sitting(void) {
	for (int s = 0; s < N * N; ++s) {
		vector<Heap> heap;

		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				// 빈 자리 발견
				if (board[i][j] == 0) {
					int love = 0, blank = 0;

					for (int dir = 0; dir < 4; ++dir) {
						int ny = i + dy[dir];
						int nx = j + dx[dir];

						// 범위 초과
						if (ny < 1 || nx < 1 || ny > N || nx > N)
							continue;

						// 빈자리인 경우
						if (board[ny][nx] == 0)
							blank++;

						// 학생이 있다면
						else {
							for (int k = 0; k < 4; ++k) {
								if (board[ny][nx] == students[s].love[k]) {
									love++;
									break;
								}
							}
						}
					}

					// 대기열에 삽입
					heap.push_back({ i,j,love, blank });
					sort(heap.begin(), heap.end());
				}
			}
		}

		if (!heap.empty()) {
			board[heap[0].y][heap[0].x] = students[s].idx;
			students[s].y = heap[0].y;
			students[s].x = heap[0].x;
		}
	}
	return;
}

// 만족도 계산
int get_satisfy_score(void) {
	int tot = 0;

	for (auto& st : students) {
		int love = 0;
		for (int dir = 0; dir < 4; ++dir) {
			int ny = st.y + dy[dir];
			int nx = st.x + dx[dir];

			if (ny < 1 || nx < 1 || ny > N || nx > N)
				continue;

			if (board[ny][nx] != 0) {
				for (int k = 0; k < 4; ++k) {
					if (board[ny][nx] == st.love[k]) {
						love++;
						break;
					}
				}
			}
		}
		tot += satisfy[love];
	}

	return tot;
}

int solution(void) {
	int answer = 0;

	sitting(); // 자리 배치
	answer = get_satisfy_score();
	return answer;
}
int main(void) {
	memset(board, 0, sizeof(board));

	cin >> N;
	students = vector<student>(N * N);
	for (int i = 0; i < N * N; ++i) 
		cin >> students[i].idx >> students[i].love[0] >> students[i].love[1] >> students[i].love[2] >> students[i].love[3];
	
	int ret = solution();
	cout << ret;
	return 0;
}
