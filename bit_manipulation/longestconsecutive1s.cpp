class Solution {
  public:
    int maxConsecutiveOnes(int n) {
        // code here
        int ans = 0;
        int count = 0;
        while(n>0){
            if((n&1)==1){
                count++;
            }else{
                count=0;
            }
            ans = max(ans,count);
            n=n>>1;
        }
        return ans;
    }
};

/*Input: n = 14
Output: 3
Explanation: Binary representation of 14 is 1110, in which 111 is the longest consecutive set bits of length is 3.*/
