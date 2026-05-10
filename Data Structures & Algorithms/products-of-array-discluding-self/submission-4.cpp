class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>res(nums.size());
        int prod = 1;
        int zerocount = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++) {

            if(nums[i] == 0) {
                zerocount++;
            }
            else {
                prod *= nums[i];
            }
        }

        for(int i =0; i<n; i++){
            if(zerocount > 1){
                res[i] = 0;
            }
            else if(zerocount == 1){
                if(nums[i] == 0)
                    res[i] = prod;
                else
                    res[i]=0;
            }
            else{
                res[i] = prod/nums[i];
            }
        }
        return res;
    }
};
