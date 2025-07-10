class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {

        int score = 0;
        sort(tokens.begin(),tokens.end());
        int i=0;
        int j = tokens.size()-1;
        int maxi = 0;

        while(i<=j){

            if(power>=tokens[i]){
                score++;
                power-=tokens[i];
                i++;
                maxi = max(score,maxi);
            }else if(power>=tokens[j]){
                score++;
                power-=tokens[j];
                j--;
                maxi = max(score,maxi);
            }else{
                if(score>=1){
                    if(tokens[j]>tokens[i]){
                        score--;
                        power+=tokens[j];
                        j--;
                    }else{
                        score++;
                        power+=tokens[i];
                        i++;
                    }
                }else{
                    i++;
                    j--;

                }
                
            }
        }

        return maxi;

        
    }
};

/*xample 1:

Input: tokens = [100], power = 50

Output: 0

Explanation: Since your score is 0 initially, you cannot play the token face-down. You also cannot play it face-up since your power (50) is less than tokens[0] (100).

Example 2:

Input: tokens = [200,100], power = 150

Output: 1

Explanation: Play token1 (100) face-up, reducing your power to 50 and increasing your score to 1.

There is no need to play token0, since you cannot play it face-up to add to your score. The maximum score achievable is 1.

Example 3:

Input: tokens = [100,200,300,400], power = 200

Output: 2

Explanation: Play the tokens in this order to get a score of 2:

Play token0 (100) face-up, reducing power to 100 and increasing score to 1.
Play token3 (400) face-down, increasing power to 500 and reducing score to 0.
Play token1 (200) face-up, reducing power to 300 and increasing score to 1.
Play token2 (300) face-up, reducing power to 0 and increasing score to 2.
The maximum score achievable is 2.
*/