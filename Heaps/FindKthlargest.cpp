
int findKthLargest(vector<int>& nums, int k) {

        priority_queue<int> pq;
        for(auto i : nums){
            pq.push(i);
        }
        
        k=k-1;

        while(k>0){
            pq.pop();
            k--;
        }

        return pq.top();
        
}

//shorter approach

int findKthLargest(vector<int>& nums, int k) {

        priority_queue<int, vector<int>,greater<int>> pq;
        for(auto i : nums){
            pq.push(i);
            if(pq.size()>k){
                pq.pop();
            }
        }
        
        return pq.top();
        
}

/*Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?

 

Example 1:

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5*/