Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

For example, given the range [5, 7], you should return 4.


//����1
//���������ͬ�Ĳ��� ����ʣ�µ����� ΪANDΪ0
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

//����2
//����һЩ
int rangeBitwiseAnd(int m, int n)
{
    while(n > m) { 
       n = n & (n-1);
    }
    return n;
}