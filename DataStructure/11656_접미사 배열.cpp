#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void solution(void) {
	string str;
	vector<string> result;

	cin >> str;
	//substr�̿��Ͽ� ������Ϳ� ����
	for (int i = 0; i < str.length(); ++i) {
		string tmp = str.substr(i);
		result.push_back(tmp);
	}
	
	//sort�Լ� �̿�
	sort(result.begin(), result.end());

	//���� ���
	for (int i = 0; i < result.size(); ++i)
		cout << result[i] << '\n';

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