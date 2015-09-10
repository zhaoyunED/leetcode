
#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
#include <iostream>
using namespace std;

int edge[101][101];
int main()
{
	int m, n, from, to, value, i, j, k;
    scanf("%d%d", &n, &m);
    memset(edge, 0x3f, 101 * 101 * sizeof(int));

	for(int i=0;i<m;i++)
	{
		scanf("%d%d%d",&from,&to,&value);
		edge[from][to] = min(edge[from][to],value);
		edge[to][from] = min(edge[to][from],value);
	}
	int d;
	
	 for(k=1;k<=n;k++)
		for(i=1;i<=n;i++)
		{	edge[i][i] = 0;
				for(j=i+1;j<=n;j++)
			{
			    
    				if((d = edge[i][k] + edge[k][j]) < edge[i][j])
    					edge[i][j] = edge[j][i] = d;
			}
		}

	for (i = 1; i <= n; ++i)
    {
        for (j = 1; j < n; ++j)
            printf("%d ", edge[i][j]);
        printf("%d\n", edge[i][j]);
    }

	
	return 0;
}