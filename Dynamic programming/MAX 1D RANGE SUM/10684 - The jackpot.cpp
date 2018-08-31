/*
"IF U BELIEVE WHY NOT!!"
                       --Cristiano Ronaldo
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define M 1000000007
#define INF 1000000007
typedef pair<lli,lli> ll;
#define mem(a,x) memset(a,x,sizeof(a))
lli n,k,m;
lli dist[507][507];
lli path1[207][207];
vector<int> v2(1005,1);
vector<double> v;
lli x,y,c,z,t,q,u,d,a1,b;
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
bool check(lli a)
{
    if((a1*a*m+b*(a-1)+d)>=x)
    return true;
    return false;
}
/*bool valid(int i,int x)
{
    for(int j=1;j<x;j++)
    {
        if((abs(b[j-1]-i)==abs(j-x))||(i==b[j-1])||(j==x))
        return false;
    }
    return true;
}*/
lli p[10007];
lli dp[100001];
map<ll,ll> pat;
map<ll,lli> p2;
lli pr[200007],we[200007];
lli a[100005];
map<lli,vector<int>> m4;
vector<int> v4;
int f=0;
lli tot=1;
lli vis[1001][1001];
lli p1;
lli solve(lli n)
{
if(n==1)
return dp[n]=a[n];
if(dp[n]!=-1)
return dp[n];
dp[n]=a[n]+max(0LL,solve(n-1));
return dp[n];
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
        cin>>a[i];
    }
    mem(dp,-1);
    solve(n);
    lli d=-1;
    for(int i=1;i<=n;i++)
    {
        d=max(d,dp[i]);
    }
    if(d<=0)
    cout<<"Losing streak."<<endl;
    else
    cout<<"The maximum winning streak is "<<d<<"."<<endl;
}
}
