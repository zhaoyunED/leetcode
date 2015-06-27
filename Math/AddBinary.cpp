Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".

//不用考虑a与b的长度谁大,直接进行二进制加法操作
string addBinary(string a, string b)
{
       int c=0;
       int i = a.size()-1;
       int j = b.size()-1;
       
       string s="";
       int vala =0;
       int valb =0;
       while(c>0 || i >=0 || j>=0)
       {
           vala = i>=0 ? a[i--]-'0': 0;
           valb = j>=0 ? b[j--]-'0': 0;
           
           c += vala+valb;
           s.push_back(c%2+'0');
           c = c/2;
       }
       
       reverse(s.begin(),s.end());
       return s;
}