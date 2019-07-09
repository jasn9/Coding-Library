 
 // https://codeforces.com/contest/1016/problem/B
 
 #include<bits/stdc++.h>

using namespace std;
typedef long long int ll;

#define endl '\n'


int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n,m,q;
    cin>>n>>m>>q;
    string s,t;
    cin>>s>>t;

    string k;
    k+=t;
    k+="#";
    k+=s;
    ll pi[k.size()+1];

    memset(pi,0,sizeof(pi));

    for(ll i=1;i<k.size();i++){

        ll j = pi[i-1];

        while(j>0 and k[i]!=k[j]){
            j = pi[j-1];
        }
        if(k[i]==k[j]){
            j++;
        }
        pi[i] = j;

    }

    // KMP ALGO ABOVE


    ll cou[n+m+2];
    memset(cou,0,sizeof(cou));
    for(ll i=0;i<=m+n+1;i++){
        if(pi[i]==m){
            cou[i-2*m] = 1;
        }
    }

    for(ll i=1;i<=m+n+1;i++){
    //    cout<<cou[i]<<" ";
        cou[i]+=cou[i-1];
    }
    //cout<<endl;

    while(q--){
        ll a,b;cin>>a>>b;
        a--;
        b-=m;
        //cout<<a<<" "<<b<<endl;
        if(b<0){
            cout<<0<<endl;continue;
        }
        if(a<1){
            cout<<cou[b]<<endl;continue;
        }
        cout<<max(0LL,cou[b]-cou[a-1])<<endl;
    }

}







