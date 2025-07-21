#include<bits/stdc++.h>


int getKthLargest(vector<int> &arr, int k)            //TC - O(n^2(logk))
{
	//	Write your code here.
	priority_queue<int,vector<int>,greater<int>> pq;

	int n = arr.size();
    for(int i=0;i<n;i++){
		int sum = 0;
		for(int j=i;j<n;j++){
			sum+=arr[j];
			pq.push(sum);
			if(pq.size()>k){
				pq.pop();
			}
		}
	}

	return pq.top();

}


/*Input = [3,-2,5], k = 2
Output= 5*/