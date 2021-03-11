#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

#define MAX_COUNT 10001

using namespace std;

int N, total, end_node;
vector<pair<int, int>> tree[MAX_COUNT];
bool visit[MAX_COUNT] = { false, };

void dfs(int start, int weight)
{
    if (visit[start])
        return;

    visit[start] = true;

    if (total < weight)
    {
        total = weight;
        end_node = start;
    }

    for (int i = 0; i < tree[start].size(); i++)
    {
        dfs(tree[start][i].first, weight + tree[start][i].second);
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    int parent, child, weight;

    for(int i = 0; i < N - 1; i++)
    {
        cin >> parent >> child >> weight;

        tree[parent].push_back(make_pair(child, weight));
        tree[child].push_back(make_pair(parent, weight));
    }

    total = 0;
    dfs(1, 0);

    total = 0;
    memset(visit, false, sizeof(visit));
    dfs(end_node, 0);

    cout << total;

    return 0;
}