#include <iostream>
#include <queue>

using namespace std;

const int MAP_SIZE = 5;
const int PLAYER_x = 4;
const int PLAYER_y = 0;
const int GOAL_x = 4;
const int GOAL_y = 4;

int shortest[MAP_SIZE][MAP_SIZE];  // �ִܰŸ� ���� �迭
int dx[4] = { -1, 0, 1, 0 };  // �����¿� �̵��� ���� �迭
int dy[4] = { 0, 1, 0, -1 };

void bfs(char map[][MAP_SIZE], int row, int col) {
    queue<pair<int, int>> q;
    q.push(make_pair(row, col));
    shortest[row][col] = 0;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= MAP_SIZE || ny < 0 || ny >= MAP_SIZE) continue;
            if (map[nx][ny] == '#') continue;
            if (shortest[nx][ny] != -1) continue;

            q.push(make_pair(nx, ny));
            shortest[nx][ny] = shortest[x][y] + 1;
        }
    }

}

int main() {
    // �� �ʱ�ȭ
    char map[MAP_SIZE][MAP_SIZE];
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            map[i][j] = '-';
        }
    }

    // �÷��̾�� ������ ����
    map[PLAYER_x][PLAYER_y] = 'P';
    map[GOAL_x][GOAL_y] = 'G';

    // ��ֹ� �߰�
    int num_obstacles;
    cout << "��ֹ��� ������ �Է��ϼ���: ";
    cin >> num_obstacles;

    for (int i = 0; i < num_obstacles; i++) {
        int row, col;
        cout << i + 1 << "��° ��ֹ��� ��ġ�� �Է��ϼ��� (��: 2 3): ";
        cin >> row >> col;

        if (row < 0 || row >= MAP_SIZE || col < 0 || col >= MAP_SIZE) {
            cout << "�߸��� ��ġ�Դϴ�." << endl;
            i--;
            continue;
        }

        if (map[row][col] != '-') {
            cout << "�̹� �ٸ� ��ü�� ��ġ�� �ֽ��ϴ�." << endl;
            i--;
            continue;
        }

        map[row][col] = '#';
    }

    // �ִܰ�� ���ϱ�
    memset(shortest, -1, sizeof(shortest));
    bfs(map, PLAYER_x, PLAYER_y);

    // �ִܰ�ο� �ش��ϴ� ���� 'o'�� ǥ���ϱ�
    int x = GOAL_x;
    int y = GOAL_y;
    while (shortest[x][y] != 0) {
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= MAP_SIZE || ny < 0 || ny >= MAP_SIZE) continue;
            if (shortest[nx][ny] == -1) continue;
            if (shortest[nx][ny] >= shortest[x][y]) continue;

            x = nx;
            y = ny;
            if (map[x][y] != 'P' && map[x][y] != 'G') // P�� G�� ǥ������ ����
                map[x][y] = 'o';
            break;
        }
    }
    // �� ���
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}