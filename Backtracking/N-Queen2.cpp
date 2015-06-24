N-Queen2

Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total number of distinct solutions.



//和 N-QUEEN 1 一模一样
int totalNQueens(int n) {
        int result =0;
        if(n<=0 ) return 0;
        vector<int> vec(n,0);
        Queen(vec,n,0,result);
        return result;
    }
    
    bool isMatch(vector<int>& vec,int cur)
    {
        for(int i=0;i<cur;i++)
        {
            if( vec[i]==vec[cur] || ( abs(vec[cur]-vec[i])== (cur-i) ) )
                    return false;
        }
        return true;
    }
    
    void Queen(vector<int>& vec,int n,int cur,int& total) //vec 可以用引用 也可以不用引用
    {
        if(cur == n)
        {
            total++;
            return;
        }
        
        for(int i=0;i<n;i++)
        {
            vec[cur] = i;
            if(isMatch(vec,cur))
                Queen(vec,n,cur+1,total);
        }
    }