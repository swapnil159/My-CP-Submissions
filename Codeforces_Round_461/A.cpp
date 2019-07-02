#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define vc vector
#define fs first
#define sec second
#define pq priority_queue
 
int main() {
    ios_base::sync_with_stdio(false);
	ll x=0,y=0;
	cin>>x>>y;
	if(!y || (y==1 && x>0))
	{
	    cout<<"No\n";
	}
	else
	{
	    y--;
	    x-=y;
	    if(x&1 || x<0)
	    {
	        cout<<"No\n";
	    }
	    else
	    {
	        cout<<"Yes\n";
	    }
	}
	return 0;
}
