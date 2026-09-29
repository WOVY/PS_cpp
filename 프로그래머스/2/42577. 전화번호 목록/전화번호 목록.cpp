#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book) {
    unordered_map<string, int> m;
    for (string number : phone_book) {
        m[number] = 1;
    }
    
    for (string number : phone_book) {
        string prefix = "";
        
        for (int i = 0; i < number.length(); i++) {
            prefix += number[i];
            
            if ((m.count(prefix) > 0) && (prefix != number)) {
                return false;
            }
        }
    }
    return true;
}