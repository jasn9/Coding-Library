
// https://codeforces.com/contest/546/problem/E

#include<bits/stdc++.h>
 
using namespace std;
typedef long long int ll;
 
#define endl '\n'
 
ll n,m;
ll arr[105];
ll brr[105];
ll par[205];
 
ll cap[205][205];
 
ll bfs(ll s,ll t)
{
   memset(par,-1,sizeof(par));
   queue <ll> que;
   que.push(s);
    ll flg =  0;
   while(!que.empty())
   {
       ll x = que.front();
       que.pop();
       //cout<<" *"<<x<<endl;
 
       for(ll i=0;i<=2*n+1;i++){
 
          ll v = i;//cout<<" ** "<<v<<" "<<cap[x][v]<<endl;
          if( par[v]==-1 and v!=s and cap[x][v]>0 ){
            que.push(v);
            par[v] = x;
            if(x==t){
                flg = 1;
                break;
            }
          }
 
       }
       if(flg==1)break;
 
   }
 
   if(par[t]==-1){
    return -1;
   }
   ll v = t;
   ll u = par[t];
   ll ans = INT_MAX;
   while(u!=-1)
   {
      ans = min(ans,cap[u][v]);
      v = par[v];
      u = par[u];
   }
    v = t;
    u = par[t];
   while(u!=-1){
 
      cap[u][v] -= ans;
      cap[v][u] += ans;
      v = u;
      u = par[u];
   }
   return ans;
 
 
}
 
ll maxflow()
{
    ll flow = 0;
    while(1){
 
        ll x = bfs(0,2*n+1);
        //cout<<x<<endl;
        if(x==-1){
            return flow;
        }
        flow += x;
 
    }
 
    return flow;
 
}
 
 
int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(cap,0,sizeof(cap));
    cin>>n>>m;
 
    ll s1 = 0;
    for(ll i=1;i<=n;i++){
        cin>>arr[i];
        s1+=arr[i];
    }
    ll s2 = 0;
    for(ll i=1;i<=n;i++){
        cin>>brr[i];
        s1-=brr[i];
        s2+=brr[i];
    }
    if(s1){
        cout<<"NO"<<endl;return 0;
    }
 
    for(ll i=0;i<m;i++){
        ll a,b;
        cin>>a>>b;
        cap[a][b+n] = 200;
        cap[b][a+n] = 200;
    }
 
    for(ll i=0;i<n;i++){
        cap[0][i+1] = arr[i+1];
        cap[i+1+n][2*n+1] = brr[i+1];
        cap[i+1][n+i+1] = 200;
 
    }
 
 
 
 
    ll ans = maxflow();
 
    //cout<<ans<<endl;
 
    if(ans != s2){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
 
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=n;j++){
                cout<<cap[n+j][i]<<" ";
            }cout<<endl;
        }
 
    }
 
 
 
}
 
 
