class Solution {
  public:
    int setBit(int n) {

        return (n | (n+1));
       
        //2nd approach
        int k = 0;
		int m = n;
		while(m!=0){
		    if((m&1)==0){
		        break;
		    }
		    k++;
		    m=m>>1;
		}
		
		return (n | (1<<k));
    }

    
};

/*Input: n = 6
Output: 7
Explanation: The binary representation of 6 is 110. After setting right most bit it becomes 111 which is 7.*/