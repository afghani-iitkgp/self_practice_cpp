#include <bits/stdc++.h>
using namespace std;


int main()
{
    vector<int> nums;
    nums = {2, 6, 5, 9, 10};

    sort(nums.begin(), nums.end(), greater<int>());

    for (int i : nums) {
        cout<<i<<'\n';
    }
}