#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;
#define Maxn 105000
#define Maxm 1000500
#define INF 0x3f3f3f3f
struct Edge{
	int to;int len;
	int next;
}edge[Maxm*2];
int en,head[Maxn];
inline void add_edge(int u,int v,int len){
	edge[en].to=v;edge[en].len=len;edge[en].next=head[u];head[u]=en++;
}
int dis[Maxn];
bool vis[Maxn];
int spfa(int src,int des){
	memset(vis,false,sizeof(vis));
	memset(dis,0x3f,sizeof(dis));
	queue<int> que;
	que.push(src);vis[src]=true;dis[src]=0;
	while (!que.empty()){
		int u=que.front();que.pop();vis[u]=false;
		for (int p=head[u];~p;p=edge[p].next){
			int v=edge[p].to,len=edge[p].len;
			if (dis[v]>dis[u]+len){
				dis[v]=dis[u]+len;
				if (!vis[v]){
					que.push(v);
					vis[v]=true;
				}
			}
		}
	}
	if (dis[des]>=INF) return -1;
	else return dis[des];
}

int main(){
	int n,m;
	int src,des;
	while (~scanf("%d%d",&n,&m)){
		scanf("%d%d",&src,&des);
		en=0;
		fill(head,head+n+1,-1);
		int u,v;int len;
		for (int i=1;i<=m;i++){
			scanf("%d%d%d",&u,&v,&len);
			add_edge(u,v,len);
			add_edge(v,u,len);
		}
		printf("%d\n",spfa(src,des));
	}
	return 0;
}






//方法2
#include <iostream>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
 
const int MAXN=100;
const int INF=0x7FFFFFFF;
 
struct edge
{
    int to,weight;
};
 
vector<edge> adjmap[MAXN];//邻接表
bool in_queue[MAXN];//顶点是否在队列中
int in_sum[MAXN];//顶点入队次数
int dist[MAXN];//源点到各点的最短路径
int path[MAXN];//存储到达i的前一个顶点
int nodesum;//顶点数
int edgesum;//边数
 
bool SPFA(int source)
{
    deque<int> dq;
    int i,j,x,to;
    for(i=1;i<=nodesum;i++)
    {
        in_sum[i]=0;
        in_queue[i]=false;
        dist[i]=INF;
        path[i]=-1;
    }
    dq.push_back(source);
    in_sum[source]++;
    dist[source]=0;
    in_queue[source]=true;
//初始化完成
 
    while(!dq.empty())
    {
        x=dq.front();
        dq.pop_front();
        in_queue[x]=false;
        for(i=0;i<adjmap[x].size();i++)
        {
            to=adjmap[x][i].to;
            if((dist[x]<INF)&&(dist[to]>dist[x]+adjmap[x][i].weight))
            {
                dist[to]=dist[x]+adjmap[x][i].weight;
                path[to]=x;
                if(!in_queue[to])
                {
                    in_queue[to]=true;
                    in_sum[to]++;
                    if(in_sum[to]==nodesum) return false;
                    if(!dq.empty())
                    {
                        if(dist[to]>dist[dq.front()]) dq.push_back(to);
                        else dq.push_front(to);
                    }else dq.push_back(to);
                }
            }
        }
    }
    return true;
}
 
void Print_Path(int x)
{
    stack<int> s;
    int w=x;
    while(path[w]!=-1)
    {
        s.push(w);
        w=path[w];
    }
    cout<<"顶点1到顶点"<<x<<"的最短路径长度为："<<dist[x]<<endl;
    cout<<"所经过的路径为：1";
    while(!s.empty())
    {
        cout<<s.top()<<"";
        s.pop();
    }
    cout<<endl;
}
 
int main()
{
    int i,s,e,w;
    edge temp;
    cout<<"输入顶点数和边数：";
    cin>>nodesum>>edgesum;
    for(i=1;i<=nodesum;i++)
    adjmap[i].clear();//清空邻接表
    for(i=1;i<=edgesum;i++)
    {
        cout<<"输入第"<<i<<"条边的起点、终点还有对应的权值：";
        cin>>s>>e>>w;
        temp.to=e;
        temp.weight=w;
        adjmap[s].push_back(temp);
    }
    if(SPFA(1))
    {
        for(i=2;i<=nodesum;i++) Print_Path(i);
    } else cout<<"图中存在负权回路"<<endl;
    return 0;
}