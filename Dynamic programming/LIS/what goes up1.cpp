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
lli path[100007];
int main()
{
   set<int> s;
   map<lli,lli> m,m1,m2;
   int t=0;
   int a[1000007];
   lli L,L1;
   L=1;
   lli d=1;
   vector<int> v;
    while(cin>>n)
    {
        t++;
        a[t]=n;
        if(s.find(n)==s.end())
        {
            s.insert(n);
            auto it=s.find(n);
            auto it1=it;
            auto it2=it;
            it1--;
            it++;
            m[n]=t;
            m1[t]=(it2==s.begin())?INF:m[*it1];
            if(it!=s.end())
            {
                s.erase(it);
            }
        }
    }
    cout<<s.size()<<endl<<"-"<<endl;
    for(int j=m[*s.rbegin()];j!=INF;j=m1[j])
    v.push_back(a[j]);
    for(int j=v.size()-1;j>=0;j--)
    cout<<v[j]<<endl;
}
/*
test case:
6
3
4
5
2
3
4
output:
2
3
4
*/
