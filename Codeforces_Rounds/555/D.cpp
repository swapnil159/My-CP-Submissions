/* winners never quit and quitters never win.
      #swap                                 */
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    
    ll n,k;
    cin>>k>>n;
    ll x[n];
    ll sum=0;
    for(ll a=0;a<n;a++)
    {
        x[a]=a+1;
        sum+=x[a];
    }
    if(sum>k)
    {
        cout<<"NO\n";
        exit(0);
    }
    ll rem=k-sum;
    ll inc[n]={0};
    for(ll a=0;a<n;a++)
    {
        if(a and x[a]==2*(x[a-1]+inc[a-1]))
            continue;
        inc[a]=rem/(n-a);
        if(inc[a]>0)
            rem=rem%(n-a);
    }
    x[n-1]+=rem;
    ll po=0;
    for(ll a=0;a<n;a++)
    {
        po+=inc[a];
        x[a]+=po;
    }
    bool flag=false;
    for(ll a=1;a<n;a++)
    {
        if(x[a]<=x[a-1] or x[a]>2*x[a-1])
            flag=true;
    }
    if(flag)
        cout<<"NO\n";
    else
    {
        cout<<"YES\n";
        for(ll a=0;a<n;a++)
            cout<<x[a]<<" ";
        cout<<endl;
    }
	return 0;
}
