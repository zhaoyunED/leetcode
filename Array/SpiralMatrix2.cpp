Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]


vector<vector<int>> generateMatrix(int n)
{
        if(n<=0)
            return vector<vector<int> >();
        if(n==1)
            return vector<vector<int> >(1,vector<int>(1,1));
            
        vector<vector<int>> result(n,vector<int>(n,0));
        
        int x1=0,y1=0;
        int x2=n-1,y2=n-1;
        
        int num =1;
        
        while(x1<=x2 && y1<=y2)
        {
            for(int i=y1; i<=y2 ;i++)
                result[x1][i] = num++;
            for(int i=x1+1;i<=x2;i++)
                result[i][y2] = num++;
            for(int i= y2-1;i>=y1; i--)
                result[x2][i] = num++;
            for(int i= x2-1;i>x1;i--)
                result[i][y1]=num++;
            x1++;y1++;
            x2--;y2--;
        }
        
        return result;
}