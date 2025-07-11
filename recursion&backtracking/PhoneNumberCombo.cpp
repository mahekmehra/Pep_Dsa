
void solve(vector<string> &res,string &temp,string &digits,unordered_map<char,string> &mp,int idx){

        if(idx>=digits.size()){
            res.push_back(temp);
            return;
        }

        char ch = digits[idx];
        string str = mp[ch];

        for(int i=0;i<str.length();i++){
            temp.push_back(str[i]);
            solve(res,temp,digits,mp,idx+1);
            temp.pop_back();
        }
    }



    vector<string> letterCombinations(string digits) {

        if(digits.size()==0) return {};
        vector<string> res;

        unordered_map<char,string> mp;

        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        string temp = "";

        solve(res,temp,digits,mp,0);
        return res;        
    }


    /*Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = ""
Output: []*/