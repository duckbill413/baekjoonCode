// dfs bfs �˰���(���� �켱 Ž��, �ʺ� �켱 Ž��)
// vector�� sort�� ���
// c++ class deque�� ����
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
    bool *visited = new bool[N + 1](); // N+1�� ����� �Բ� false�� �ʱ�ȭ

    while (M--)
    {
        Data A, B;
        cin >> A >> B;
        //������ ����� �����̴�.
        data[A].push_back(B);
        data[B].push_back(A);
    }
    //���� ��ȣ�� ���� �ͺ��� �湮�ϹǷ� vector�� �����Ͽ� �ش�.
    for (int i = 1; i <= N; i++)
        if (data[i].size() != 0)
            sort(data[i].begin(), data[i].end(), compare);
    /* sort(==qsort)
    �������� : sort(data[i].begin(), data[i].end());
    �������� : sort(data[i].begin(), data[i].end(), greater<Data>());
    */
    dfs(V, data, visited);
    cout << endl;

    // bfs������ ���Ͽ� visit�� �ʱ�ȭ
    delete[] visited;
    visited = new bool[N + 1]();
    bfs(V, data, visited);

    delete[] visited;
    delete[] data;
}
bool compare(Data left, Data right)
{
    //�������� ���� �̹Ƿ� right�� left���� Ŭ�� ���̴�.
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