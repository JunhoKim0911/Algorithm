#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct tree
{
    char left;
    char right;
};

int N;
char node, left_node, right_node;
struct tree arr[100];

void preOrder(char root)
{
    if (root == '.')
        return;
    else
    {
        cout << root;
        preOrder(arr[root].left);
        preOrder(arr[root].right);
    }
}

void inOrder(char root)
{
    if (root == '.')
        return;
    else
    {
        inOrder(arr[root].left);
        cout << root;
        inOrder(arr[root].right);
    }
}

void postOrder(char root)
{
    if (root == '.')
        return;
    else
    {
        postOrder(arr[root].left);
        postOrder(arr[root].right);
        cout << root;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for(int i = 0; i < N; i++)
    {
        cin >> node >> left_node >> right_node;

        arr[node].left = left_node;
        arr[node].right = right_node;
    }

    preOrder('A');
    cout << "\n";
    inOrder('A');
    cout << "\n";
    postOrder('A');
    cout << "\n";

    return 0;
}