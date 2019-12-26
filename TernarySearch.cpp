
// https://www.codechef.com/problems/AMCS03

#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
typedef long double ld;
 
ll arr[100005][2];
ll n,k;
long double cost(long double t)
{
	long double ma = -1,mi = -1;
	for(ll i=0;i<n;i++)
	{
		long double temp = arr[i][0]*t+arr[i][1];
		if(i==0)
		{
			ma = temp;
			mi = temp;
		}
		ma = max(ma,temp);
		mi = min(mi,temp);
	}
	return (ma-mi);
}
    
int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin>>n>>k;
    
    
    for(ll i=0;i<n;i++)
    {
		cin>>arr[i][0]>>arr[i][1];
	}
	
	long double l = 0;
	long double r = k;
	long double eps = 1e-9; 
	
	while((r-l)>eps)
	{
		long double m1 = l+(r-l)/3.0;
		long double m2 = r-(r-l)/3.0;
		//ll f1 = cost(m1);
		//ll f2 = cost(m2);
		
		if(cost(m1)>cost(m2))
		{
			l = m1;
		}
		else{
			r = m2;
		}
	}
	
	cout<<fixed<<setprecision(6)<<cost(l)<<endl;
    
    
}
