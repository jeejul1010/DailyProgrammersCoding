#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool cmp(vector<int>& a, vector<int>& b)
{
    return a[0] < b[0];
}

struct comp {
    bool operator()(vector<int>& a, vector<int>& b)
    {
        return a[1] > b[1];
    }
};

int solution(vector<vector<int>> jobs) {
    sort(jobs.begin(), jobs.end(), cmp);

    int answer = 0, time = 0, index = 0;

    priority_queue < vector<int>, vector<vector<int>>, comp> pq;

    while (index<jobs.size() || !pq.empty())
    {
        if (index<jobs.size() && time >= jobs[index][0])
        {
            pq.push(jobs[index++]);
            continue;

        }

        if (!pq.empty())
        {
            time += pq.top()[1];
            answer += time - pq.top()[0];
            pq.pop();
        }
        else
        {
            time = jobs[index][0];
        }
    }
    
    return answer/jobs.size();
}

void diskController()
{
    cout << solution({ {0,3}, {1,9}, {2,6} }) << endl;
}