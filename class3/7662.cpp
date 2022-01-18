//중요도!!!!!
//이중 우선순위 큐
// multiset의 사용
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <sstream>
#include <set>
using namespace std;

vector<string> DoublePriQue(vector<string> order)
{
    vector<string> answer;
    multiset<int> tree;

    for (int i = 0; i < order.size(); i++)
    {
        stringstream stream;
        stream.str(order[i]);
        string tmp;
        stream >> tmp;
        if (tmp == "I")
        {
            stream >> tmp;
            tree.insert(stoi(tmp));
        }
        else if (tmp == "D" && !tree.empty())
        {
            stream >> tmp;
            if (tmp == "1")
                tree.erase(--tree.end());
            else if (tmp == "-1")
                tree.erase(tree.begin());
        }
    }
    if (tree.empty())
        answer.push_back("EMPTY");
    else
    {
        answer.push_back(to_string(*(--tree.end())));
        answer.push_back(to_string(*tree.begin()));
    }

    return answer;
}
 
int main()
{
    int T, K;
    string tmp;
    vector<string> order, answer;

    cin >> T;
    while (T--)
    {
        cin >> K;
        cin.ignore();
        while (K--)
        {
            getline(cin, tmp);
            order.push_back(tmp);
        }
        answer = DoublePriQue(order);
        for (int i = 0; i < answer.size(); i++)
        {
            cout << answer[i] << " ";
        }
        cout << endl;
        order.clear();
        answer.clear();
    }

    return 0;
}
