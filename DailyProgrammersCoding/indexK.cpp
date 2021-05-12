#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "indexK.h"

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for (int i = 0; i < commands.size(); i++)
    {
        vector<int> comptr = commands[i];
        vector<int> temp;

        for (int j = comptr[0] - 1; j < comptr[1]; j++)
        {
            temp.push_back(array[j]);
        }

        sort(temp.begin(), temp.end());

        answer.push_back(temp[comptr[2] - 1]);

    }

    return answer;
}

void indexKMain()
{
    vector<int> array = { 1,5,2,6,3,7,4 };
    vector<vector<int>> commands = { {2,5,3},{4,4,1},{1,7,3} };
    vector<int> sol = solution(array, commands);

    cout << "[";
    for (int i = 0; i < sol.size(); i++)
    {
        cout << sol[i];
        if (i != sol.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}