class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {


        int suff = 0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        int n = g.size();
        int m = s.size();

        int i=0,j=0;
        while(i<n && j<m){
            if(s[j]>=g[i]){
                suff++;
                j++;
                i++;
            }else{
                j++;
            }
        }

        return suff;
    }
};

/*Input: g = [1,2,3], s = [1,1]
Output: 1
Explanation: You have 3 children and 2 cookies. The greed factors of 3 children are 1, 2, 3. 
And even though you have 2 cookies, since their size is both 1, you could only make the child whose greed factor is 1 content.
You need to output 1. */