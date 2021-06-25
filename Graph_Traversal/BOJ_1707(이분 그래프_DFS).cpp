#include <iostream>
#include <vector>
#include <stack>
#define MAX 20001
using namespace std;
int v, e;
vector<int> graph[MAX];
int visited[MAX]; //�̺� �׷����̹Ƿ� ������ ���� 1:�� 2:�� 0:�湮X

void DFS(int start) {
    stack<int> st;
    st.push(start);
    visited[start] = 1;
    while (!st.empty()) {
        int next = st.top();
        st.pop();
        for (int i = 0; i < graph[next].size(); i++) {
            // �� 
            if (visited[next] == 1)
            {
                // ������ ���� �Ķ� ó��
                if (visited[graph[next][i]] == 0)
                {
                    st.push(graph[next][i]);
                    visited[graph[next][i]] = 2;
                }
            }
            // �Ķ� 
            else if (visited[next] == 2)
            {
                // ������ ���� �������� ��ĥ 
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
        for (int i = 1; i <= v; i++) //�׽�Ʈ ���̽��� �����Ƿ�
        {
            graph[i].clear(); //�׷��� �ʱ�ȭ
            visited[i] = 0;   //�湮 �ʱ�ȭ
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