class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {

        int sum = 0;
        sort(costs.begin(),costs.end());
        int n = costs.size();
        for(int i=0;i<n;i++){
            if(costs[i]<=coins){
                sum++;
                coins-=costs[i];
            }

            if(coins==0){
                break;
            }
        }

        return sum;
        
    }
};


/*Input: costs = [1,3,2,4,1], coins = 7
Output: 4
Explanation: The boy can buy ice cream bars at indices 0,1,2,4 for a total price of 1 + 3 + 2 + 1 = 7.*/