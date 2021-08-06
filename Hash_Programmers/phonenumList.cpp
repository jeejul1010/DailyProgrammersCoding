#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "phonenumList.h"

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;

    sort(phone_book.begin(), phone_book.end());

    int i;
    for (i = 0; i < phone_book.size() - 1; i++)
    {
        string temp = phone_book[i];
        string temp2 = phone_book[i + 1];
        int j;
        for (j = 0; j < phone_book[i].length(); j++)
        {
            if (temp[j] != temp2[j])
            {
                break;
            }
        }
        if (j == phone_book[i].length())
        {
            return false;
        }
    }
    return answer;
}

void phonenumList()
{
    cout << (solution({ "119", "97674223", "1195524421" })? "true" : "false") << endl;

    cout << boolalpha;
    cout << solution({ "123", "456", "789" }) << endl;
    cout << solution({ "12", "123", "1235", "567", "88" }) << endl;
}