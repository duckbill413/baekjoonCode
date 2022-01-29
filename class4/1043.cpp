// 1043 거짓말
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

    //진실을 아는 자
    vector<int> truth(N + 1, 0);
    int knowTrue;
    cin >> knowTrue;
    for (int i = 0; i < knowTrue; i++)
    {
        int tmp;
        cin >> tmp;
        truth[tmp] = 1;
    }

    vector<vector<int>> party(M + 1, vector<int>()); //파티원 벡터
    //파티원 입력
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
    //진실을 아는 파티원 찾기
    //파티원 중에 진실을 아는 인원이 있을 경우 다른 인원 들도 진실을 알게 되므로 진실을 아는 인원에 추가하여 다시 검색해야한다.
    vector<int> flag(M + 1, 0); //한번 진실을 아는 인원을 찾은 경우는 다시 검색할 필요가 없다.
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
                i = 0; //처음부터 재검색
                break;
            }
        }
    }
    int cnt = 0; //진실을 아는 사람이 포함된 파티의 수
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

    cout << M - cnt; //진실을 모르는 파티
}