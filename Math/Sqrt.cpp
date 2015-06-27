Implement int sqrt(int x).

Compute and return the square root of x.



//二分查找
int sqrt(int x)
{
        unsigned long long begin = 0;  
        unsigned long long end = (x+1)/2;  
        unsigned long long mid;  
        unsigned long long tmp;  
        while(begin < end)  
        {  
            mid = begin + (end-begin)/2;  
            tmp = mid*mid;  
            if(tmp==x)return mid;  
            else if(tmp<x) begin = mid+1;  
            else end = mid-1;  
        }  
        tmp = end*end;  
        if(tmp > x)  
            return end-1;  
        else  
            return end;  
}


//位运算
int mySqrt(int x)
{
     unsigned int res = 0;
     for (int i = 15; i >= 0; i--)
     {
        if ((res + (1 << i)) * (res + (1 << i)) <= x)
            res += (1 << i);
     }
     return res;
}


//牛顿迭代算法

int sqrt(int x)
{
    double ans    = x;
    double delta  = 0.0001;
    while (fabs(pow(ans, 2) - x) > delta) {
        ans = (ans + x / ans) / 2;
    }
    return ans;
}

x(n+1) = xn - f(xn) / f'(xn)

x = sqrt(S) where S is the parameter x x^2 = S

f(xn) = xn^2 - S = 0 f'(xn) = 2 * xn

From the first sentence, x(n+1) = xn - (xn^2 - S) / 2 * xn x(n+1) = (xn + S / x_n) / 2

From the code, ans = (ans + x / ans) / 2;

I.E. get x where f(x) = x^7 + x^4 + x^2 + 1 = 0

f(x) = x^7 + x^4 + x^2 + 1 f'(x) = 7x^6 + 4x^3 + 2*x

while( > delta) { x(n+1) = xn - (xn^7 + xn^4 + xn^2 + 1) / (7*xn^6 + 4x_n^3 + 2x_n) }

return x(n_1) // depending initial value and the status of the graph, the result may vary.