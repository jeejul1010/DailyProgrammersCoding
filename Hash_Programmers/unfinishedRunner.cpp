#include "unfinishedRunner.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    int i;
    for (i = 0; i < completion.size(); i++)
    {
        if (completion[i] != participant[i])
        {
            break;
        }
    }
    answer = participant[i];
    return answer;
}

void unfinishedRunner() {
    cout << solution({ "leo", "kiki", "eden" }, { "eden", "kiki" }) << endl;
    cout << solution({ "marina", "josipa", "nikola", "vinko", "filipa" }, { "josipa", "filipa", "marina", "nikola" }) << endl;
    cout << solution({ "mislav", "stanko", "mislav", "ana" }, { "stanko", "ana", "mislav" }) << endl;
}