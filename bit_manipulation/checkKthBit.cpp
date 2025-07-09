class Solution {
  public:
    bool checkKthBit(int n, int k) {
        //  code here
        return (n & (1<<k));
        // return ((n>>k) & 1); ye bhi kar sakte hai
    }
};

/*Input: n = 4, k = 0
Output: false
Explanation: Binary representation of 4 is 100, in which 0th index bit from LSB is not set. So, return false.
*/