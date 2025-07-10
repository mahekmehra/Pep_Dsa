 Maximum Element After Decreasing and Rearranging

 class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {

        sort(arr.begin(),arr.end());
        if(arr[0]!=1){
            arr[0]=1;
        }

        int n = arr.size();

        for(int i=1;i<n;i++){
            if(abs(arr[i]-arr[i-1])>1){
                arr[i]=arr[i-1]+1;
            }
        }

        return arr[n-1];  
    }
};

/*Example 1:

Input: arr = [2,2,1,2,1]
Output: 2
Explanation: 
We can satisfy the conditions by rearranging arr so it becomes [1,2,2,2,1].
The largest element in arr is 2.
Example 2:

Input: arr = [100,1,1000]
Output: 3
Explanation: 
One possible way to satisfy the conditions is by doing the following:
1. Rearrange arr so it becomes [1,100,1000].
2. Decrease the value of the second element to 2.
3. Decrease the value of the third element to 3.
Now arr = [1,2,3], which satisfies the conditions.
The largest element in arr is 3.
*/