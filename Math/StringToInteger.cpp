Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. 
If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). 
You are responsible to gather all the input requirements up front.



int myAtoi(string str) 
{
   int index=0;
        int n = str.size();
        
        //qu kongge
        while(index<n && str[index]==' ') index++;
        
        if(index>=n) return 0;
        
        int sign =1;
        if(str[index]=='+')
        {
            sign=1;
            index++;
        }else if(str[index]=='-')
        {
            sign =-1;
            index++;
        }
        long result =0;//important sheidng wei long 才能与INT_MAX比较
        
        while(index<n && result< INT_MAX && isdigit(str[index]) )
        {
            result = result*10+ str[index]-'0';
            index++;
        }
        
        if(result >INT_MAX)
        {
            return sign ==1 ? INT_MAX:INT_MIN;
        }
        
        return result*sign;

}