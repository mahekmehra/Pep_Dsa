
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {

        if(k<=1) return 0;

        int cnt = 0;
        long pro = 1;
        int n = nums.size();
        int i=0,j=0;

        while(j<n){

            pro*=nums[j];
            while(pro>=k){
                pro /= nums[i];
                i++;
            }

            cnt += (j-i+1);
            j++;
        }

        return cnt;
    }
};



/*Given an array of integers nums and an integer k, return the number of contiguous subarrays where the product of all the elements in the subarray is strictly less than k.


Example 1:

Input: nums = [10,5,2,6], k = 100
Output: 8
Explanation: The 8 subarrays that have product less than 100 are:
[10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]
Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.*/