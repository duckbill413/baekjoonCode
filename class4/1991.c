//이진 트리
//목적에 맞는 순회 함수의 구현
#include <stdio.h>
#include <stdlib.h>

typedef char BTData;
typedef struct _bTreeNode //연결 리스트로 구성
{
    BTData data;
    struct _bTreeNode *left;
    struct _bTreeNode *right;
} BTreeNode;
// 이진 트리의 기본 함수 구성
BTreeNode *MakeBTreeNode(void);           //노드의 생성
BTData GetData(BTreeNode *bt);            //노드에 저장된 데이터를 반환
void SetData(BTreeNode *bt, BTData data); //노드에 데이터를 저장

BTreeNode *GetLeftSubTree(BTreeNode *bt);  //왼쪽 서브 트리 주소 값 반환
BTreeNode *GetRightSubTree(BTreeNode *bt); //오른쪽 서브 트리 주소 값 반환

void MakeLeftSubTree(BTreeNode *main, BTreeNode *sub); //왼쪽 서브 트리를 연결한다.
void MakeRightSubTree(BTreeNode *main, BTreeNode *sub);

//순회 함수
typedef void VisitFuncPtr(BTData data);
void PreorderTraverse(BTreeNode *bt, VisitFuncPtr action);  //전위
void InorderTraverse(BTreeNode *bt, VisitFuncPtr action);   //중위
void PostorderTraverse(BTreeNode *bt, VisitFuncPtr action); //후위
//함수 포인터를 이용한 출력 함수
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
BTreeNode *MakeBTreeNode(void) //노드의 생성
{
    BTreeNode *nd = (BTreeNode *)malloc(sizeof(BTreeNode));
    nd->left = NULL;
    nd->right = NULL;
    return nd;
}
BTData GetData(BTreeNode *bt) //노드에 저장된 데이터를 반환
{
    return bt->data;
}
void SetData(BTreeNode *bt, BTData data) //노드에 데이터를 저장
{
    bt->data = data;
}

BTreeNode *GetLeftSubTree(BTreeNode *bt) //왼쪽 서브 트리 주소 값 반환
{
    return bt->left;
}
BTreeNode *GetRightSubTree(BTreeNode *bt) //오른쪽 서브 트리 주소 값 반환
{
    return bt->right;
}

void MakeLeftSubTree(BTreeNode *main, BTreeNode *sub) //왼쪽 서브 트리를 연결한다.
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
//이진 트리의 순회
// 1. 중위 순회 함수
void InorderTraverse(BTreeNode *bt, VisitFuncPtr action)
{
    if (bt == NULL)
        return;

    InorderTraverse(bt->left, action);
    action(bt->data);
    InorderTraverse(bt->right, action);
}
// 2. 전위 순위 함수
void PreorderTraverse(BTreeNode *bt, VisitFuncPtr action)
{
    if (bt == NULL)
        return;

    action(bt->data);
    PreorderTraverse(bt->left, action);
    PreorderTraverse(bt->right, action);
}
// 3. 후위 순회 함수
void PostorderTraverse(BTreeNode *bt, VisitFuncPtr action)
{
    if (bt == NULL)
        return;

    PostorderTraverse(bt->left, action);
    PostorderTraverse(bt->right, action);
    action(bt->data);
}