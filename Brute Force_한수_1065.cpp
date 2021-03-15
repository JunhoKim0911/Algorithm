#include <iostream>

using namespace std;

int N;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    int answer = 0;

    for (int i = 1; i <= N; i++)
    {
        if (i < 100)
            answer++;
        else
        {
            int first = i / 100;
            int second = (i % 100) / 10;
            int third = (i % 100) % 10;

            if ((first - second) == (second - third))
                answer++;
        }
    }

    cout << answer;

    return 0;
}