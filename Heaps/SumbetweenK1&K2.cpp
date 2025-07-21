int small(long long A[], long long N, long long K) {
        // code here
        priority_queue<long long> pq;
        for(int i=0;i<N;i++){
            pq.push(A[i]);
            if(pq.size()>K){
                pq.pop();
            }
        }
        
        return pq.top();
}
  
long long sumBetweenTwoKth(long long A[], long long N, long long K1, long long K2) {
        // Your code goes here
        long long k1 = small(A,N,K1);
        long long k2 = small(A,N,K2);
        
        long long sum = 0;
        for(int i=0;i<N;i++){
            if(A[i]>k1 && A[i]<k2){
                sum+=A[i];
            }
        }
        return sum;
        
}



/*Given an array A[] of N positive integers and two positive integers K1 and K2. Find the sum of all elements between K1th and K2th smallest elements of the array. It may be assumed that (1 <= k1 < k2 <= n).

Example 1:

Input:
N  = 7
A[] = {20, 8, 22, 4, 12, 10, 14}
K1 = 3, K2 = 6
Output:
26
Explanation:
3rd smallest element is 10
6th smallest element is 20
Element between 10 and 20 
12,14. Their sum = 26.*/