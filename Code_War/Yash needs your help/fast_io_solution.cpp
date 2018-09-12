#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
#define lint int
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	lint t;
	cin >> t;
	while(t--){

		lint n,val,maxi;
		cin >> n;
		unordered_map<lint,lint> freq;

		//1st input
		cin >> val;
		maxi=val;
		freq[val]++;
		printf("%d\n",maxi);
		//fprintf(fp,"%d\n",maxi);
		//n-1 inputs
		for(lint i=1;i<n;i++){

			cin >> val;
			freq[val]++;
			if(freq[val] > freq[maxi])
			{
				maxi = val;
			}
			else if(freq[val] == freq[maxi])
			{
				if(val < maxi)
					maxi = val;
			}

		printf("%d\n",maxi);			//fprintf(fp,"%d\n",maxi);

		}


	}
	return 0;
}
