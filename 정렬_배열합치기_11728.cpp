#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N, M, index = 0, index2 = 0;

    cin >> N >> M;

    vector<int> arr(N);
    vector<int> arr2(M);
    
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < M; i++)
    {
        cin >> arr2[i];
    }

    sort(arr.begin(), arr.end());
    sort(arr2.begin(), arr2.end());
    
    while (index < N && index2 < M)
    {
        if (arr[index] < arr2[index2])
            cout << arr[index++] << " ";
        else if (arr[index] > arr2[index2])
            cout << arr2[index2++] << " ";
        else
            cout << arr[index++] << " ";
    }
    
    if (index >= N && index2 < M)
    {
        for (int i = index2; i < M; i++)
            cout << arr2[i] << " ";
    }
    else if (index < N && index2 >= M)
    {
        for (int i = index; i < N; i++)
            cout << arr[i] << " ";
    }
    
    return 0;
}