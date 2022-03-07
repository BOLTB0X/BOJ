#include <iostream>
#include <vector>
#define MS 20001
using namespace std;

int v, e;
bool check = false;
vector<int> graph[MS];
int visited[MS]; //이분 그래프이므로 색으로 구분 1:빨 2:파 0:방문X

//깊이우선탐색
void DFS(int start) {
    if (!visited[start]) 
        visited[start] = 1;
    
    for (int i = 0; i < graph[start].size(); i++) {
        int next = graph[start][i];
        if (!visited[next]) {
            if (visited[start] == 1) 
                visited[next] = 2;
            
            else if (visited[start] == 2) 
                visited[next] = 1;
            
            DFS(next);
        }
    }
    return;
}

void solution(int t) {
    while (t--) {
        cin >> v >> e;
    
        //테스트 케이스가 있으므로
        for (int i = 1; i <= v; i++) {
            graph[i].clear(); //그래프 초기화
            visited[i] = 0;   //방문 초기화
        }

        for (int i = 1; i <= e; i++) {
            int value1, value2;
            cin >> value1 >> value2;

            graph[value1].push_back(value2);
            graph[value2].push_back(value1);
        }

        for (int i = 1; i <= v; i++) {
            if (visited[i] == 0)
                DFS(i);
        }

        bool check = true;
        for (int i = 1; i <= v; i++) {
            for (int j = 0; j < graph[i].size(); j++) {
                if (visited[i] == visited[graph[i][j]]) //색이 달라야 하는데 같으므로
                    check = false;
            }
        }

        if (check) 
            cout << "YES" << "\n";
        else 
            cout << "NO" << "\n";
    }
    return;
}

int main(void) {
    int t;
    cin >> t;

    solution(t);
    return 0;
}