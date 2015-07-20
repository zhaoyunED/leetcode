Given an integer n, return the number of trailing zeroes in n!.


int trailingZeroes(int n)
{
        if(n<=0) return 0;
        int ret=0;
        while(n)
        {
            ret += n/5;
            n= n/5;
        }
        return ret;
}