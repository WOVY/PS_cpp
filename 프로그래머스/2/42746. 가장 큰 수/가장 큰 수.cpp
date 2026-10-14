#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string a, string b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> str_n;
    for (int num : numbers)
        str_n.push_back(to_string(num));
    
    sort(str_n.begin(), str_n.end(), cmp);
    
    if (str_n[0] == "0")
        return "0";
    for (string num : str_n)
        answer += num;
    
    return answer;
}