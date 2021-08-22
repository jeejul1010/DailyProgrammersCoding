#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include "network.h"

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> visited(n, false);

    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            answer++;
            s.push(i);
            visited[i] = true;
            while (!s.empty())
            {
                int top = s.top();
                s.pop();
                for (int j = 0; j < computers[top].size(); j++)
                {
                    if (!visited[j] && computers[top][j]==1)
                    {
                        s.push(j);
                        visited[j] = true;
                    }
                }
            }
        }
    }

    return answer;
}

void network()
{
    cout << solution(3, { {1,1,0},{1,1,0},{0,0,1} }) << endl;
    cout << solution(3, { {1,1,0},{1,1,1},{0,1,1} }) << endl;
}