The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.


//一个简单的循环迭代处理
string convert(string say)
    {
        stringstream ss;
        int count =0;
        char pre =say[0];
        
        for(int i=0;i<=say.size();i++)
        {
            if(say[i]==pre)
                count++;
            else{
                ss<<count<<pre;
                pre = say[i];
                count =1;
            }
        }
        return ss.str();
    }


string countAndSay(int n) 
{
        if(n<=0) return "";
        string result ="1";
        
        for(int i=1;i<n;i++)
        {
            result = convert(result);
        }
        return result;
}