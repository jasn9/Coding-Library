//  https://www.spoj.com/problems/MKTHNUM/

#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
typedef long double ld;
 
vector <ll> segtree[5*100005];
vector < pair <ll,ll> > vec;
 
 
vector <ll> merge(vector <ll> a,vector <ll> b)
{
	
	vector <ll> temp;
	a.push_back(1e18);
	b.push_back(1e18);
	ll p = 0;
	ll q = 0;
	for(ll i=0;i<a.size()+b.size()-2;++i)
	{
		if(a[p]<b[q])
		{
			temp.push_back(a[p]);
			p++;
		}
		else{
			temp.push_back(b[q]);
			q++;
		}
	}
	a.pop_back();
	b.pop_back();
	return temp;
	
} 	
	
void build(ll l,ll r,ll ind)
{
	if(l==r)
	{
		segtree[ind].push_back(vec[l].second);
		return;
	}
	
	ll mid = l+(r-l)/2;
	build(l,mid,2*ind+1);
	build(mid+1,r,2*ind+2);
	
	segtree[ind] = merge(segtree[2*ind+1],segtree[2*ind+2]);
	
	
	
}
 
ll query(ll l,ll r,ll ql,ll qr,ll k,ll ind)
{
	
	if(l==r){
		return segtree[ind][0];
	}
 
	ll mid = l+(r-l)/2;
	
	auto it = upper_bound(segtree[2*ind+1].begin(),segtree[2*ind+1].end(),qr);
	ll x = it-lower_bound(segtree[2*ind+1].begin(),segtree[2*ind+1].end(),ql);
	
	if(x>=k){
		
		return query(l,mid,ql,qr,k,2*ind+1);
	}
	else{
		return query(mid+1,r,ql,qr,k-x,2*ind+2);
	}
	
}
 
int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	ll n,q;
	cin>>n>>q;
	ll arr[n];
	
	
	
	for(ll i=0;i<n;i++){
		cin>>arr[i];
		vec.push_back({arr[i],i});
	}
	sort(vec.begin(),vec.end());
	build(0,n-1,1);
	
	while(q--)
	{
		ll i,j,k;
		cin>>i>>j>>k;
		i--;j--;
		ll id = query(0,n-1,i,j,k,1);
		//cout<<"*"<<id<<endl;
		cout<<arr[id]<<endl;
	}
    
}
