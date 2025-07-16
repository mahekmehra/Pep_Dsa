class Solution {
public:
    bool winnerOfGame(string colors) {

        int n = colors.length();

        if(n<3) return false;

        int totA = 0;
        int totB = 0;

        for (int i = 1; i < n - 1; i++) {
            if (colors[i - 1] == colors[i] && colors[i] == colors[i + 1]) {
                if (colors[i] == 'A') totA++;
                else totB++;
            }
        }

        return (totA>totB);
    }
          
};

/*Input: colors = "AAABABB"
Output: true
Explanation:
AAABABB -> AABABB
Alice moves first.
She removes the second 'A' from the left since that is the only 'A' whose neighbors are both 'A'.

Now it's Bob's turn.
Bob cannot make a move on his turn since there are no 'B's whose neighbors are both 'B'.
Thus, Alice wins, so return true.*/