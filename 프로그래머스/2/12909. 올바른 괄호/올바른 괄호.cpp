#include <string>
#include <iostream>
#include <vector>

using namespace std;

bool solution(string s)
{
    vector <char> list;
    list.push_back(s[0]);
    list.push_back(s[1]);
    
    for (int i = 2; i < s.length(); i++) {
        if (list[list.size() - 1] == ')'&& list[list.size() - 2] == '(') {
            list.pop_back();
            list.pop_back();
        }
        
        list.push_back(s[i]);
    }
    
    if (list[list.size() - 1] == ')'&& list[list.size() - 2] == '(') {
            list.pop_back();
            list.pop_back();
    }
    
    if (list.empty())
        return true;
    else
        return false;
}