//중요도!!!!!
//백준 1655 가운데를 말해요
#include <iostream>
#include <algorithm>
#define HEAP_LEN 100010
using namespace std;

typedef int Data;
int N, Max_Heap_Idx, Min_Heap_Idx;

void HPush(Data data, bool T, Data Max_Heap[], Data Min_Heap[])
{
    if (T == true)
    {
        int Idx = ++Max_Heap_Idx;
        Max_Heap[Idx] = data;
        while ((Idx != 1) && (data > Max_Heap[Idx / 2]))
        {
            swap(Max_Heap[Idx], Max_Heap[Idx / 2]);
            Idx /= 2;
        }
    }
    else
    {
        int Idx = ++Min_Heap_Idx;
        Min_Heap[Idx] = data;
        while ((Idx != 1) && (data < Min_Heap[Idx / 2]))
        {
            swap(Min_Heap[Idx], Min_Heap[Idx / 2]);
            Idx /= 2;
        }
    }
}

Data HPop(bool T, Data Max_Heap[], Data Min_Heap[])
{
    if (T == true)
    {
        Data Result = Max_Heap[1];
        Max_Heap[1] = Max_Heap[Max_Heap_Idx--];

        int Parent = 1;
        int Child;
        while (1)
        {
            Child = Parent * 2;
            if (Child + 1 <= Max_Heap_Idx && Max_Heap[Child] < Max_Heap[Child + 1])
                Child++;
            if (Child > Max_Heap_Idx || Max_Heap[Child] < Max_Heap[Parent])
                break;
            swap(Max_Heap[Child], Max_Heap[Parent]);
            Parent = Child;
        }
        return Result;
    }
    else
    {
        Data Result = Min_Heap[1];
        Min_Heap[1] = Min_Heap[Min_Heap_Idx--];

        int Parent = 1;
        int Child;
        while (1)
        {
            Child = Parent * 2;
            if (Child + 1 <= Min_Heap_Idx && Min_Heap[Child] > Min_Heap[Child + 1])
                Child++;
            if (Child > Min_Heap_Idx || Min_Heap[Child] > Min_Heap[Parent])
                break;
            swap(Min_Heap[Child], Min_Heap[Parent]);
            Parent = Child;
        }
        return Result;
    }
}
int getSize(bool T)
{
    if (T == true)
        return Max_Heap_Idx;
    return Min_Heap_Idx;
}
int getTop(bool T, Data Max_Heap[], Data Min_Heap[])
{
    if (T == true)
        return Max_Heap[1];
    else
        return Min_Heap[1];
}
void Input(Data *Arr)
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> Arr[i];
}
bool HIsEmpty(bool T) s
{
    if (T == true)
    {
        if (Max_Heap_Idx == 0)
            return true;
        else
            return false;
    }
    else
    {
        if (Min_Heap_Idx == 0)
            return true;
        else
            return false;
    }
}
void Solution(Data *Arr, Data Max_Heap[], Data Min_Heap[])
{
    for (int i = 0; i < N; i++)
    {
        int Max_Heap_Size = getSize(true);
        int Min_Heap_Size = getSize(false);

        if (Max_Heap_Size > Min_Heap_Size)
            HPush(Arr[i], false, Max_Heap, Min_Heap);
        else
            HPush(Arr[i], true, Max_Heap, Min_Heap);

        if (HIsEmpty(true) == false && HIsEmpty(false) == false)
        {
            if (getTop(true, Max_Heap, Min_Heap) > getTop(false, Max_Heap, Min_Heap))
            {
                int Max_Value = HPop(true, Max_Heap, Min_Heap);
                int Min_Value = HPop(false, Max_Heap, Min_Heap);

                HPush(Min_Value, true, Max_Heap, Min_Heap);
                HPush(Max_Value, false, Max_Heap, Min_Heap);
            }
        }

        cout << getTop(true, Max_Heap, Min_Heap) << endl;
    }
}
void Solve(Data *Arr, Data Max_Heap[], Data Min_Heap[])
{
    Input(Arr);
    Solution(Arr, Max_Heap, Min_Heap);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Data Arr[HEAP_LEN];
    Data Max_Heap[HEAP_LEN];
    Data Min_Heap[HEAP_LEN];
    Solve(Arr, Max_Heap, Min_Heap);
    return 0;
}