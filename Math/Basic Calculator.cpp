Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

You may assume that the given expression is always valid.

Some examples:
"1 + 1" = 2
" 2-1 + 2 " = 3
"(1+(4+5+2)-3)+(6+8)" = 23
Note: Do not use the eval built-in library function.



int calculate(string s)
{
        stack<int> signs; //ÓÃÀ´´æ·Å ·ûºÅ
        int sign = 1;
        int num = 0;
        int ans = 0;
        
        signs.push(1);
        
        for(auto c:s)
        {
            if(c>='0' && c<='9')
            {
                num = num*10+c-'0';
            }else if( c == '+' || c=='-')
            {
                ans = ans + signs.top() * sign * num;
                sign = c=='+' ? 1 :-1;
                num =0;
            }else if(c =='(')
            {
                signs.push(sign* signs.top());
                sign =1;
                
            }else if( c == ')')
            {
                ans = ans + signs.top() * sign * num;
                signs.pop();
                num=0;
                sign =1;
            }
        }
        
        if (num) {
            ans = ans + signs.top() * sign * num;
        }

        return ans;
}