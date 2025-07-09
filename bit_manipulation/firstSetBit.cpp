
class Solution {
  public:
    int getFirstSetBit(int n) {
        // code here
        int k = 1;
        while(n!=0){
            if((n&1)==1){
                break;
            }
            k++;
            n=n>>1;

        }
        
        return k;
    }
};

/*Input: n = 18
Output: 2
Explanation: Binary representation of 18 is 010010,the first set bit from the right side is at position 2.*/