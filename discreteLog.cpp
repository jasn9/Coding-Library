
#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
typedef long double ld;

ll power(ll a,ll b,ll m)
{
    ll r = 1;
    while(b>0)
    {
        if(b%2 == 1)
        {
            r = (r*a)%m;
        }
        a = (a*a)%m;
        b = b/2;
    }
    return r;
}

ll discreteLog(ll a,ll b,ll m)
{
    ll n = ll(sqrt(m+0.0))+1;
    
    // a^(np) = b*a^(q) 
	
    map <ll,ll> mp;
    // q
    for(ll i=0;i<=n;i++)
    {
        mp[(m+(power(a,i,m)*b)%m)%m] = i;
        
    }
    
    // p
    for(ll i=1;i<=n;i++)
    {
        ll val = power(a,i*n,m);
        if(mp.find(val)!=mp.end())
        {
            ll ans = n*i-mp[val];
            return ans;
        }
    }
    
    return -1;
    
    
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    ll T;
    cin>>T;
    
    while(T--)
    {
        ll r,s,p;
        cin>>r>>s>>p;
        // r^x = s (mod p)
        
        ll x = discreteLog(r,s,p);
        
    }
    
}
