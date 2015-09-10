#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=1000+10;
int cost[maxn][maxn];
int mincost[maxn];
bool used[maxn];
int n;
int INF=65535;
int prim()
{
    for(int i=0;i<n;++i)
    {
        mincost[i]=INF;
        used[i]=false;
    }
    mincost[0]=0;
    int res=0;
    while(true)
    {
        int v=-1;
        for(int u=0;u<n;u++)
        {
            if(!used[u]&&(v==-1||mincost[u]<mincost[v]))
                v=u;
        }
        if(v==-1)   break;
        used[v]=true;
        res+=mincost[v];
        for(int u=0;u<n;u++)
        {
            mincost[u]=min(mincost[u],cost[v][u]);
        }
    }
    return res;
}
int main()
{
    while(cin>>n)
    {
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            cin>>cost[i][j];
        int dd=prim();
        cout<<dd<<endl;
    }
    return 0;
}
