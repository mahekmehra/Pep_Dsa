class Solution {
  public:
  
    bool solve(vector<int>& arr,int sum,int n,int i){
        
        if(sum==0){
            return true;
        }
        
        if(sum<0 || i==n) return false;
        
        
        
        return solve(arr,sum-arr[i],n,i+1) || solve(arr,sum,n,i+1);
    } 
  
    bool isSubsetSum(vector<int>& arr, int sum) {
        
        // code here
        int n = arr.size();
        return solve(arr,sum,n,0);
        
    }
};

/*Input: arr[] = [3, 34, 4, 12, 5, 2], sum = 9
Output: true 
Explanation: Here there exists a subset with target sum = 9, 4+3+2 = 9.
Input: arr[] = [3, 34, 4, 12, 5, 2], sum = 30
Output: false
Explanation: There is no subset with target sum 30.*/