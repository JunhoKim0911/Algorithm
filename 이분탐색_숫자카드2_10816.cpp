#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N, M, check;

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
        
        cout << upper_bound(arr.begin(), arr.end(), check) - lower_bound(arr.begin(), arr.end(), check) << " ";
    }

    return 0;
}