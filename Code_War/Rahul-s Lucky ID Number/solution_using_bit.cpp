#include <bits/stdc++.h>
using namespace std;
using lint=long long int;
/*
    Given n numbers, find how many numbers are not of the form 2^x+2^y (x!=y) exist in the range [l,r] to be provided.
*/
unordered_set<lint> req;
lint n;
void pre_compute(int N)
{
    for(int i=1;i<=N;i=i*2)
    {
        for(int j=i*2;j<=N;j=j*2){
            req.insert(i+j);
        }
    }
}
 
void insert(lint arr[],lint bit[],lint val,lint i)
{
    arr[i]=val;
    if(req.find(val) != req.end())
    {
        while(i<=n){
            bit[i]++;
            i+=(i&-i);
        }
    }
}
void update(lint arr[],lint bit[],lint i,lint val)
{
    if(req.find(val) != req.end()){
        for(;i<=n;i+=(i&(-i)))
        {
            bit[i] ++;
        }
    }
}
void update_sub(lint arr[],lint bit[],lint i,lint val)
{
    for(;i<=n;i+=(i&(-i)))
    {
        bit[i] --;
        //if(bit[i] < 0)
          //  bit[i]=0;
    }
}
lint get_sum(lint bit[],lint i)
{
    lint sum=0;
    for(;i>0;i-=(i&(-i))){
        sum += bit[i];
    }
    return sum;
}
 
int main(){
    lint t,i,temp;
    pre_compute(1000000001); //save all numbers of the form 2^x+2^y x!=y x >= 0 y >= 0
    cin>>t;
    while(t--)
    {
        cin>>n;
        lint arr[n+1],bit[n+1]={0};
        for(i=1;i<=n;i++)
        {
            cin>>temp;
            insert(arr,bit,temp,i);
        }
        lint q;
        cin>>q;
        while(q--)
        {
            lint ch,x,y;
            cin>>ch>>x>>y;
            switch(ch)
            {
                case 1:
                        if((req.find(arr[x]) != req.end() and req.find(y) != req.end()))
                        {
                            arr[x]=y;
                        }
                        else if(req.find(arr[x]) == req.end() and req.find(y) == req.end())
                        {
                            arr[x]=y;
                        }
                        else if(req.find(arr[x]) != req.end() and req.find(y) == req.end())
                        {
                            arr[x]=y;
                            update_sub(arr,bit,x,y);
                        }
                        else
                        {
                            arr[x]=y;
                            update(arr,bit,x,y);
                        }
                        break;
                case 2:
                        if(y < x)
                        {
                            cout << "0\n";
                        }else
                            cout<<get_sum(bit,y)-get_sum(bit,x-1)<<endl;
                        break;
            }
        }
    }
    return 0;
}
