Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: 
Starting with any positive integer, replace the number by the sum of the squares of its digits, 
and repeat the process until the number equals 1 (where it will stay), 
or it loops endlessly in a cycle which does not include 1. 
Those numbers for which this process ends in 1 are happy numbers.

Example: 19 is a happy number

12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1

//简单的小逻辑题目
bool isHappy(int n)
{
        if(n ==1) return true;
        
        unordered_set<int> set;
        
        int newNum =0;
        
        while((newNum = getNum(n)) !=1 )
        {
            if(set.find(newNum) == set.end())
                set.insert(newNum);
            else
                return false;
            n = newNum ;   
        }
        
        return true;
}
    
int getNum(int n)
{
     int result =0;
     while(n>0)
     {
         int temp = n%10;
         result += temp*temp;
         n = n/10;
     }
     return result;
}