class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int result = nums[0]; 

        for(int i=0; i<nums.size(); i++){
            int curr = nums[i];

            result = max(result, curr); 

            for(int j = i+1; j<nums.size(); j++){
                curr *= nums[j];
                result = max(result,curr);
            }
            
        }
        return result;
    }
};
