#include <iostream>
#include <vector>
#include <stack>
#define MAX 20001
using namespace std;
int v, e;
vector<int> graph[MAX];
int visited[MAX]; //이분 그래프이므로 색으로 구분 1:빨 2:파 0:방문X

void DFS(int start) {
    stack<int> st;
    st.push(start);
    visited[start] = 1;
    while (!st.empty()) {
        int next = st.top();
        st.pop();
        for (int i = 0; i < graph[next].size(); i++) {
            // 빨 
            if (visited[next] == 1)
            {
                // 인접한 곳은 파랑 처리
                if (visited[graph[next][i]] == 0)
                {
                    st.push(graph[next][i]);
                    visited[graph[next][i]] = 2;
                }
            }
            // 파랑 
            else if (visited[next] == 2)
            {
                // 인접한 곳은 빨강으로 색칠 
                if (visited[graph[next][i]] == 0)
                {
                    st.push(graph[next][i]);
                    visited[graph[next][i]] = 1;
                }
            }
        }
    }
}

int main(void) {
    int t;
    cin >> t;
    while (t--) {
        cin >> v >> e;
        for (int i = 1; i <= v; i++) //테스트 케이스가 있으므로
        {
            graph[i].clear(); //그래프 초기화
            visited[i] = 0;   //방문 초기화
        }
        for (int i = 1; i <= e; i++)
        {
            int value1, value2;
            cin >> value1 >> value2;

            graph[value1].push_back(value2);
            graph[value2].push_back(value1);
        }
        for (int i = 1; i <= v; i++)
        {
            if (visited[i] == 0)
            {
                DFS(i);
            }
        }
        bool check = true;
        for (int i = 1; i <= v; i++)
        {
            for (int j = 0; j < graph[i].size(); j++)
            {
                if (visited[i] == visited[graph[i][j]])
                {
                    check = false;
                }
            }
        }
        if (check) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}