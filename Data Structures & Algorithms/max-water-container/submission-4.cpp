class Solution {
public:
    int maxArea(vector<int>& heights) {
        int res =0; 
        int l = 0; 
        int r = heights.size() - 1;

        while(l<r){
            int area = min(heights[r], heights[l]) * (r-l);
            res = max(area, res);
            
            if(heights[l] <= heights[r]) {
                l++; 
            }else {
                r--;
            }
        }
        return res;
    }
};
