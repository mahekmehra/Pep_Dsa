
int heapHeight(int n, int arr[]) {
        // code here
        if(n==1) return 1;
        
        int h = 0;
        while(n>1){
            h++;
            n=n/2;
        }
        
        return h;
}

/*
Input: n = 9, arr[] = [3, 6, 9, 2, 15, 10, 14, 5, 12]
Output: 3
Explaination: The tree looks like following
           (2)
        /      \
      (3)      (9)
     /  \     /   \
   (5) (15) (10) (14)
   / \
 (6) (12)*/