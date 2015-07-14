Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6


 //stack 的经典利用

 int perop(int a,int b,string op)
{
        if(op=="+")
            return a+b;
        else if(op=="-")
            return a-b;
        else if(op=="*")
            return a*b;
        else if(op=="/")
            return a/b;
        return 0;
}
    
int evalRPN(vector<string>& tokens)
{
        stack<int> ss;
        for(auto str : tokens)
        {
            if(str == "+" || str =="-" || str =="*" || str =="/")
            {
                int a = ss.top();ss.pop();
                int b = ss.top();ss.pop();
                int c = perop(b,a,str);
                ss.push(c);
            }else{
                ss.push(atoi(str.c_str()));
            }
        }
        
        return ss.top();
}