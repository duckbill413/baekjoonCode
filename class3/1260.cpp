// dfs bfs 알고리즘(깊이 우선 탐색, 너비 우선 탐색)
// vector와 sort의 사용
// c++ class deque의 구현
#include <iostream>
#include <vector>
#include <algorithm>
#define TRUE 1
#define FALSE 0
using namespace std;
typedef int Data;
typedef struct _node
{
    Data data;
    struct _node *next;
    struct _node *prev;
} Node;

class Deque
{
private:
    Node *head;
    Node *tail;
    int size;

public:
    // Deque ?? ??
    Deque()
    {
        head = tail = NULL;
        size = 0;
    }
    int empty();
    int getSize();
    void push_front(Data data);
    void push_back(Data data);
    Data pop_front();
    Data pop_back();

    Data peek_front();
    Data peek_back();
};

void dfs(Data start, vector<Data> *data, bool *visited);
void bfs(Data start, vector<Data> *data, bool *visited);
bool compare(Data left, Data right);
int main()
{
    int N, M, V;
    cin >> N >> M >> V;
    vector<Data> *data = new vector<Data>[N + 1];
    bool *visited = new bool[N + 1](); // N+1개 선언과 함께 false로 초기화

    while (M--)
    {
        Data A, B;
        cin >> A >> B;
        //정점은 양방향 연결이다.
        data[A].push_back(B);
        data[B].push_back(A);
    }
    //정점 번호가 작은 것부터 방문하므로 vector을 정렬하여 준다.
    for (int i = 1; i <= N; i++)
        if (data[i].size() != 0)
            sort(data[i].begin(), data[i].end(), compare);
    /* sort(==qsort)
    오름차순 : sort(data[i].begin(), data[i].end());
    내림차순 : sort(data[i].begin(), data[i].end(), greater<Data>());
    */
    dfs(V, data, visited);
    cout << endl;

    // bfs실행을 위하여 visit을 초기화
    delete[] visited;
    visited = new bool[N + 1]();
    bfs(V, data, visited);

    delete[] visited;
    delete[] data;
}
bool compare(Data left, Data right)
{
    //오름차순 정렬 이므로 right가 left보다 클때 참이다.
    if (left < right)
        return true;
    else
        return false;
}
void dfs(Data start, vector<Data> *data, bool *visited)
{
    visited[start] = true;
    cout << start << " ";
    for (int i = 0; i < data[start].size(); i++)
    {
        Data next = data[start][i];
        if (!visited[next])
            dfs(next, data, visited);
    }
}
void bfs(Data start, vector<Data> *data, bool *visited)
{
    Deque q;
    q.push_back(start);
    visited[start] = true;

    while (!q.empty())
    {
        Data next = q.pop_front();
        cout << next << " ";
        for (int i = 0; i < data[next].size(); i++)
        {
            Data nextToNext = data[next][i];
            if (!visited[nextToNext])
            {
                q.push_back(nextToNext);
                visited[nextToNext] = true;
            }
        }
    }
}
int Deque::getSize()
{
    return size;
}
int Deque::empty()
{
    if (head == NULL)
        return TRUE;
    else
        return FALSE;
}

void Deque::push_front(Data data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = head;

    if (empty())
        tail = newNode;
    else
        head->prev = newNode;

    newNode->prev = NULL;
    head = newNode;
    size++;
}
void Deque::push_back(Data data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = tail;

    if (empty())
        head = newNode;
    else
        tail->next = newNode;

    newNode->next = NULL;
    tail = newNode;
    size++;
}
Data Deque::pop_front()
{
    if (empty())
        return -1;
    Node *rnode = head;
    Data rdata = rnode->data;
    head = head->next;
    free(rnode);

    if (head == NULL)
        tail = NULL;
    else
        head->prev = NULL;
    size--;
    return rdata;
}
Data Deque::pop_back()
{
    if (empty())
        return -1;
    Node *rnode = tail;
    Data rdata = rnode->data;

    tail = tail->prev;
    free(rnode);
    if (tail == NULL)
        head = NULL;
    else
        tail->next = NULL;
    size--;
    return rdata;
}

Data Deque::peek_front()
{
    if (empty())
        return -1;

    return head->data;
}
Data Deque::peek_back()
{
    if (empty())
        return -1;

    return tail->data;
}