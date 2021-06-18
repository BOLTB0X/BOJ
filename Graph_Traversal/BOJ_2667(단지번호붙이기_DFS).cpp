#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int cnt=0; //�� �Ѵ��� ��
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
string graph[26];
vector<int> answer; //����Ʈ ������ ī��Ʈ�� ����
bool visited[26][26];

void dfs(int x, int y) {
    cnt++; //���� �� ���� ���� ����
    visited[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && nx < n && 0 <= ny && ny < n) //���� ���� �ְ�
            if (graph[nx][ny] == '1' && visited[nx][ny] == false) //���� �湮���� ���� ��
                dfs(nx, ny);
    }
}

int main(void) {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> graph[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j] == '1' && visited[i][j] == false)
            {
                cnt = 0;
                dfs(i, j);
                answer.push_back(cnt);
            }
        }
    sort(answer.begin(), answer.end());
    cout << answer.size() << endl;
    for (int i = 0; i < answer.size(); i++)
        cout << answer[i] << endl;
    return 0;
}
