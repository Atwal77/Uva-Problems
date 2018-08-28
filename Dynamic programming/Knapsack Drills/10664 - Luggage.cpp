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
lli vis[1007][1007];
lli dist[507][507];
lli path1[207][207];
vector<int> v2(1005,1);
vector<lli> v;
lli x,y,c,z,t,q,u;
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
lli dp[21][201];
lli pr[200007],we[200007];
lli solve(lli n,lli v1,lli v2,lli k)
{
if(n==0)
return abs(v1-v2);
if(dp[n][abs(v1-v2)]!=INF)
return dp[n][abs(v1-v2)];
dp[n][abs(v1-v2)]=min(dp[n][abs(v1-v2)],solve(n-1,v1+v[k],v2,k+1));
dp[n][abs(v1-v2)]=min(dp[n][abs(v1-v2)],solve(n-1,v1,v2+v[k],k+1));
return dp[n][abs(v1-v2)];
}
int main()
{
   cin>>t;
   getchar();
   while(t--)
   {
       string s;
       getline(cin,s);
       for(int j=0;j<s.length();j++)
       {
           string d="\0";
           while(s[j]>=48&&s[j]<=57)
           d+=s[j],j++;
           lli f=stoi(d);
           v.push_back(f);
       }
       for(int j=0;j<=20;j++)
       {
           for(int k=0;k<=200;k++)
           dp[j][k]=INF;
       }
       lli d=solve(v.size(),0,0,0);
       if(d>0)
       cout<<"NO"<<endl;
       else
       cout<<"YES"<<endl;
       v.clear();
   }
}
