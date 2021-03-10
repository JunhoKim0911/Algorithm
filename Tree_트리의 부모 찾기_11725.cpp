#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 100001;

int N, node1, node2;
bool visit[MAX];
int parent[MAX];
vector<int> tree[MAX];

void parentNode(int node)
{
    visit[node] = true;

    for (int i = 0; i < tree[node].size(); i++)
    {
        int nextNode = tree[node][i];

        if (!visit[nextNode])
        {
            parent[nextNode] = node;
            parentNode(nextNode);
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for(int i = 1; i < N; i++)
    {
        cin >> node1 >> node2;

        tree[node1].push_back(node2);
        tree[node2].push_back(node1);
    }

    parentNode(1);

    for (int i = 2; i <= N; i++)
    {
        cout << parent[i] << "\n";
    }

    return 0;
}