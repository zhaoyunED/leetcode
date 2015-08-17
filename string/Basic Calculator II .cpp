Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.

You may assume that the given expression is always valid.

Some examples:
"3+2*2" = 7
" 3/2 " = 1
" 3+5 / 2 " = 5
Note: Do not use the eval built-in library function.



//方法1
//利用 istringstream
int calculate(string s) {
        istringstream in('+' + s + '+');
        long long total = 0, term = 0, n;
        char op;
        while (in >> op) {
            if (op == '+' || op == '-') {
                total += term;
                in >> term;
                term *= 44 - op;
            } else {
                in >> n;
                if (op == '*')
                    term *= n;
                else
                    term /= n;
            }
        }
        return total;
 }

 //方法2 利用stack
  int calculate(string s) {
        stack<char> opS;
       stack<int>  numS;
       s.push_back(')'); // to make sure the last operand will be saved in the stack e.g. 1+2*3), 2*3 will be calculated and push in the stack
       opS.push('+'); // sign for the first operand

       int i, curNum, len = s.size(), res =0;
       for(i=0,curNum=0; i<len; ++i)
       {
           if(isdigit(s[i])) curNum = curNum*10 + s[i] -'0'; // digit, recover the oprand
           else if(isspace(s[i])) continue; // skip the space
           else
           {
               switch(opS.top())
               { 
                   case '*': // if the last operator is * / , do calculation
                   case '/':
                        curNum = opS.top()=='/'?numS.top()/curNum : numS.top()*curNum;
                        opS.pop();
                        numS.pop();
               }
                numS.push(curNum); 
                curNum = 0;
                opS.push(s[i]);
           }
       }
       opS.pop(); // skip the ")"
       while(!opS.empty()) {res += (opS.top()=='-')? -numS.top(): numS.top(); opS.pop(); numS.pop();}
       return res;
    }