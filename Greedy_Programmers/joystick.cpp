#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string name) {
    string temp = "";
    for (int i = 0; i < name.length(); i++)
    {
        temp += 'A';
    }

    int nextIndex = 0;
    int answer = 0;
    int tmp;
    int cand1, cand2;
    while (name != temp)
    {
        tmp = name[nextIndex] - 'A';
        if (tmp > 13)
        {
            tmp = 26 - tmp;
        }
        answer += tmp;
        name[nextIndex] = 'A';

        if (name == temp)
        {
            break;
        }

        int dist1 = 1;
        int dist2 = 1;
        cand1 = (nextIndex + 1) % name.length();
        cand2 = ((nextIndex + name.length()) - 1) % name.length();
        while (name[cand1] == 'A')
        {
            cand1 = (cand1 + 1) % name.length();
            dist1++;
        }
        while (name[cand2] == 'A')
        {
            cand2 = ((cand2 + name.length()) - 1) % name.length();
            dist2++;
        }
        if (dist1 > dist2)
        {
            answer += dist2;
            nextIndex = cand2;
        }
        else
        {
            answer += dist1;
            nextIndex = cand1;
        }
    }

    return answer;
}

void joystick()
{
    cout << solution("JEROEN") << endl;
    cout << solution("JAN") << endl;
}