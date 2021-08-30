#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
using namespace std;

struct pos {
    int x, y, z;
};


int map[101][101][101];
bool visited[101][101][101];
queue<pos> q;
int answer = -1;

void BFS(int m, int n, int h) {
    int dx[] = { -1,1,0,0,0,0 };
    int dy[] = { 0,0,0,0,-1,1 };
    int dz[] = { 0,0,-1,1,0,0 };
    //큐가 비어질때까지
    while (!q.empty()) {
        //각 위치에서 토마토가 익어가야하므로
        int q_size = q.size();
        ++answer;
        while (q_size--) {
            pos cur = q.front(); 
            q.pop();

            for (int i = 0; i < 6; i++) {
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];
                int nz = cur.z + dz[i];

                if (nx < 0 || nx >= m || ny < 0 || ny >= n || nz < 0 || nz >= h)
                    continue;
                if (!visited[nx][ny][nz] && map[nx][ny][nz] == 0) {
                    visited[nx][ny][nz] = true;
                    q.push({ nx, ny, nz });
                }
            }
        }
    }
}

void last_check(int m, int n, int h) {
    //안익은 토마토 탐색
    for (int k = 0; k < h; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[j][i][k]) {
                    answer = -1;
                    return;
                }
            }
        }
    }
    return;
}

int main() {
    int m, n, h;
    scanf("%d %d %d", &m, &n, &h);
    for (int k = 0; k < h; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &map[j][i][k]);
                if (map[j][i][k] == 1) {
                    q.push({ j,i,k });
                    visited[j][i][k] = true;
                }
                else if (map[j][i][k] == -1)
                    visited[j][i][k] = true;
            }
        }
    }
    BFS(m,n,h);
    last_check(m,n,h);
    printf("%d", answer);
    return 0;
}
