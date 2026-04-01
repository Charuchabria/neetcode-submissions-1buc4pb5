class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        int n = nums.size();

        for(int i = 0; i<n; i++){
            freq[nums[i]]++;
        }

        vector<pair<int, int>>vec;
        for(auto it : freq){
            vec.push_back({it.first, it.second});
        }
        sort(vec.begin(), vec.end(),[](pair<int,int>& a, pair<int,int>& b){
            return a.second > b.second;
        });

        vector<int> result;
        for(int i=0; i<k; i++){
            result.push_back(vec[i].first);
        }
        return result;
    }
};
