//���� Ʈ��
//������ �´� ��ȸ �Լ��� ����
#include <stdio.h>
#include <stdlib.h>

typedef char BTData;
typedef struct _bTreeNode //���� ����Ʈ�� ����
{
    BTData data;
    struct _bTreeNode *left;
    struct _bTreeNode *right;
} BTreeNode;
// ���� Ʈ���� �⺻ �Լ� ����
BTreeNode *MakeBTreeNode(void);           //����� ����
BTData GetData(BTreeNode *bt);            //��忡 ����� �����͸� ��ȯ
void SetData(BTreeNode *bt, BTData data); //��忡 �����͸� ����

BTreeNode *GetLeftSubTree(BTreeNode *bt);  //���� ���� Ʈ�� �ּ� �� ��ȯ
BTreeNode *GetRightSubTree(BTreeNode *bt); //������ ���� Ʈ�� �ּ� �� ��ȯ

void MakeLeftSubTree(BTreeNode *main, BTreeNode *sub); //���� ���� Ʈ���� �����Ѵ�.
void MakeRightSubTree(BTreeNode *main, BTreeNode *sub);

//��ȸ �Լ�
typedef void VisitFuncPtr(BTData data);
void PreorderTraverse(BTreeNode *bt, VisitFuncPtr action);  //����
void InorderTraverse(BTreeNode *bt, VisitFuncPtr action);   //����
void PostorderTraverse(BTreeNode *bt, VisitFuncPtr action); //����
//�Լ� �����͸� �̿��� ��� �Լ�
void DeleteTree(BTData data)
{
    printf("%c ", data);
}
int main()
{
    int N;
    scanf("%d", &N);
    getchar();
    char p, l, r;
    BTreeNode *node;
    for (int i = 0; i < N; i++)
        node[i] = MakeBTreeNode();
    for (int i = 0; i < N; i++)
    {
        scanf("%c %c %c", &p, &l, &r);
        getchar();

        SetData(node[(int)(p - 'A')], p);

        if (l != '.')
        {
            node[(int)(l - 'A')] = MakeBTreeNode();
            SetData(node[(int)(l - 'A')], l);
            MakeLeftSubTree(node[(int)(p - 'A')], node[(int)(l - 'A')]);
        }
        else
            MakeLeftSubTree(node[(int)(p - 'A')], NULL);

        if (r != '.')
        {
            SetData(node[(int)(r - 'A')], r);
            MakeRightSubTree(node[(int)(p - 'A')], node[(int)(r - 'A')]);
        }
        else
            MakeRightSubTree(node[(int)(p - 'A')], NULL);
    }
    PreorderTraverse(node[0], DeleteTree);
    printf("\n");
    InorderTraverse(node[0], DeleteTree);
    printf("\n");
    PostorderTraverse(node[0], DeleteTree);
    return 0;
}
BTreeNode *MakeBTreeNode(void) //����� ����
{
    BTreeNode *nd = (BTreeNode *)malloc(sizeof(BTreeNode));
    nd->left = NULL;
    nd->right = NULL;
    return nd;
}
BTData GetData(BTreeNode *bt) //��忡 ����� �����͸� ��ȯ
{
    return bt->data;
}
void SetData(BTreeNode *bt, BTData data) //��忡 �����͸� ����
{
    bt->data = data;
}

BTreeNode *GetLeftSubTree(BTreeNode *bt) //���� ���� Ʈ�� �ּ� �� ��ȯ
{
    return bt->left;
}
BTreeNode *GetRightSubTree(BTreeNode *bt) //������ ���� Ʈ�� �ּ� �� ��ȯ
{
    return bt->right;
}

void MakeLeftSubTree(BTreeNode *main, BTreeNode *sub) //���� ���� Ʈ���� �����Ѵ�.
{
    if (main->left != NULL)
        free(main->left);

    main->left = sub;
}
void MakeRightSubTree(BTreeNode *main, BTreeNode *sub)
{
    if (main->right != NULL)
        free(main->right);

    main->right = sub;
}
//���� Ʈ���� ��ȸ
// 1. ���� ��ȸ �Լ�
void InorderTraverse(BTreeNode *bt, VisitFuncPtr action)
{
    if (bt == NULL)
        return;

    InorderTraverse(bt->left, action);
    action(bt->data);
    InorderTraverse(bt->right, action);
}
// 2. ���� ���� �Լ�
void PreorderTraverse(BTreeNode *bt, VisitFuncPtr action)
{
    if (bt == NULL)
        return;

    action(bt->data);
    PreorderTraverse(bt->left, action);
    PreorderTraverse(bt->right, action);
}
// 3. ���� ��ȸ �Լ�
void PostorderTraverse(BTreeNode *bt, VisitFuncPtr action)
{
    if (bt == NULL)
        return;

    PostorderTraverse(bt->left, action);
    PostorderTraverse(bt->right, action);
    action(bt->data);
}