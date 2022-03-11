// 1197 최소 스패닝 트리
// 중요도 !!!!
/* 최소 스패닝 트리 <= 크루스칼 알고리즘
1. 모든 간선들의 가중치를 오름차순으로 정렬한다.
2. 가중치가 가장 작으며 스패닝 트리에 사이클이 없을 경우에만 선택한다.
3. 2에서 선택한 간선이 연결하려는 2개의 노드가 아직 서로 연결되지 않은 상태라면, 2개의 노드를 서로 연결한다.
4. 위의 과정을 반복한다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> P; // node1, node2

int ifSame(int, int, vector<int> &);
int find(int, vector<int> &);
void unionNode(int, int, vector<int> &);
int total;
int main()
{
    int V, E;
    cin >> V >> E;
    vector<pair<int, P>> line;
    for (int i = 0; i < E; i++)
    {
        int s, e, d;
        cin >> s >> e >> d;
        line.push_back({d, {s, e}});
    }

    // 가중치가 최소가 되도록 트리를 만들어야 하므로 정렬 필요
    sort(line.begin(), line.end()); // 가중치에 대하여 정렬
    vector<int> parent(V + 1, 0);   // 부모 노드,, 부모 노드가 같으면 연결된 상태
    for (int i = 1; i <= V; i++)
        parent[i] = i;

    for (int i = 0; i < E; i++)
    {
        // 각 노드에 대하여 부모 노드가 같지 않을 경우 연결
        if (!ifSame(line[i].second.first, line[i].second.second, parent))
        {
            unionNode(line[i].second.first, line[i].second.second, parent);
            total += line[i].first;
        }
    }

    cout << total;
}
int ifSame(int s, int e, vector<int> &parent)
{
    s = find(s, parent);
    e = find(e, parent);
    if (s == e)
        return true;
    else
        return false;
}
int find(int n, vector<int> &parent)
{
    if (parent[n] == n)
        return n;
    else
        return parent[n] = find(parent[n], parent);
}
void unionNode(int n1, int n2, vector<int> &parent)
{
    n1 = find(n1, parent);
    n2 = find(n2, parent);
    if (n1 != n2)
        parent[n2] = n1;
}