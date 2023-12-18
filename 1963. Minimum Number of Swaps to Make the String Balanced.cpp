//what i learn - 1.if you get any pattern question then use pen and paper and find all possible case and generalize that then use appropriate DS
//                 2.In case of balancing we should first check is balaced part are playing role or not 

// method -1 
class Solution {
public:
    int minSwaps(string s) {
       int size=0;
       for(char&ch:s){
           if(ch=='['){
               size++;
           }
           else if( size!=0){
               size--;
           }
       } 
       return (size+1)/2;
    }
};

//method 2
class Solution {
public:
    int minSwaps(string s) {
        stack<char>st;
        int n=s.size();
        for(int i=0;i<n;i++){
          if(s[i]=='['){
              st.push(s[i]);
          }
          else if(!st.empty()){
              st.pop();
          }
        }
        int m=st.size();
        return (m+1)/2;
    }
};
