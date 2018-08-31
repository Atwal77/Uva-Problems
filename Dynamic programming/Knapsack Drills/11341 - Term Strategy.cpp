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
vector<double> v;
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
lli dp[15][111];
map<ll,ll> pat;
map<ll,lli> p2;
lli pr[200007],we[200007];
lli a[15][105];
lli s1;
string s3[301];
lli n1;
map<lli,vector<int>> m4;
vector<int> v4;
int f=1;
lli solve(lli i,lli m)
{
if(m==0&&i<=n)
return -10000000;
if(m<0)
return -10000000;
if(i==n+1)
return 0;
if(dp[i][m]!=-100000)
return dp[i][m];
for(int j=1;j<=m;j++)
{
if(a[i][j]>=5)
dp[i][m]=max(dp[i][m],a[i][j]+solve(i+1,m-j));
}
return dp[i][m];
}
int main()
{
cin>>t;
while(t--)
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        cin>>a[i][j],dp[i][j]=-100000;
    }
    double d=solve(1,m);
    if(d>0)
    {
        double p=d/n;
        p=p*100;
        p=p+0.5;
        p=floor(p);
        p=p/100.0;
        printf("Maximal possible average mark - %0.2f.\n",p);
    }
    else
    cout<<"Peter, you shouldn't have played billiard that much."<<endl;
}
}
