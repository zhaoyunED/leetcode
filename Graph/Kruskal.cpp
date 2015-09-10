#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

typedef long long LL;
const int INF = 0x3f3f3f3f;
const int MAX = 1000000+10;

int t, n, m, Case = 1;

struct EDGE
{
	int u, v, w;
	bool operator < (const EDGE& p)const
	{
		return w < p.w;
	}
}Edge[MAX];

int a[MAX];

int Find(int x)
{
	if(x == a[x]) return a[x];
	else return a[x] = Find(a[x]);
}

void Uni(int u, int v)
{
	if(u>v) {u^=v;v^=u;u^=v;}
	a[v] = a[u];
}

void Kruscal()
{
	LL ans = 0;
	for(int i = 1; i<=m; i++)
	{
		int u, v;
		if((u = Find(Edge[i].u)) != (v = Find(Edge[i].v)))
		{
			Uni(u, v);
			ans += Edge[i].w;
		}
	}
	printf("%lld\n", ans);
}

int main()
{
#ifdef OFFLINE
    freopen("input.txt", "r", stdin);
#endif

    while(~scanf("%d%d", &n, &m))
    {
		for(int i = 1; i<=n; i++) a[i] = i;
		for(int i = 1; i<=m; i++)
		{
			scanf("%d%d%d", &Edge[i].u, &Edge[i].v, &Edge[i].w);
		}
		sort(Edge+1, Edge+m+1);
		Kruscal();
    }
    return 0;
}