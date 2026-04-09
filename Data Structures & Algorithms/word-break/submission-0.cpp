class Solution {
public:
    bool f(const string& s, const vector<string>& wordDict, int i, vector<int>& dp){
        if(i == s.length()){
            return true;
        }
        if(dp[i] != -1) return dp[i];

        for(int j = 0; j < wordDict.size(); j++){
            string w = wordDict[j];
            if( i+ w.length() <= s.length() && s.substr(i, w.length()) == w){
                if(f(s,wordDict, i+w.length(), dp)){
                    return dp[i] = 1;
                }
            }
        }
        return dp[i]=0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int>dp (s.length(), -1);
        return f(s, wordDict, 0, dp);
    }
};
