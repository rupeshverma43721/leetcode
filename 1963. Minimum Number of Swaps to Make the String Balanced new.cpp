class Solution {
public:
    int minSwaps(string s) {
      int n=s.size();
      int count=0; int maxt=0;
      for(int i=0;i<n;i++){
          if(s[i]==']'){
              count++;
          }
          else{
              count--;
          }
          maxt=max(count,maxt);
      }
      return (maxt+1)/2;   // odd hoga to even pair no./2 step  + 1 single step == odd me +1 /2 
                          // in case of even even/2=(even+1)/2
                         // (maxt+1)/2 kiya kyuki 1/2 =0 dega but 1 bracket ke liye ek swaping karna padega  
    }
};
