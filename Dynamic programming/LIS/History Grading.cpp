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
lli dp[27];
lli a[200007],b[200007];
map<lli,lli> m1;
lli solve(lli x)
{
   if(dp[x]!=0)
   return dp[x];
   int f=0;
   for(int i=1;i<x;i++)
   {
       if(m1[a[i]]<m1[a[x]])
       {
           dp[x]=max(dp[x],1+solve(i));
           f=1;
       }
   }
   if(f)
   return dp[x];
   return dp[x]=1;
}
int main()
{
    int t=0;
    while(1)
    {
     if(t==0)
     cin>>n;
     if(n>20)
     break;
     for(int i=1;i<=n;i++)
     {
         cin>>a[i];
         m1[i]=a[i];
     }
     while(1)
     {
     mem(dp,0);
     for(int i=1;i<=n;i++)
     {
         if(cin>>x)
         {
         if(x>n)
         break;
         a[x]=i;
         }
     }
     if(x>n)
     break;
     for(int i=1;i<=n;i++)
     solve(i);
     lli d=-1;
     for(int i=1;i<=n;i++)
     d=max(d,dp[i]);
     cout<<d<<endl;
     x=1000000;
     }
     t++;
     if(x>n)
     {
         n=x;
         m1.clear();
         continue;
     }
    }
}
/* test case 1:
4
4 2 3 1
1 3 2 4
3 2 1 4
2 3 4 1
10
3 1 2 4 9 5 10 6 8 7
1 2 3 4 5 6 7 8 9 10
4 7 2 3 10 6 9 1 5 8
3 1 2 4 9 5 10 6 8 7
2 10 1 3 8 4 9 5 7 6

Output:
1
2
3
6
5
10
9
*/
