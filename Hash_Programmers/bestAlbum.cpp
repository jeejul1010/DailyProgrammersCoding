#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <utility> //pair header

using namespace std;

bool cmp(const pair<string, int>& a, const pair<string, int>& b)
{
    return a.second > b.second;
}

bool compare(const pair<int, int>& a, const pair<int, int>& b)
{
    if (a.first > b.first)
    {
        return true;
    }
    else if (a.first == b.first)
    {
        if (a.second < b.second)
        {
            return true;
        }
    }
    return false;
   
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    map<string, int> m;
    map<string, vector<pair<int, int>>> songInfo;
    vector<int> answer;
    
    for (int i = 0; i < genres.size(); i++)
    {
        m[genres[i]] += plays[i];
        songInfo[genres[i]].push_back(make_pair(plays[i], i));
    }

    vector<pair<string, int>> genreCount(m.begin(), m.end());
    sort(genreCount.begin(), genreCount.end(), cmp);

    for (auto i : genreCount)
    {
        sort(songInfo[i.first].begin(), songInfo[i.first].end(), compare);
        answer.push_back(songInfo[i.first][0].second);
        if (songInfo[i.first].size() >= 2 )
        {
            answer.push_back(songInfo[i.first][1].second);
        }
    }

    return answer;
}

void bestAlbum()
{
    vector<int> answer = solution({ "classic", "pop", "classic", "classic", "pop" }, { 500, 600, 150, 800, 2500 });
    for (auto i : answer)
    {
        cout << i << endl;
    }
}