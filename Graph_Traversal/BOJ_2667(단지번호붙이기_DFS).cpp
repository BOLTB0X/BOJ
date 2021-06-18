#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int cnt=0; //각 총단지 수
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
string graph[26];
vector<int> answer; //아파트 단지별 카운트용 벡터
bool visited[26][26];

void dfs(int x, int y) {
    cnt++; //단지 내 집의 수를 센다
    visited[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && nx < n && 0 <= ny && ny < n) //범위 내에 있고
            if (graph[nx][ny] == '1' && visited[nx][ny] == false) //아직 방문하지 않은 집
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
