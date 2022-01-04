#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int>& a, vector<int>& b) //오름차순 정렬
{
    if (a[0] == b[0])
    {
        return a[1] < b[1];
    }
    return a[0] < b[0];
}

int solution(vector<vector<int>> routes) {
    int answer = 0;

    sort(routes.begin(), routes.end(), compare);

    int idx = 0;
    int maxOverlap = 0;
    int startOverlap = 0;
    int leaveOverlap = 0;

    while (idx<routes.size()-1)
    {
        maxOverlap = routes[idx++][1];
        startOverlap = routes[idx][0];

        while (idx<routes.size()-1 && startOverlap <= maxOverlap)
        {
            leaveOverlap = routes[idx][1];
            if (leaveOverlap < maxOverlap)
            {
                maxOverlap = leaveOverlap;
            }

            idx++;
            
            startOverlap = routes[idx][0];
        }

        answer++;
    }

    if (startOverlap > maxOverlap)
    {
        answer++;
    }
    return answer;
}

void speedCamera()
{
    cout << solution({ { -20, -15 }, { -14, -5 }, { -18, -13 }, { -5, -3 } }) << endl;
}