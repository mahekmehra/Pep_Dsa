class Solution {
public:
    bool checkValidString(string s) {

        int n = s.length();
        int cop = 0;
        int ccl = 0;
        for(int i=0;i<n;i++){

            if(s[i]=='(' || s[i]=='*'){
                cop++;
            }else{
                cop--;
            }

            if(cop<0) return false;
        }

        for(int i=n-1;i>=0;i--){

            if(s[i]==')' || s[i]=='*'){
                ccl++;
            }else{
                ccl--;
            }

            if(ccl<0) return false;
        }

        return true;
        
    }
};

/*Input: s = "()"
Output: true
Example 2:

Input: s = "(*)"
Output: true
Example 3:

Input: s = "(*))"
Output: true*/