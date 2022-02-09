// 5639 이진 검색 트리
#include <iostream>
using namespace std;

typedef struct _node
{
    int data;
    struct _node *left;
    struct _node *right;
} Node;

Node *insert(Node *node, int data)
{
    if (node == NULL)
    {
        node = new Node();
        node->data = data;
        node->left = node->right = NULL;
    }
    else if (data <= node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);

    return node;
}

void PostOrder(Node *node)
{
    if (node->left != NULL)
        PostOrder(node->left);
    if (node->right != NULL)
        PostOrder(node->right);
    cout << node->data << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    Node *root = NULL;
    int data;
    while (cin >> data)
    {
        if (data == EOF)
            break;
        root = insert(root, data);
    }
    PostOrder(root);
}