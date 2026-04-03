class Solution {
public:
/*
recursion:
if(shan[i] != 1) return shan[i]
rob this then go i+2
rob= num[i], solve(i+2, num, shan)
skip this then go i+1
skip= solve(i+1, num, shan)
max(rob,skip)
*/
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n==0) return 0;
        if (n==1) return nums[0]; 

        vector<int> dp(n);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for( int i =2; i<n; i++){
            //max (rob curr aur -2 house, skip curr)
            dp[i] = max(nums[i]+ dp[i-2], dp[i-1]);
        }
        return dp[n-1];
    }
};


