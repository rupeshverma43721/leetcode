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
