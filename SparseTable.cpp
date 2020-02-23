
// https://cses.fi/problemset/task/1647

#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize ("-ffloat-store")  
#pragma GCC optimize ("-fno-defer-pop")
typedef long long int ll; 
typedef long double ld; 
 
ll dp[200005][22];
 
 
int main()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	memset(dp,-1,sizeof(dp));
	ll n,q;
	cin>>n>>q;
	
	ll arr[n+1];
	
	for(ll i=0;i<n;i++)
	{
		cin>>arr[i];
		dp[i][0] = arr[i];
	}
	//cout<<"iop"<<endl;
	for(ll i=1;i<=18;i++)
	{
		for(ll j=0;j<n;j++)
		{
			//cout<<i<<" "<<j<<" "<<(j+(1LL<<(i-1)))<<endl;
			if((((1LL<<(i-1))+j) <= n) and dp[j+(1LL<<(i-1))][i-1]>0 and dp[j][i-1]>0)
			dp[j][i] = min(dp[j][i-1],dp[j+(1LL<<(i-1))][i-1]); 
		}
	}
	//cout<<"io"<<endl;
	while(q--)
	{	
		ll a,b;
		cin>>a>>b;
		
		ll v = log(b-a+1)/log(2);
		//cout<<v<<endl;
		cout<<min(dp[a-1][v],dp[b-1-(1LL<<v)+1][v])<<endl;	
 
		
	}
	
	
}
