class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>umap;
        vector<vector<int>>result;
        for(int i=0;i<n;i++){
            int freq=umap[nums[i]];
            if(freq==result.size()){
                result.push_back({}); // add one more row
            }
            result[freq].push_back(nums[i]);
            umap[nums[i]]++;
        }
        return result;
    }
};
