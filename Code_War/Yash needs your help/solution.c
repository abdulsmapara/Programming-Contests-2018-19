/*
	Editorial for que 1
	Link to the que: https://www.hackerearth.com/problem/algorithm/yashs-bro-needs-your-help/ 
*/
#include <stdio.h>
#define MAXN 10000
int main(){

	int t;
	scanf("%d",&t);
	while(t--){

		int n,val,maxi;
		scanf("%d",&n);
		int freq[2*MAXN+1]={0};

		//1st input
		scanf("%d",&val);
		maxi=val;
		freq[val+MAXN]++;
		printf("%d\n",maxi);
		//n-1 inputs
		for(int i=1;i<n;i++){

		  scanf("%d",&val);
			freq[val+MAXN]++;
			if(freq[val+MAXN] > freq[maxi+MAXN])
			{
				maxi = val;
			}
			else if(freq[val+MAXN] == freq[maxi+MAXN])
			{
				if(val < maxi)
					maxi = val;
			}

		printf("%d\n",maxi);
		}


	}
	return 0;
}
