#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> nums)
{
    unordered_map<int, int> m;
    int cnt = 0;
    
    for (int num: nums) {
        m[num]++;
        cnt++;
    }
    if ((cnt / 2) >= m.size())
        return m.size();
    else {
        return cnt / 2;
    }
}