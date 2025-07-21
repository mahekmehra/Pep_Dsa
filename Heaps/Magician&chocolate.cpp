
#include <bits/stdc++.h> 
int maximumChocolates(vector<int> &arr, int k){
    // Write your code here.

    int ans = 0;
    priority_queue<int> pq;
    for(auto &i : arr){
        pq.push(i);
    }

    while(k>0){
        int x = pq.top();
        pq.pop();
        ans+=x;
        x/=2;
        pq.push(x);
        k--;
    }

    return ans;
}

/*In a magic event, you are given ‘N’ bags, each bag containing ‘A[i]’ chocolates. In one unit of time, you can choose any bag ‘i’ and eat all the chocolates ‘A[i]’ in that bag and then the magician fills the ith bag with floor(‘A[i]’ / 2) chocolates. Your task is to find the maximum number of chocolate you can eat in ‘K’ units of time.

Since the answer could be large, return answer modulo 10^9 + 7.

For Example:
For the array [ 4, 7, 9, 10] and ‘k’=2
In the first step, we can choose the last bag. So the answer will be 10 and the array will be [4, 7, 9, 5].
In the second step, we can choose the second last bag. So the answer will be 19 and the array will be [4, 7, 4, 5].
So the final output will be 19.*/