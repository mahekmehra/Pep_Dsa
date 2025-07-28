
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

int kDistinctChars(int k, string &str)
{
    // Write your code here
    unordered_map<char,int> mp;
    int i = 0,j=0;
    int maxLen = 0;

    while(j<str.length()){

        mp[str[j]]++;

        while(mp.size()>k){

            mp[str[i]]--;
            if(mp[str[i]]==0){
                mp.erase(str[i]);
            }
            i++;
        }
        maxLen = max(maxLen,j-i+1);
        j++;
    }

    return maxLen;
  
}

/*You are given a string 'str' and an integer ‘K’. Your task is to find the length of the largest substring with at most ‘K’ distinct characters.

For example:
You are given ‘str’ = ‘abbbbbbc’ and ‘K’ = 2, then the substrings that can be formed are [‘abbbbbb’, ‘bbbbbbc’]. Hence the answer is 7.*/