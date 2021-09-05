#include <iostream>
#include <string>
#include <vector>

using namespace std;

int minStep = 50;

void dfs(string begin, string target, vector<string> words, vector<bool> visited, int step) {
    if (step == words.size() && begin != target)
    {
        minStep = 0;
        return;
    }
    if (begin == target)
    {
        if (step < minStep)
        {
            minStep = step;
        }
        return;
    }

    for (int i = 0; i < begin.length(); i++)
    {
        if (begin[i] != target[i])
        {
            for (int j = 0; j < words.size(); j++)
            {
                if (!visited[j] && words[j].substr(0, i) == begin.substr(0, i) && words[j].substr(i + 1) == begin.substr(i + 1))
                {
                    visited[j] = true;
                    dfs(words[j], target, words, visited, step + 1);
                }
            }
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;

    vector<bool> visited(words.size(), false);

    dfs(begin, target, words, visited, 0);

    answer = minStep;
    return answer;
}

void wordChange()
{
    cout << solution("hit", "cog", { "hot", "dot", "dog", "lot", "log", "cog" }) << endl;
    cout << solution("hit", "cog", { "hot", "dot", "dog", "lot", "log" }) << endl;
}