#include<iostream>
using namespace std;


class Solution {
  public:
    void bitManipulation(int num, int i) {
        // your code here
        if((num & (1<<(i-1)))==0){
            cout<<0;
        }else{
            cout<<1;
        }
        int k = num | (1<<(i-1));
        cout<<" "<<k;
        k = num & (~(1<<(i-1)));
        cout<<" "<<k;
    }
};

class Solution {
  public:
    void bitManipulation(int num, int i) {
        // your code here
        int n =(num>>(i-1)) & 1;
        int k = num | (1<<(i-1));
        int m = num & (~(1<<(i-1)));
        cout<<n<<" "<<k<<" "<<m;
    }
};

/*Input: 70 3
Output: 1 70 66
Explanation: Bit at the 3rd position from LSB is 1. (1 0 0 0 1 1 0) .The value of the given number after setting the 3rd bit is 70. The value of the given number after clearing 3rd bit is 66. (1 0 0 0 0 1 0)*/