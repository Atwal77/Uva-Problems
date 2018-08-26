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
lli dp[200007];
lli dp1[200007];
lli a[200007],b[200007];
map<lli,lli> m1;
lli solve(lli x)
{
   if(dp[x]!=0)
   return dp[x];
   int f=0;
   for(int i=1;i<x;i++)
   {
       if(a[i]<a[x])
       {
           dp[x]=max(dp[x],b[x]+solve(i));
           f=1;
       }
   }
   if(f)
   return dp[x];
   return dp[x]=b[x];
}
lli solve1(lli x)
{
    if(dp1[x]!=0)
    return dp1[x];
    int f=0;
    for(int i=x+1;i<=n;i++)
    {
        if(a[i]<a[x])
        {
            dp1[x]=max(dp1[x],b[x]+solve1(i));
            f=1;
        }
    }
    if(f)
    return dp1[x];
    return dp1[x]=b[x];
}
lli pw[100];
lli t;
int main()
{
   cin>>t;
   getchar();
   getchar();
   int o=0;
   while(t--)
   {
      o++;
      vector<lli> v;
      string s1;
      while(getline(cin,s1))
      {
          if(s1[0]=='\0')
          break;
          stringstream ss(s1);
          ss>>n;
          v.push_back(n);
      }
      set<lli> s;
      map<lli,lli> m,m1;
      for(int j=0;j<v.size();j++)
      {
          if(s.find(v[j])==s.end())
          {
          s.insert(v[j]);
          auto it=s.find(v[j]);
          auto it1=it;
          it1--;
          m[*it]=j;
          m1[j]=it==s.begin()?INF:m[*it1];
          it++;
          if(it!=s.end())
          s.erase(it);
          }
      }
      cout<<"Max hits: "<<s.size()<<endl;
      vector<int> v1;
      for(int j=m[*s.rbegin()];j!=INF;j=m1[j])
      v1.push_back(v[j]);
      for(int j=v1.size()-1;j>=0;j--)
      cout<<v1[j]<<endl;
      if(t>0)
      cout<<endl;
      v.clear();
      v1.clear();
      m.clear();
      m1.clear();
   }
}
/*
IF U BELIEVE WHY NOT!!
*/
