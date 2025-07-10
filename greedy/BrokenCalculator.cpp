
int brokenCalc(int startValue, int target) {

        int count = 0;
        while(target>startValue){
            if(target%2==0){
                count++;
                target/=2;
            }else{
                count++;
                target+=1;
            }
        }

        return count + (startValue-target);
}



   if(target<=startValue){                                      //Recursive Approach 
            return startValue - target;
        }

        if(target%2==0){
            return 1 + brokenCalc(startValue,target/2);
        }else{
            return 1 + brokenCalc(startValue,target+1);
        }
    }

