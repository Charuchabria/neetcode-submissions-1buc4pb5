class Solution {
public:
    int f(int n, vector<int>& shan){

    if(n<=2) return n;
    if(shan[n] != -1) return shan[n];
    return shan[n] = f(n-1, shan) + f(n-2,shan); 

    }

    int climbStairs(int n) {
        vector<int>shan(n+1, -1);
        return f(n, shan);
    }
};
