class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;                   //TC - O(LOGN)
        while(n!=0){
            if(n&1){
                count++;
            }
            n=n>>1;
        }
        return count;

        //Brian Kermighan's algorithm
        int count = 0;
        while(n>0){
            n= n&(n-1);
            count++;
        }
        return count;

        //3rd method
        int count = 0;
        while(n!=0){
            if(n%2){
                count++;
            }
            n=n/2;
        }
        return count;

        
    }

    
};