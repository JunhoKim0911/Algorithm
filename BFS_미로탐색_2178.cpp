#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
int map[100][100];
int mapCnt[100][100];
bool visit[100][100];
int direction[4][2] = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };
queue<pair<int, int>> q;

void bfs(int x, int y)
{
    visit[x][y] = false;
    q.push(make_pair(x, y));

    while (!q.empty())
    {
        int tempX = q.front().first;
        int tempY = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nextX = tempX + direction[i][0];
            int nextY = tempY + direction[i][1];

            if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= M)
            {
                continue;
            }

            if (map[nextX][nextY] == 1 && visit[nextX][nextY])
            {
                visit[nextX][nextY] = false;
                mapCnt[nextX][nextY] = mapCnt[tempX][tempY] + 1;
                q.push(make_pair(nextX, nextY));
            }
        }
    }
}

int main()
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        string input;
        cin >> input;

        for (int j = 0; j < input.length(); j++)
        {
            map[i][j] = input[j] - '0';

            if (map[i][j] == 1)
                visit[i][j] = true;
            else
                visit[i][j] = false;
        }
    }

    mapCnt[0][0] = 1;

    bfs(0, 0);

    cout << mapCnt[N - 1][M - 1] << "\n";

    return 0;
}