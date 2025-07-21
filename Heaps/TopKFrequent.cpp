
//approach 1 (with maps)

vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int,int> mp;
        for(auto &i : nums){
            mp[i]++;
        }

        vector<pair<int,int>> ans(mp.begin(),mp.end());

        auto comparator = [&](pair<int,int> a,pair<int,int> b){
            return a.second>b.second;
        };
        

        sort(ans.begin(),ans.end(),comparator);
        vector<int> res;

        for(int i=0;i<k;i++){
            res.push_back(ans[i].first);
        }

        return res;
 
}

//approach 2 (with heaps)

        unordered_map<int,int> mp;      //(Max Heaps)
        for(auto &i : nums){
            mp[i]++;
        }

        priority_queue<pair<int,int>> pq;

        for(auto i : mp){
            pq.push({i.second,i.first});
        }


        vector<int> res;
        while(k--){
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
 
//approach 3 (with min heap)

        unordered_map<int,int> mp;
        for(auto &i : nums){
            mp[i]++;
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        for(auto i : mp){
            pq.push({i.second,i.first});
            if(pq.size()>k){
                pq.pop();
            }
        }


        vector<int> res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;


/*Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Input: nums = [1,2,3,2,1,1,1,5,6,1,5,5,3]
Output: [1,5]*/