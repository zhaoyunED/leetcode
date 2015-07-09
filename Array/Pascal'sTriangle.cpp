Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]




//很简单的一个题目

vector<vector<int>> generate(int numRows)
{
        vector<vector<int>> result;
        if(numRows<=0)
            return result;
        vector<int> first(1,1);
            
        result.push_back(first);
        for(int i=2;i<=numRows;i++)
        {
            vector<int> cur;
            cur.push_back(1);
            
            vector<int> pre = result[i-2];
            
            for(int j=0;j<pre.size()-1;j++)
            {
                cur.push_back(pre[j]+pre[j+1]);
            }
            
            cur.push_back(1);
            result.push_back(cur);
        }
        
        return result;
}


//精简代码版

vector<vector<int> > generate(int numRows) {
          vector<vector<int> > r;  
			for(int i = 0; i < numRows; i++){  
				vector<int> tmp;  
				for(int j = 0; j <= i; j++){  
					if(j == 0 || j == i){  
						tmp.push_back(1);  
					}  
					else{  
						tmp.push_back(r[i - 1][j - 1] + r[i - 1][j]);  
					}  
				}  
				r.push_back(tmp);  
			}  
			return r;
    }