vector<int> mergeKArrays(vector<vector<int>> arr, int K) {
        // code here
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<K;i++){
            for(int j=0;j<K;j++){
                pq.push(arr[i][j]);
            }
        }
        
        vector<int> res;
        while(!pq.empty()){
            res.push_back(pq.top());
            pq.pop();
        }
        
        return res;
}

/*Input: k = 4, arr[][]={{1,2,3,4},{2,2,3,4},{5,5,6,6},{7,8,9,9}}
Output: 1 2 2 2 3 3 4 4 5 5 6 6 7 8 9 9 
Explanation: Above test case has 4 sorted arrays of size 4, 4, 4, 4 arr[][] = [[1, 2, 2, 2], [3, 3, 4, 4], [5, 5, 6, 6], [7, 8, 9, 9 ]]. The merged list will be [1, 2, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 8, 9, 9].*/