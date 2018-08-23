#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define M 1000000007
#define INF 1000000007
typedef pair<lli,lli> ll;
#define mem(a,x) memset(a,x,sizeof(a))
lli n,k,m;
lli vis[1007][1007];
lli dist[507][507];
lli path[207][207];
lli path1[207][207];
vector<int> v2(1005,1);
vector<vector<lli>> v;
lli x,y,c,z;
map<int,int> m1;
struct edge
{
    lli a,b,cost;
};
/*void djkstra(int x,vector<ll> v[])
{
    mem(vis,0);
    dist[x]=0;
    s2.insert({0,x});
    while(!s2.empty())
    {
        ll p=*s2.begin();
        s2.erase(s2.begin());
        x=p.second;
        if(vis[x])
        continue;
        vis[x]=1;
        for(int j=0;j<v[x].size();j++)
        {
            if(dist[v[x][j].second]>dist[x]+v[x][j].first)
            {
                dist[v[x][j].second]=dist[x]+v[x][j].first;
                s2.insert({dist[v[x][j].second],v[x][j].second});
                a[v[x][j].second]=x;
            }
        }
    }
}*/
lli parent[100007];
lli find(lli a)
{
    return a==parent[a]?a:parent[a]=find(parent[a]);
}
void dset(lli n)
{
    for(int j=0;j<=n;j++)
    parent[j]=j;
}
void unio(lli a,lli b,lli rank[])
{
    if(rank[find(a)]>rank[find(b)])
    parent[find(b)]=find(a);
    else if(rank[find(b)]>rank[find(a)])
    parent[find(a)]=find(b);
    else
    {
        parent[find(a)]=find(b);
        rank[find(b)]++;
    }
}
bool check(lli a,lli b)
{
    return find(a)==find(b);
}
lli vis1[31];
lli q,u,v1,l;
/*bool valid(int i,int x)
{
    for(int j=1;j<x;j++)
    {
        if((abs(b[j-1]-i)==abs(j-x))||(i==b[j-1])||(j==x))
        return false;
    }
    return true;
}*/
lli d,N,e;
lli tot;
lli coins[10007];
lli dp[3007][3007];
lli a[200007],b[200007];
lli solve(lli x,lli wc)
{
   if(x>n||wc<0)
   return 0;
   if(dp[x][wc]!=0)
   return dp[x][wc];
   dp[x][wc]=max(dp[x][wc],solve(x+1,wc));
   dp[x][wc]=max(dp[x][wc],(1+solve(x+1,min(b[x+1],wc-a[x+1]))));
   return dp[x][wc];
}
int main()
{
    while(1)
    {
        cin>>n;
        if(!n)
        return 0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i]>>b[i];
        }
        mem(dp,0);
        lli d=-1;
        for(int i=1;i<=n;i++)
        d=max(d,solve(i,b[i]));
        cout<<d<<endl;
    }
}
