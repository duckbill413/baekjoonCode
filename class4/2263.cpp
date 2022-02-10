// 2263 트리의 순회
#include <iostream>
#include <vector>
using namespace std;

vector<int> inOrder(100001, 0);
vector<int> postOrder(100001, 0);
vector<int> Idx(100001, 0);

void PreOrder(int inS, int inE, int postS, int postE);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> inOrder[i];
    for (int i = 1; i <= N; i++)
        cin >> postOrder[i];
    for (int i = 1; i <= N; i++)
        Idx[inOrder[i]] = i;

    PreOrder(1, N, 1, N);
}

void PreOrder(int inS, int inE, int postS, int postE)
{
    if (inS > inE || postS > postE)
        return;

    int root = postOrder[postE];
    cout << root << " ";
    PreOrder(inS, Idx[root] - 1, postS, postS + Idx[root] - inS - 1);
    PreOrder(Idx[root] + 1, inE, postS + Idx[root] - inS, postE - 1);
}