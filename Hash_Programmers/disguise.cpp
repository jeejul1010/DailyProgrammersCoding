#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;

    unordered_map<string, int> um;

    for (int i = 0; i < clothes.size(); i++)
    {
        if (um.find(clothes[i][1]) != um.end())
        {
            um[clothes[i][1]]++;
        }
        else
        {
            um[clothes[i][1]] = 1;
        }
    }

    for (auto elem : um)
    {
        answer *= (elem.second + 1);
    }
    answer -= 1;

    return answer;
}

void disguise()
{
    cout << solution({ {"yellowhat", "headgear"}, {"bluesunglasses", "eyewear"}, {"green_turban", "headgear"} }) << endl;
    cout << solution({ {"crowmask", "face"}, {"bluesunglasses", "face"}, {"smoky_makeup", "face"} }) << endl;
}