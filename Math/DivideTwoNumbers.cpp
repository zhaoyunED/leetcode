Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.




int divide(int dividend, int divisor)
{
        auto sign = [=](int x){
            return x>=0 ? 1 : -1;
        };
        
        int d1 = sign(dividend);
        int d2 = sign(divisor);
        
        if(divisor == 0 || (dividend == INT_MIN && divisor ==-1))
            return INT_MAX;
        
        long long n1 = abs(static_cast<long long>(dividend));
        long long n2 = abs(static_cast<long long>(divisor));
        long long ans = 0;
        
        while(n1>=n2)
        {
            long long base = n2;
            for(int i=0;base<=n1;i++)
            {
                n1 -= base;
                base <<=1;
                ans += 1LL<<i;
            }
        }
        
        int res = static_cast<int>(ans);
        
        if(d1 != d2) return -res;
        else return res;
}