/* winners never quit and quitters never win.
      #swap                                 */
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#pragma GCC optimize ("-O3")
#define mod 1000000007
#define inf 1000000000000000000
#define rk 256
#define pb push_back
#define mp make_pair
#define vc vector
#define fs first
#define sec second
#define pq priority_queue
#define lb lower_bound
#define ub upper_bound
#define pll pair<ll,ll> 
#define pls pair<ll,string>
#define psl pair<string,ll>
#define plc pair<ll,char>
#define pcl pair<char,ll>
#define pss pair<string,string>
#define all(v) v.begin(),v.end()
#define tol(s) transform(s.begin(),s.end(),s.begin(),::tolower);
#define tou(s) transform(s.begin(),s.end(),s.begin(),::toupper);
#define T ll t=0;cin>>t;for(ll test=0;test<t;test++)
 
ll pr[1000001]={0};
 
void build(vector<ll> &seg,vector<ll> &sum,ll x[],ll low,ll high,ll pos)
{
    if(low==high)
    {
        seg[pos]=x[low];
        sum[pos]=x[low];
        return;
    }
    ll mid=(low+high)/2;
    build(seg,sum,x,low,mid,2*pos+1);
    build(seg,sum,x,mid+1,high,2*pos+2);
    seg[pos]=max(seg[2*pos+1],seg[2*pos+2]);
    sum[pos]=sum[2*pos+1]+sum[2*pos+2];
}
 
void update(vector<ll> &seg,vector<ll> &sum,ll qlow,ll qhigh,ll low,ll high,ll pos)
{
    if(low>high or qlow>high or qhigh<low)
        return;
    if(seg[pos]<=2)
        return;
    if(low==high)
    {
        seg[pos]=pr[seg[pos]];
        sum[pos]=seg[pos];
        return;
    }
    ll mid=(low+high)/2;
    update(seg,sum,qlow,qhigh,low,mid,2*pos+1);
    update(seg,sum,qlow,qhigh,mid+1,high,2*pos+2);
    seg[pos]=max(seg[2*pos+1],seg[2*pos+2]);
    sum[pos]=sum[2*pos+1]+sum[2*pos+2];
}
 
ll query(vector<ll> &sum,ll qlow,ll qhigh,ll low,ll high,ll pos)
{
    if(low>high or qlow>high or qhigh<low)
        return 0;
    if(qlow<=low and qhigh>=high)
    {
        return sum[pos];
    }
    ll mid=(low+high)/2;
    return query(sum,qlow,qhigh,low,mid,2*pos+1)+query(sum,qlow,qhigh,mid+1,high,2*pos+2);
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    for(ll a=1;a<=1000000;a++)
    {
        for(ll b=a;b<=1000000;b+=a)
            pr[b]++;
    }
	//coeff();
	/*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    ll n,m;
    cin>>n>>m;
    vector<ll> seg(4*n,0),sum(4*n,0);
    ll x[n];
    for(ll a=0;a<n;a++)
        cin>>x[a];
    build(seg,sum,x,0,n-1,0);
    while(m--)
    {
        ll t,l,r;
        cin>>t>>l>>r;
        l--,r--;
        if(t==1)
        {
            update(seg,sum,l,r,0,n-1,0);
        }
        else
        {
            cout<<query(sum,l,r,0,n-1,0)<<endl;
        }
    }
	return 0;
}
