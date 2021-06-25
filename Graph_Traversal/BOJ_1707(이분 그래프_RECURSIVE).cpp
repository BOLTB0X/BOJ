#include <iostream>
#include <vector>
#define MAX 20001
using namespace std;
int v, e;
bool check = false;
vector<int> graph[MAX];
int visited[MAX]; //�̺� �׷����̹Ƿ� ������ ���� 1:�� 2:�� 0:�湮X

void DFS(int start) {
    if (!visited[start]) {
        visited[start] = 1;
    }
    for (int i = 0; i < graph[start].size(); i++) {
        int next = graph[start][i];
        if (!visited[next]) {
            if (visited[start] == 1) {
                visited[next] = 2;
            }
            else if (visited[start] == 2) {
                visited[next] = 1;
            }
            DFS(next);
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
                if (visited[i] == visited[graph[i][j]]) //���� �޶�� �ϴµ� �����Ƿ�
                {
                    check = false;
                }
            }
        }
        if (check) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}