class Solution {
  public:
  
  
    int psum(vector<int>& arr,int n,int target,int i){
        
        if(i==n){
            if(target==0){
                return 1;
            }else{
                return 0;
            }
        }
        
        return psum(arr,n,target-arr[i],i+1) + psum(arr,n,target,i+1);
    }
  
  
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int i = 0;
        int n = arr.size();
        return psum(arr,n,target,i);
        
    }
};

/*Input: arr[] = [5, 2, 3, 10, 6, 8], target = 10
Output: 3
Explanation: The subsets {5, 2, 3}, {2, 8}, and {10} sum up to the target 10.
Input: arr[] = [2, 5, 1, 4, 3], target = 10
Output: 3
Explanation: The subsets {2, 1, 4, 3}, {5, 1, 4}, and {2, 5, 3} sum up to the target 10.*/