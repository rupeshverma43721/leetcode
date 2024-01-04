class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            int tofind=target-nums[i];
            for(int j=0;j<n;j++){
                if(tofind==nums[j] && j!=i){
                    ans.push_back(i);
                    ans.push_back(j);
                    break;
                }
            }
            if(ans.size()==2){
                break;
            }
        }
        return ans;
    }
};


// updated 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>ans;
        unordered_map<int,int>umap;
        for(int i=0;i<n;i++){
            auto itr=umap.find(target-nums[i]);
            if(itr!=umap.end()){
                ans.push_back(itr->second);
                ans.push_back(i);
                break;
            }
            umap[nums[i]]=i;
        }
        return ans;
    }
};
