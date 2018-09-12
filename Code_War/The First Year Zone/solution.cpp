#include <iostream>
#include <math.h>
#include <stdio.h>
#include <unordered_set>
 
#define S scanf
#define LLD long int
using namespace std;
 
LLD sum(unordered_set <LLD> s)
{
    LLD retval=0;
    for (auto it : s) 
        retval += it;
    return retval;
}
 
bool is_pal(LLD num)
{
    LLD rev=0,digit,n;
    n = num;
    do
     {
         digit = num % 10;
         rev = (rev * 10) + digit;
         num = num / 10;
     } while (num != 0);
    
    return (n == rev);
}
int main()
{
    LLD t,i,j,n,d,num,root;
    unordered_set <LLD> s;
    scanf("%ld",&t);
    while(t)
    {
        scanf("%ld %ld",&n,&d);
        root = sqrt(n);
        for(i=1;i <root;i++)
        {
            num = i*i;
            for(j=i+d;j<root;j+=d)
            {
                //cout << num << endl;
                num += j*j;
                if(num >= n)
                    break;
                //cout << num << endl;
                if(is_pal(num))
                {
                    //printf("%lld ",num);
                    s.insert(num);
                }
            }
        }
        
        cout << sum(s) << endl;
        s.clear();
        t--;
    }
}
