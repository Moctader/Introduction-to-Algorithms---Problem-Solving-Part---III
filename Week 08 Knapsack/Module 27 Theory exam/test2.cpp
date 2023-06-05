#include<iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

int robUtil(vector<int>& nums, int start, int end, unordered_map<string, int>& memo) {
    if (start > end) {
        return 0;
    }
    
    string key = to_string(start) + "-" + to_string(end);
    
    if (memo.count(key)) {
        return memo[key];
    }
    
    int rob = nums[start] + robUtil(nums, start + 2, end - 2, memo);
    int notRob = robUtil(nums, start + 1, end, memo);
    
    int maxAmount = max(rob, notRob);
    memo[key] = maxAmount;
    
    return maxAmount;
}

int rob(vector<int>& nums) {
    int n = nums.size();
    
    if (n == 1) {
        return nums[0]; // Only one house, so we can rob it
    } else if (n == 2) {
        return max(nums[0], nums[1]); // Choose the house with more money
    }
    
    unordered_map<string, int> memo;
    
    // Calculate the maximum amount of money that can be robbed
    int maxAmount = max(robUtil(nums, 0, n - 2, memo), robUtil(nums, 1, n - 1, memo));
    
    return maxAmount;
}

int main()
{
    vector<int>nums;
    for(int i=0; i<5; i++)
    {
        int in;
        cin>>in;
        nums.push_back(in);
    }
    cout<<rob(nums);
    return 0;
}