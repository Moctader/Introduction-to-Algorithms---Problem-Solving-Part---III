#include <iostream>
#include <vector>

using namespace std;

int maxPoints(vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }

    int n = nums.size();
    vector<long long> dp(100001, 0);
    vector<long long> count(100001, 0);

    for (int i = 0; i < n; i++) {
        count[nums[i]]++;
    }

    dp[1] = count[1];

    for (int i = 2; i <= 100000; i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + count[i] * i);
    }

    return dp[100000];
}

int main() {
    int n;
    cout << "Enter the number of elements in the sequence: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the sequence elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int maxScore = maxPoints(nums);
    cout << "Maximum points: " << maxScore << endl;

    return 0;
}
