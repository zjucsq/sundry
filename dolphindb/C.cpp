#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    set<int> nums;
public:
    int mrank(int x) {
        nums.insert(x);
        return distance(nums.begin(), nums.lower_bound(x)) + 1;
    }
};

int main()
{
    Solution s;
    cout << s.mrank(1) << endl;
    cout << s.mrank(3) << endl;
    cout << s.mrank(2) << endl;
    cout << s.mrank(3) << endl;
    cout << s.mrank(4) << endl;
    return 0;
}