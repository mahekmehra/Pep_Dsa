
class Solution {
  public:
    int distance(int x, int y) {
        // code here
        if(x==y) return 0;
        
        int count = 0;
        
        while(x!=y){
            
            if(x>y){
                x/=2;
                count++;
            }else{
                y/=2;
                count++;
            }
        }
        
        return count;
        
        
    }
};

/*Consider you have an infinitely long binary tree having the pattern as below
               1

            /     \
           2      3  

         /  \     /   \
        4  5    6  7
    .  .  .  .   .  .  .  . 
Given two nodes with values x and y, the task is to find the length of the shortest path between the two nodes.

Examples:

Input: x = 1, y = 3
Output: 1
Explanation: 3 is the child of 1 so, distance between them is 1.*/