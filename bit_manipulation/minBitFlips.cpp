class Solution {
public:
    int minBitFlips(int start, int goal) {

        int count = 0;
        int xorr = start^goal;
        while(xorr!=0){
            if(xorr&1) count++;     /*or
            xorr = xorr>>1;         xorr&=(xorr-1);
                                    count++;*/
        }
        return count;


        //2nd approach

        int a = start;
        int b = goal;
        int count =0;
        while((a>0) || (b>0)){
            if((a&1) != (b&1)){
                count++;
            }
            a=a>>1;
            b=b>>1;
        }

        return count;
        
    }
};

/*Input: start = 10, goal = 7
Output: 3
Explanation: The binary representation of 10 and 7 are 1010 and 0111 respectively. We can convert 10 to 7 in 3 steps:
- Flip the first bit from the right: 1010 -> 1011.
- Flip the third bit from the right: 1011 -> 1111.
- Flip the fourth bit from the right: 1111 -> 0111.
It can be shown we cannot convert 10 to 7 in less than 3 steps. Hence, we return 3.
*/