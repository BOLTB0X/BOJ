#include<iostream>
#include<vector>

using namespace std;

vector<int> cards(21);

void init(void) {
	for (int i = 1; i <= 20; ++i)
		cards[i] = i;
	return;
}

void reverse_arr(int start, int end) {
	int* tmp = new int[start + end + 1];
	int tmp_idx = 0;
	for (int i = end; i >= start; --i) 
		tmp[tmp_idx++] = cards[i];

	for (int i = start, j = 0; i <= end; ++i, ++j)
		cards[i] = tmp[j];
	delete[] tmp;
	return;
}

void solution(vector<pair<int, int>>& cmd) {
	init();

	for (auto& c : cmd) {
		int start = c.first;
		int end = c.second;

		reverse_arr(start, end);
	}
	for (int i = 1; i <= 20; ++i)
		cout << cards[i] << ' ';
	return;
}

int main(void) {
	int a, b;
	vector<pair<int, int>> cmd;

	for (int i = 0; i < 10; ++i) {
		cin >> a >> b;

		cmd.push_back({ a,b });
	}

	solution(cmd);
	return 0;
}