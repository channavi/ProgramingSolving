#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int MAXN = 1000;
const int INF = 987654321;

int N, M; // 맵의 크기
int Map[MAXN][MAXN]; // 맵
int dist[MAXN][MAXN]; // 시작점으로부터의 최단거리
bool visited[MAXN][MAXN]; // 방문 여부

struct Coord {
    int x, y;
};

Coord start; // 시작점 좌표
Coord end; // 목표지점 좌표

// 인접한 셀을 확인하여 방문하지 않았고 이동 가능한 경우 큐에 추가합니다.
void bfs(int x, int y) {
    queue<Coord> q;
    q.push({ x, y });
    visited[x][y] = true;
    dist[x][y] = 0;

    while (!q.empty()) {
        Coord cur = q.front();
        q.pop();

        int dx[4] = { 1, -1, 0, 0 };
        int dy[4] = { 0, 0, 1, -1 };

        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (Map[nx][ny] == 0 || visited[nx][ny]) continue;

            visited[nx][ny] = true;
            dist[nx][ny] = dist[cur.x][cur.y] + 1;
            q.push({ nx, ny });
        }
    }
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> Map[i][j];
            dist[i][j] = INF;
            visited[i][j] = false;

            if (Map[i][j] == 2) {
                start = { i, j };
            }
            else if (Map[i][j] == 3) {
                end = { i, j };
            }
        }
    }

    bfs(start.x, start.y);

    if (dist[end.x][end.y] == INF) {
        cout << "목표 지점에 도달할 수 없습니다." << endl;
    }
    else {
        cout << "목표 지점까지의 최단 거리는 " << dist[end.x][end.y] << "입니다." << endl;
    }

    return 0;
}