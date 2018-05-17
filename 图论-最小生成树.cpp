#include<cstdio>
#include<string>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<cstring>
#include<set>
#include<queue>
#include<algorithm>
#include<vector>
#include<map>
#include<cctype>
#include<stack>
#include<sstream>
#include<list>
#include<assert.h>
#include<bitset>
#include<numeric>
#define debug() puts("++++")
#define gcd(a,b) __gcd(a,b)
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define fi first
#define se second
#define pb push_back
#define sqr(x) ((x)*(x))
#define ms(a,b) memset(a,b,sizeof(a))
#define sz size()
#define be begin()
#define pu push_up
#define pd push_down
#define cl clear()
#define lowbit(x) -x&x
#define all 1,n,1
#define rep(i,n,x) for(int i=(x); i<(n); i++)
#define in freopen("in.in","r",stdin)
#define out freopen("out.out","w",stdout)
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> P;
const int INF = 0x3f3f3f3f;
const LL LNF = 1e18;
const int MAXN =  1e3 + 5;
const int maxm = 1e6 + 10;
const double PI = acos(-1.0);
const double eps = 1e-8;
const int dx[] = {-1,1,0,0,1,1,-1,-1};
const int dy[] = {0,0,1,-1,1,-1,1,-1};
const int mon[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int monn[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int G[MAXN][MAXN];
int n,m;
void prim()
{
	int lowcost[MAXN],closest[MAXN],vis[MAXN];
	/*1.记录不在S中的顶点到S的最短距离，即到最近邻接点的权值
	  2.记录不在S中的顶点在S中的最近邻接点
      3.标记顶点是否被访问，访问过的顶点标记为1
	 */
	vis[1]=1;
	for(int i=2; i<=n; i++){
		lowcost[i]=G[1][i];
		closest[i]=1;
		vis[i]=0;
	}

	for(int i=2;i<=n;i++){
		int Min = INF;
		int j=1;
		for(int k=1;k<=n;k++)
			if((!vis[k]) && lowcost[k]<Min){
				Min = lowcost[k];
				j=k;
         }

         printf("%d %d %d\n",closest[j],j,lowcost[j]);
		 vis[j]=1;
		 for(int k=2;k<=n;k++){
             if(G[j][k] < lowcost[k] && !vis[k]){
                lowcost[k]=G[j][k];
                closest[k] = j;
             }
		 }
	}
}
int main()
{
	int a,b,c;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			G[i][j] = INF;
		}
	}
	for(int i=1;i<=m;i++){
		cin>>a>>b>>c;
		G[a][b]=G[b][a]=c;
	}
	prim();
}
/*
3 3
1 2 10
1 3 15
2 3 50
1 2 10
1 3 15
*/
