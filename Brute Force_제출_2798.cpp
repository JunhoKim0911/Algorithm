#include <iostream>

using namespace std;

#define MAX_LENGTH 100

int N, M;
int arr[MAX_LENGTH];

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    int sum = 0;
    int max = 0;

    for (int i = 0; i < N - 2; i++)
    {
        sum = arr[i];

        if (sum >= M)
            continue;

        for (int j = i + 1; j < N - 1; j++)
        {
            sum += arr[j];

            if (sum >= M)
            {
                sum -= arr[j];
                continue;
            }

            for (int k = j + 1; k < N; k++)
            {
                sum += arr[k];

                if (sum <= M)
                {
                    if (max < sum)
                    {
                        max = sum;
                    }
                }

                sum -= arr[k];
            }

            sum -= arr[j];
        }
    }

    cout << max;

    return 0;
}