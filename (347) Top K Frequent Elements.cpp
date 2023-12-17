class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // put all in umap
        int n=nums.size();
        unordered_map<int,int>unorderedmap;
         for(auto x:nums){
             unorderedmap[x]=unorderedmap[x]+1;
         }
        // for store output 
         vector<int>ans;
         // to get top k element 
         priority_queue<pair<int,int>>pq;
         for(auto it=unorderedmap.begin();it!=unorderedmap.end();it++){
             pq.push(make_pair(it->second,it->first));
             if(pq.size()> unorderedmap.size()-k){
                 ans.push_back(pq.top().second);
                 pq.pop();
             }
         }
         return ans;
    }
};
/*from line 13 to 20 create a priority_queue of pair int and int type then (itereate through each element's pointer) not element of
map hence to acces the member of each map element(key,value) we use -> arrow now we push  the pair of second and firt of map using make_pair 
and it will sorted itself we give a check if element exceed or equal to kth element just push second into ans vector and pop that so that another 
first of pair will come and we will able to push that  again. */ 
