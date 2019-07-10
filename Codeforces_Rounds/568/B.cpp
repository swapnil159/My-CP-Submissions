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
vc<ll> solve(string s)
{
    ll n=s.length();
    ll cnt=1;
    vc<ll> ans;
    for(ll a=1;a<n;a++)
    {
        if(s[a]==s[a-1])
            cnt++;
        else
        {
            ans.pb(cnt);
            cnt=1;
        }
        
    }
    ans.pb(cnt);
    return ans;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
	//isprime();
	//coeff();
	/*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    T
    {
        string s1,s2;
        cin>>s1>>s2;
        vc<ll> v1=solve(s1),v2=solve(s2);
        if(v1.size()!=v2.size())
        {
            cout<<"NO\n";
        }
        else
        {
            ll p=1,i=0,j=0;
            for(int a=0;a<v1.size();a++)
            {
                i+=v1[a],j+=v2[a];
                if(s2[j-1]!=s1[i-1] or v2[a]<v1[a])
                    p=0;
            }
            if(p)
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
    }
	return 0;
}
