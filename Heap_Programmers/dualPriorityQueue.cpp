#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;


vector<int> solution(vector<string> operations) {
    vector<int> answer;
    
    deque<int> pq;

    string temp;
    int num = 0;
    for (int i = 0; i < operations.size(); i++)
    {
        if (operations[i][0] == 'I')
        {
            temp = "";
            for (int j = 2; j < operations[i].length(); j++)
            {
                temp += operations[i][j];
            }
            num = stoi(temp);

            pq.push_back(num);

        }
        else if (operations[i][2] == '1')
        {
            if (!pq.empty())
            {
                sort(pq.begin(), pq.end());
                pq.pop_back();
            }
        }
        else
        {
            if (!pq.empty())
            {
                sort(pq.begin(), pq.end());
                pq.pop_front();
            }
            
        }
    }

    int max = 0, min = 0;

    if (!pq.empty())
    {
        sort(pq.begin(), pq.end());
        max = pq.back();
        min = pq.front();
    }

    answer.push_back(max);
    answer.push_back(min);

    return answer;
}

void dualPriorityQueue()
{
    //vector<int> sol = solution({ "I 16","D 1" });
    vector<int> sol = solution({ "I 7","I 5","I -5","D -1" });
    cout << '[';
    for (int i = 0; i < sol.size(); i++)
    {
        cout << sol[i];
        if (i != sol.size() - 1)
        {
            cout << ',';
        }
        else
        {
            cout << ']' << endl;
        }
    }
}