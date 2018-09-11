#include <stdio.h>
int main()
{
    long long int t;
    scanf("%lld",&t);
    while(t--)
    {
        long long int a,x,b,y;
        scanf("%lld%lld%lld%lld",&a,&x,&b,&y);
        double first=x*log10(a);
        
        double second=y*log10(b);
        
        if(first < second)
        {
            //cout << "Sanshul\n";
            printf("Sanshul\n");
        }
        else if(first==second)
        {
            printf("Draw\n");
        }
        else
        {
            printf("Samkit\n");
        }
    }
    return 0;
}
