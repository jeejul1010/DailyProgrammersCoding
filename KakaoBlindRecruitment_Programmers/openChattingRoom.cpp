#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;

    vector<vector<string>> input;
    unordered_map<string, string> um;

    for (int i = 0; i < record.size(); i++)
    {
        vector<string> temp;
        input.push_back(temp);

        string str = record[i];
        istringstream ss(str);
        string stringBuffer;

        while (getline(ss, stringBuffer, ' '))
        {
            input[i].push_back(stringBuffer);
        }

        if (input[i][0] != "Leave")
        {
            um[input[i][1]] = input[i][2];
        }
    }

    string tmp;
    for (int i = 0; i < record.size(); i++)
    {
        if (input[i][0] == "Change")
        {
            continue;
        }

        if (input[i][0] == "Enter")
        {
            tmp = um[input[i][1]] + "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.";
        }
        else
        {
            tmp = um[input[i][1]] + "´ÔÀÌ ³ª°¬½À´Ï´Ù.";
        }

        answer.push_back(tmp);
    }
    
    /*for (auto elem : um)
    {
        cout << elem.first << " " << elem.second << endl;
    }*/

    /*for (int i = 0; i < record.size(); i++)
    {
        for (int j = 0; j < input[i].size(); j++)
        {
            cout << input[i][j] << endl;
        }
    }*/
    return answer;
}

void openChattingRoom()
{
    vector<string> sol = solution({ "Enter uid1234 Muzi", "Enter uid4567 Prodo", "Leave uid1234", "Enter uid1234 Prodo", "Change uid4567 Ryan" });
    //solution({ "Enter uid1234 Muzi", "Enter uid4567 Prodo", "Leave uid1234", "Enter uid1234 Prodo", "Change uid4567 Ryan" });
    //vector<string> sol = { "Enter uid1234 Muzi", "Enter uid4567 Prodo", "Leave uid1234", "Enter uid1234 Prodo", "Change uid4567 Ryan" };

    for (auto el : sol)
    {
        cout << el << endl;
    }
}