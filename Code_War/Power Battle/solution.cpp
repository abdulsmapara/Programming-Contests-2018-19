#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;

ld power(ll base,ll power)
{
    ld retval;
    if(base>0)
    {
        retval=power*log10(base);
    }
    else if(base==0)
        retval=0;
    return retval;
}
int compare(ll a,ll x,ll b,ll y)
{
    ld ans1,ans2;
    int retval;
    ans1=power(a,x);
    ans2=power(b,y);
    cout<<ans1<<" "<<ans2<<endl;
    if(ans1>ans2)
        retval = 1;
    else if(ans1< ans2)
		retval = -1;
	else 
		retval = 0;
    cout<<retval<<endl;
    return retval;
}
int main() {
	int i,t;
	ll a,x,b,y;
	cin>>t;
	for(i=0;i<t;i++)
	{
	    cin>>a;
	    cin>>x;
	    cin>>b;
	    cin>>y;
	    if(compare(a,x,b,y)==1)
	        cout<<"Samkit"<<endl;
	    else if(compare(a,x,b,y)==-1)
	        cout<<"Sanshul"<<endl;
	    else
		cout<<"Draw"<<endl;
	}
	return 0;
}
