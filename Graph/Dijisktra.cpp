#include <stdio.h>
#include <string.h>
#include <queue>
#include <vector>
using namespace std;
const int maxn = 1990;
bool used[maxn];
int n, m, s, e;
struct data
{
	int x;
	int dis;
	const bool operator < (const data &b) const
	{
		return dis > b.dis;
	}
}temp,tempi;
vector<data> map[maxn];



void input()
{
	int i;
	int a, b, length;
	scanf("%d %d %d %d", &n, &m, &s, &e);
	for (i = 0; i < m; ++i)
	{
		scanf("%d%d%d", &a, &b, &length);
		temp.x = b;
		temp.dis = length;
		map[a].push_back(temp);
		temp.x = a;
		map[b].push_back(temp);
	}
	return;
}


void work()
{
	int i;
	priority_queue<data> q;
	temp.x = s;
	temp.dis = 0;
	q.push(temp);
	while (!q.empty())
	{
		temp = q.top();
		q.pop();
		if (!used[temp.x])
		{
			if (temp.x == e)
			{
				printf("%d\n", temp.dis);
				return;
			}
			for (i = 0; i < map[temp.x].size(); ++i)
			{
				if (!used[map[temp.x][i].x])
				{
					tempi.x = map[temp.x][i].x;
					tempi.dis = temp.dis + map[temp.x][i].dis;
					q.push(tempi);
				}
			}
			used[temp.x] = 1;
		}
	}
	return;
}

int main()
{
	input();
	work();
	return 0;
}