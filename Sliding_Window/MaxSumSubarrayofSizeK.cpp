
class Solution {
  public:
    int maximumSumSubarray(vector<int>& arr, int k) {
        // code here
        
        long ans = INT_MIN;
        long sum = 0;
        int n = arr.size();
        int i=0,j=0;
        while(j<n){
            
            sum+=arr[j];
            
            if(j-i+1<k) j++;
            
            else if(j-i+1==k){
                ans = max(sum,ans);
                sum -= arr[i];
                i++;
                j++;
            }
        }
        
        return ans;
    }
};

/*Given an array of integers arr[]  and a number k. Return the maximum sum of a subarray of size k.

Note: A subarray is a contiguous part of any given array.

Examples:

Input: arr[] = [100, 200, 300, 400] , k = 2
Output: 700
Explanation: arr3  + arr4 = 700, which is maximum.*/