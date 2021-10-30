#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> lotto;
vector<int> com;
vector<bool> visited;

//���� �켱 Ž��
void DFS(int n, int cur, int dep) {
    int i;
    if (dep == 6) {
        //���
        for (i = 0; i < 6; i++)
            cout << com[i] << " ";
        cout << "\n";
        return;
    }

    for (int i = cur; i < n; i++) {
        if (visited[i])
            continue;
        visited[i] = true;
        com[dep] = lotto[i];
        DFS(n, i + 1, dep + 1);
        visited[i] = false;
    }
    return;
}

void solution(void) {
    int n;
    while (true) {
		cin >> n;

        //Ż�� ����
		if (n == 0) 
			return;
        
        //������ �Ҵ�
        lotto.resize(n);
        com.resize(n);
        visited.resize(n, false);

        //�Է�
        for (int i = 0; i < n; i++) 
            cin >> lotto[i];
        
        //�������� ����
        sort(lotto.begin(), lotto.end());
        //ȣ��
        DFS(n, 0, 0);
        cout << "\n";
	}
    return;
}

int main() {
    //�ʱ�ȭ
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();
    return 0;
}