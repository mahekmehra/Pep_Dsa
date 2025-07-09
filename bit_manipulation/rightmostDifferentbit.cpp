
class Solution {
  public:
    int posOfRightMostDiffBit(int m, int n) {
        //  code here
        int k = 1;
        int num = m^n;
        
        while(num!=0){
            if(num&1)  return k;
            k++;
            num=num>>1;
        }
        
        return -1;
    }
};




/*Input: m = 11, n = 9
Output: 2
Explanation: Binary representation of the given numbers are: 1011 and 1001, 2nd bit from right is different.*/