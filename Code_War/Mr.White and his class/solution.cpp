#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    // ifstream fin;
    // fin.open("t8.txt");
 
    // ofstream f;
    // f.open("a8.txt");
 
    int t;
    cin >> t;
    // fin>>t;
    while(t--)
    {
        long long a,b,n,ans;
        cin>>a>>b>>n;
        // fin>>a>>b>>n;
        switch(n%6)
        {
            case 0:
                ans=a-b;break;
            case 1:
                ans=a;break;
            case 2:
                ans=b;break;
            case 3:
                ans=b-a;break;
            case 4:
                ans=-a;break;
            case 5:
                ans=-b;break;
        }
        //ans=ans%M;
        //f << ans << '\n';
        if(ans<0)
        {
        	ans=ans%M+M;
        }    
        ans = ans%M;
        // f<<ans<<'\n';
        cout<<ans<<'\n';
    }
    // fin.close();
    // f.close();
    return 0;
}    
