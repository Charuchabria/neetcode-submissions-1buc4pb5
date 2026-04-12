class Solution {
public:
    int f(int l, int r, vector<int>& nums, int target){
        if(l>r) return -1;
        int m = l + (r-l)/2;

        if(nums[m] == target) return m;
        if(nums[m] > target)  return f(l, m-1, nums, target);
        if(nums[m]<target) return f(m+ 1, r, nums, target);
    }
    int search(vector<int>& nums, int target) {
        return f(0,nums.size()-1,nums,target);
    }
};
