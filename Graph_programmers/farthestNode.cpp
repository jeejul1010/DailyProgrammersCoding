#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include "farthestNode.h"

using namespace std;

bool cmp(const int& a, const int& b)
{
    return a > b;
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<bool> visited(n + 1, false);
    vector<vector<int>> neighbors(n + 1);
    vector<int> distance(n + 1);

    for (int i = 0; i < edge.size(); i++)
    {
        neighbors[edge[i][0]].push_back(edge[i][1]);
        neighbors[edge[i][1]].push_back(edge[i][0]);
    }

    queue<int> q;

    q.push(1);
    visited[1] = true;
    distance[1] = 0;

    while (!q.empty())
    {
        int getFront = q.front();
        q.pop();
        for (int i = 0; i < neighbors[getFront].size(); i++)
        {
            if (!visited[neighbors[getFront][i]])
            {
                q.push(neighbors[getFront][i]);
                visited[neighbors[getFront][i]] = true;
                distance[neighbors[getFront][i]] = distance[getFront] + 1;
            }
        }
    }

    sort(distance.begin(), distance.end(), cmp);
    answer++;
    for (int i = 1; i < distance.size(); i++)
    {
        if (distance[0] == distance[i])
        {
            answer++;
        }
    }

    return answer;
}

void farthestNode()
{
    cout << solution(6, { {3,6} ,{4,3},{3, 2},{1,3},{1,2},{2,4},{5,2} }) << endl;
}