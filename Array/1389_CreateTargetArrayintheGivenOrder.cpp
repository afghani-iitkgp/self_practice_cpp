#include <bits/stdc++.h>
using namespace std;

vector<int> createTargetArray(vector<int>& nums, vector<int>& index) 
{
    // Input: nums = [0,1,2,3,4], index = [0,1,2,2,1], Output: [0,4,1,3,2]
    vector<int> target;
    int n = nums.size();
    if (nums.size() == index.size()) {
        for (int i=0; i<n; i++) {
            if (i <= target.size()) {
                index[i] = 4;
            }
            
        }
    }    
}

int main()
{
    vector<int> nums {};
    vector<int> index {};
    vector<int> target = createTargetArray(nums, index);
    
    for (int i=0; i<target.size(); i++)
        cout<<i;
}
