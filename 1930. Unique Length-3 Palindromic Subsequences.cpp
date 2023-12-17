// what i learned- how to find the leftmost index , right most  index  of a char in given string  in two way 
// method -1 
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<int>letters;
        int n=s.size();
        int result=0;
        for(int i=0;i<n;i++){
            letters.insert(s[i]);
        }
         for(auto &letter:letters){
             int left_index=-1;
             int right_index=-1;
            for(int i=0;i<n;i++){
            if(s[i]==letter){
                if(left_index==-1){
                    left_index=i;
                }
                right_index=i;
            }
         }
         unordered_set<int>st;
         for(int middle=left_index+1;middle<=right_index-1;middle++){
               st.insert(s[middle]);
         }
         result=result+st.size();
             }
         return result;
    }
};



// method -2 
class Solution {
public:
    int countPalindromicSubsequence(string s) {
         int n=s.size();
         int result=0;
         vector<pair<int,int>>indices(26,{-1,-1});
         for(int i=0;i<n;i++){
             char ch=s[i];
              int idx=ch-'a';
              if(indices[idx].first==-1){
                  indices[idx].first=i;
              }
              indices[idx].second=i; // ye c yani 2 index of vector pe first and second index store karega

             }
             for(int i=0;i<26;i++)
         {
              int left_index=indices[i].first;
             int right_index=indices[i].second;
             if(left_index==-1){
                 continue;
             }
         unordered_set<int>st;
         for(int middle=left_index+1;middle<=right_index-1;middle++){
               st.insert(s[middle]);
         }
         result=result+st.size();
             }
         return result;
    }
};

             
