class Solution {
  public:
    pair<int, int> get(int a, int b) {
        // complete the function here
        
        a=a^b;
        b=a^b;
        a=a^b;
        return {a,b};


        //Method 2
        a = a+b;
        b = a-b;
        a = a-b;
    }
};

/* Swapping two numbers using bit manipulation
   a=13
   b=9
   a = a^b   13^9
   b = a^b   (13^9)^9 = 13
   a = a^b   (13^9)^13 = 9
*/