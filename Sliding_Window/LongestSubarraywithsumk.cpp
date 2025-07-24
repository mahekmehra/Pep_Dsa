int longestSubarrayWithSumK(vector<int> arr, long long k) {
    // Write your code here
    int ans = 0;
    long long sum = 0;
    int n = arr.size();
    int i=0,j=0;

    while(j<n){

        sum+=arr[j];
        while(sum>k){
            sum-=arr[i];
            i++;
        }
        if(sum==k){
            ans = max(ans,j-i+1);
        }
        j++;
    }

    return ans;

}

/*You are given an array 'a' of size 'n' and an integer 'k'.



Find the length of the longest subarray of 'a' whose sum is equal to 'k'.



Example :
Input: ‘n’ = 7 ‘k’ = 3
‘a’ = [1, 2, 3, 1, 1, 1, 1]

Output: 3

Explanation: Subarrays whose sum = ‘3’ are:

[1, 2], [3], [1, 1, 1] and [1, 1, 1]

Here, the length of the longest subarray is 3, which is our final answer.*/