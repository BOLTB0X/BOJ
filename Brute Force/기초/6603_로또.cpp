#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solution(void) {
	int n;
	vector<int> per;
	vector<bool> visited;
	
	while (true) {
		//�Է�
		cin >> n;

		//Ż��
		if (n == 0) 
			return ;

		per.resize(n);
		visited.resize(n);

		for (int i = 0; i < n; ++i) 
			cin >> per[i];

		for (int i=0; i < 6;++i )
			visited[i] = true;

		//���� ���� ����
		sort(per.begin(), per.end());

		//��������
		do {
			for (int i = 0; i < n; ++i) {
				if (visited[i])
					cout << per[i] << " ";
			}
			cout << "\n";
		} while (prev_permutation(visited.begin(), visited.end()));
		cout << '\n';
	}

	return;
}

int main(void) {
	//�ʱ�ȭ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solution();
	return 0;
}