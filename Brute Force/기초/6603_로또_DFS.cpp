#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> lotto;
vector<int> com;
vector<bool> visited;

//깊이 우선 탐색
void DFS(int n, int cur, int dep) {
    int i;
    if (dep == 6) {
        //출력
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

        //탈출 조건
		if (n == 0) 
			return;
        
        //사이즈 할당
        lotto.resize(n);
        com.resize(n);
        visited.resize(n, false);

        //입력
        for (int i = 0; i < n; i++) 
            cin >> lotto[i];
        
        //오름차순 정렬
        sort(lotto.begin(), lotto.end());
        //호출
        DFS(n, 0, 0);
        cout << "\n";
	}
    return;
}

int main() {
    //초기화
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();
    return 0;
}