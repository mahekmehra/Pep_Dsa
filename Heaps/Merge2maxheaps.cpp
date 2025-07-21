class Solution {
  public:
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        priority_queue<int> pq;
        for(auto &i : a){
            pq.push(i);
        }
        for(auto &i : b){
            pq.push(i);
        }
        
        vector<int> res;
        while(!pq.empty()){
            res.push_back(pq.top());
            pq.pop();
        }
        
        return res;
    }
};

/*Given two binary max heaps as arrays, merge the given heaps to form a new max heap.

 

Example 1:

Input  : 
n = 4 m = 3
a[] = {10, 5, 6, 2}, 
b[] = {12, 7, 9}
Output : 
{12, 10, 9, 2, 5, 7, 6}*/