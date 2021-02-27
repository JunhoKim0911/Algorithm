#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, M, check, bottom, top, point;
    bool find;

    cin >> N;

    vector<int> arr(N);

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    cin >> M;

    for (int i = 0; i < M; i++)
    {
        cin >> check;
        
        bottom = 0;
        top = N - 1;

        find = false;

        while (bottom <= top)
        {
            point = (bottom + top) / 2;

            if (arr[point] == check)
            {
                find = true;
                break;
            }
            else if (arr[point] < check)
            {
                bottom = point + 1;
            }
            else
            {
                top = point - 1;
            }
        }

        if (find)
            cout << "1 ";
        else
            cout << "0 ";
    }

    return 0;
}