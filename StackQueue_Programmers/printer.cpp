#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include "printer.h"

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;

    queue<pair<int, int>> q;
    priority_queue<int> pq;
    for (int i = 0; i < priorities.size(); i++)
    {
        q.push(make_pair(i, priorities[i]));
        pq.push(priorities[i]);
    }

    while (!q.empty())
    {
        if (q.front().second == pq.top())
        {
            answer++;
            if (q.front().first == location)
            {
                return answer;
            }
            q.pop();
            pq.pop();
        }
        else
        {
            q.push(q.front());
            q.pop();
        }
    }
}

void printer()
{
    cout << solution({ 1, 1, 9, 1, 1, 1 }, 0) << endl;
}