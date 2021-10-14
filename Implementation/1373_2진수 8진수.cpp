#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    string s = "";
    // string���� �Է�
    getline(cin, s);
    // �ڸ����� 3���� ������ �������� �����
    while (s.size() % 3 != 0) {
        s = '0' + s;
    }
    string answer = "";
    for (int i = 0; i < s.size(); i += 3) {
        int tmp = 0;
        // 3�ڸ��� 8������ ��ȯ�ϱ�
        for (int j = i; j < i + 3; j++) {
            tmp += (s[j] - '0') * pow(2, 2 - (j % 3));
        }
        answer += to_string(tmp);
    }
    cout << answer << '\n';
    return 0;
}
