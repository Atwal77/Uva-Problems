#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define M 1000000007
#define INF 1000000007
typedef pair<lli,lli> ll;
#define mem(a,x) memset(a,x,sizeof(a))
lli n,k,m;
lli vis[10007];
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
lli a[300007];
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
lli dp[10007];
lli dp1[10007];
lli s,t;
lli s1=0;
lli solve(lli x)
{
    if(x==0)
    return 0;
    if(dp1[x]!=INF)
    return dp1[x];
    for(int i=6;i>=1;i--)
    {
        if(x>=coins[i])
        {
            dp1[x]=min(dp1[x],1+solve(x-coins[i]));
        }
    }
    return dp1[x];
}
int main()
{
coins[0]=0;
coins[1]=5;
coins[2]=10;
coins[3]=20;
coins[4]=50;
coins[5]=100;
coins[6]=200;
while(1)
{
    double x;
    int c=0;
    mem(vis,0);
    for(int i=0;i<=10000;i++)
    dp[i]=INF,dp1[i]=INF;
    s1=0;
    for(int i=1;i<=7;i++)
    {
        if(i<=6)
        cin>>a[coins[i]],s1+=a[coins[i]]*coins[i];
        else
        cin>>x;
        if(i<=6&&a[coins[i]]==0)
        c+=1;
    }
    a[coins[0]]=INF;
    s=round(100.0*x);
    if(c==6)
    return 0;
    for(int j=s1;j>=0;j-=5)
    {
        lli j1=j;
        int c=0;
        int a1[201];
        for(int i=6;i>=1;i--)
        {
            a1[coins[i]]=a[coins[i]];
        }
        for(int i=6;i>=1;i--)
        {
            while(a[coins[i]]>0&&j1>0)
            {
                j1-=coins[i];
                a[coins[i]]--;
                c+=1;
            }
            if(j1==0)
            {
                dp[j]=c;
                break;
            }
            else if(j1<0)
            {
                j1+=coins[i];
                a[coins[i]]++;
                c-=1;
            }
        }
        for(int i=6;i>=1;i--)
        {
            a[coins[i]]=a1[coins[i]];
        }
    }
    lli d=dp[s];
    solve(s1);
    for(int j=s+5;j<=s1;j+=5)
    {
        d=min(d,dp[j]+dp1[j-s]);
    }
    string d1=to_string(d);
    string d2="har";
    for(int j=2;j>=0;j--)
    {
        if(j>=d1.length())
        {}
        else
        d2[d1.length()-j-1]=d1[j];
    }
    for(int j=2;j>=0;j--)
    {
        if(j>=d1.length())
        cout<<" ";
        else
        cout<<d2[j];
    }
    cout<<endl;
}
}
