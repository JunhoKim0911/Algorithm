#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX = 1001;

int N, M, V;
int map[MAX][MAX];
bool visit[MAX];
queue<int> q;

void dfs(int v)
{
    cout << v << " ";

    for (int i = 1; i <= N; i++)
    {
        if (map[v][i] == 1 && visit[i] == false)
        {
            visit[i] = true;
            dfs(i);
        }
    }
}

void bfs(int v)
{
    q.push(v);

    while (!q.empty())
    {
        int temp = q.front();
        q.pop();

        cout << temp << " ";

        for (int i = 1; i <= N; i++)
        {
            if (map[temp][i] == 1 && visit[i] == false)
            {
                visit[i] = true;
                q.push(i);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> V;

    int from, to;

    for (int i = 0; i < M; i++)
    {
        cin >> from >> to;

        map[from][to] = 1;
        map[to][from] = 1;
    }

    visit[V] = true;
    dfs(V);
    cout << "\n";

    memset(visit, false, sizeof(visit));
    visit[V] = true;
    bfs(V);
    cout << "\n";

    return 0;
}