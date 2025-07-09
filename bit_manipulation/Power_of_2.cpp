class Solution {
public:
    bool isPowerOfTwo(int n) {    //(n & n-1) == 0 then n is a power of 2

         
        if(n<=0) return false; 
        long long k = n-1;
        if(n & k){
            return false;
        }else{
            return true;
        }
        
    }
};

class Solution {
public:
    bool isPowerOfTwo(int n) {

        return (n>0) && ((n & (n-1))==0);
        
    }
};