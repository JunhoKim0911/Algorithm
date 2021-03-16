#include <iostream>
#include <vector>
#include <queue>

#define MAX 20001
#define INF 987654321

using namespace std;

int V, E, K;
int dist_arr[MAX];
vector<pair<int, int>> vertex[MAX];

void Input_value()
{
    cin >> V >> E >> K;

    int from, to, value;

    for (int i = 0; i < E; i++)
    {
        cin >> from >> to >> value;

        vertex[from].push_back(make_pair(to, value));
    }

    for (int i = 1; i <= V; i++)
    {
        dist_arr[i] = INF;
    }
}

void Dijkstra()
{
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, K));
    dist_arr[K] = 0;

    while (!pq.empty())
    {
        int node_value = -pq.top().first;
        int node_num = pq.top().second;
        pq.pop();

        for (int i = 0; i < vertex[node_num].size(); i++)
        {
            int next_node = vertex[node_num][i].first;
            int dist_value = vertex[node_num][i].second;

            if (dist_arr[next_node] > node_value + dist_value)
            {
                dist_arr[next_node] = node_value + dist_value;
                pq.push(make_pair(-dist_arr[next_node], next_node));
            }
        }
    }

    for (int i = 1; i <= V; i++)
    {
        if (dist_arr[i] == INF)
            cout << "INF\n";
        else
            cout << dist_arr[i] << "\n";
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input_value();
    Dijkstra();

    return 0;
}