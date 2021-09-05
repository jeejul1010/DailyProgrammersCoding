#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

bool cmp(vector<string> a, vector<string> b) {
    if (a[0] < b[0]) {
        return true;
    }
    else if (a[0] == b[0]) {
        if (a[1] < b[1]) {
            return true;
        }
    }
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;

    vector<bool> visited(tickets.size(), false);

    sort(tickets.begin(), tickets.end(), cmp);

    string find = "ICN";
    answer.push_back(find);

    stack<int> s;

    vector<int> temp;
    bool deadEnd = false;
    int start = 0;
    int finish = tickets.size();
    while (s.size() != tickets.size())
    {
        deadEnd = true;
        for (int i = start; i < finish; i++)
        {
            if (!visited[i] && tickets[i][0] == find) {
                visited[i] = true;
                find = tickets[i][1];
                if (tickets[i][0] < find)
                {
                    start = i + 1;
                    finish = tickets.size();
                }
                else
                {
                    start = 0;
                    finish = i;
                }
                answer.push_back(find);
                s.push(i);
                for (int j = 0; j < temp.size(); j++) {
                    visited[temp[j]] = false;
                }
                deadEnd = false;
                break;
            }
        }
        if (deadEnd) {
            temp.push_back(s.top());
            answer.pop_back();
            find = answer[answer.size() - 1];
            s.pop();
        }
    }

    return answer;
}

void travelPath() {
    //vector<string> answer = solution({ {"ICN", "JFK"}, {"HND", "IAD"}, {"JFK", "HND"} });
    vector<string> answer = solution({ {"ICN", "SFO"}, {"ICN", "ATL"}, {"SFO", "ATL"}, {"ATL", "ICN"},{"ATL", "SFO"} });
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << endl;
    }
}