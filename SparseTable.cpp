
// https://cses.fi/problemset/task/1647

#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize ("-ffloat-store")  
#pragma GCC optimize ("-fno-defer-pop")
typedef long long int ll; 
typedef long double ld; 
 
 
int main()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	ll n,q;
	cin>>n>>q;
	
	ll arr[n+1];
	
	for(ll i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	ll presum[n+1];
	presum[0] = 0;
	
	for(ll i=0;i<n;i++)
	{
		presum[i+1] = presum[i]+arr[i];
	}
	
	while(q--)
	{
		ll a,b;
		cin>>a>>b;
		
		cout<<presum[b]-presum[--a]<<endl;
		
	}
	
}
