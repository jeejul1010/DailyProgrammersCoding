#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include "functionDevelopment.h"

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    for (int i = 0; i < progresses.size(); i++)
    {
        double temp = (100 - double(progresses[i])) / speeds[i];
        if (temp > int(temp))
        {
            temp += 1;
        }
        q.push(int(temp));
    }

    int count;
    while (!q.empty())
    {
        count = 0;
        int getFront = q.front();
        q.pop();
        count++;
        while (!q.empty() && getFront >= q.front())
        {
            count++;
            q.pop();
        }
        answer.push_back(count);
    }
    return answer;
}

void functionDevelopment()
{
    //vector<int> sol = solution({ 93, 30, 55 }, { 1, 30, 5 });
    vector<int> sol = solution({ 95, 90, 99, 99, 80, 99 }, { 1, 1, 1, 1, 1, 1 });
    cout << '[';
    for (int i = 0; i < sol.size(); i++)
    {
        cout << sol[i];
        if (i != sol.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << ']';
}