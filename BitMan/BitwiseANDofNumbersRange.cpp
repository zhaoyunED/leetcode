Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

For example, given the range [5, 7], you should return 4.


//方法1
//找最左边相同的部门 其余剩下的总是 为AND为0
int rangeBitwiseAnd(int m, int n)
{
        int i = 0;
        while(m!=n){
            m=m>>1;
            n=n>>1;
            ++i;        
        }
        return m<<i;
}

//方法2
//更快一些
int rangeBitwiseAnd(int m, int n)
{
    while(n > m) { 
       n = n & (n-1);
    }
    return n;
}