class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // start with initally impossible amount 
        vector<int> dp(amount+1, amount +1);
        dp[0] = 0;
        for(int i =1; i<=amount; i++){
            //try all the coins
            for(int j =0; j<coins.size(); j++){
                if(coins[j] <= i){
                    dp[i] = min(dp[i], dp[i-coins[j]]+1); 
                    //one coin plus best way to make rest of amm.
                }
            }
        }
        if (dp[amount] > amount) {
            return -1;
        } else {
            return dp[amount];
        }
    }
};
