// 1043 ������
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    //������ �ƴ� ��
    vector<int> truth(N + 1, 0);
    int knowTrue;
    cin >> knowTrue;
    for (int i = 0; i < knowTrue; i++)
    {
        int tmp;
        cin >> tmp;
        truth[tmp] = 1;
    }

    vector<vector<int>> party(M + 1, vector<int>()); //��Ƽ�� ����
    //��Ƽ�� �Է�
    int num;
    for (int i = 1; i <= M; i++)
    {
        cin >> num;
        for (int j = 0; j < num; j++)
        {
            int tmp;
            cin >> tmp;
            party[i].push_back(tmp);
        }
    }
    //������ �ƴ� ��Ƽ�� ã��
    //��Ƽ�� �߿� ������ �ƴ� �ο��� ���� ��� �ٸ� �ο� �鵵 ������ �˰� �ǹǷ� ������ �ƴ� �ο��� �߰��Ͽ� �ٽ� �˻��ؾ��Ѵ�.
    vector<int> flag(M + 1, 0); //�ѹ� ������ �ƴ� �ο��� ã�� ���� �ٽ� �˻��� �ʿ䰡 ����.
    for (int i = 1; i <= M; i++)
    {
        if (flag[i] == 1)
            continue;
        for (int j = 0; j < party[i].size(); j++)
        {
            if (truth[party[i][j]] == 1)
            {
                for (int k = 0; k < party[i].size(); k++)
                    truth[party[i][k]] = 1;
                flag[i] = 1;
                i = 0; //ó������ ��˻�
                break;
            }
        }
    }
    int cnt = 0; //������ �ƴ� ����� ���Ե� ��Ƽ�� ��
    for (int i = 1; i <= M; i++)
    {
        for (int j = 0; j < party[i].size(); j++)
        {
            if (truth[party[i][j]] == 1)
            {
                cnt++;
                break;
            }
        }
    }

    cout << M - cnt; //������ �𸣴� ��Ƽ
}