#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> node[32001];
int inLine[32001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, A, B;

    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        cin >> A >> B;

        inLine[B]++;
        node[A].push_back(B);
    }

    queue<int> zero;

    for (int i = 1; i <= N; i++)
    {
        if (inLine[i] == 0)
        {
            zero.push(i);
        }
    }

    while (!zero.empty())
    {
        int vertex = zero.front();
        
        zero.pop();

        cout << vertex << " ";

        for (int i = 0; i < node[vertex].size(); i++)
        {
            if (--inLine[node[vertex][i]] == 0)
            {
                zero.push(node[vertex][i]);
            }
        }
    }

    return 0;
}