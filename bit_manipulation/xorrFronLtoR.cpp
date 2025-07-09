class Solution {
  public:
  
    int solve(int n){                        //TC - O(1)   because normal approach of O(n) will give TLE
        
        if(n%4==1) return 1;                 //solve(3) - 1^2^3
        
        if(n%4==2) return n+1;               //solve(8) - 1^2^3^4^5^6^7^8
        
        if(n%4==3) return 0;
        
        if(n%4==0) return n;
    }
  
  
    int findXOR(int l, int r) {
        // complete the function here
        return (solve(l-1) ^ solve(r));     // let l = 4 and r = 8
        
    }
};

/*Input: 
L = 4, R = 8 
Output:
8 
Explanation:
4 ^ 5 ^ 6 ^ 7 ^ 8 = 8
*/