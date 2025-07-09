#include<vector>

class Solution {
public:
    vector<int> countBits(int n) {

        vector<int> res(n+1);          //TC - O(NLOGN)
        for(int i=0;i<=n;i++){
            int count = 0;
            int n = i;
            while(n!=0){
                if(n&1) count++;
                n=n>>1;
            }
            res[i]=count;
        }

        return res;


        //2nd approach               TC - O(N)
        vector<int> res(n+1);
        res[0]=0;
        for(int i=1;i<=n;i++){
            if(i%2==0){
                res[i] = res[i/2];
            }else{
                res[i] = res[i/2] + 1;
            }
        }

        return res;
        
    }
};