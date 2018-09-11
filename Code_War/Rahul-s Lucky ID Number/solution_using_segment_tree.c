/*
  Solution accepted in Code_War contest using segment tree
*/
/*
  Implementation of segment tree is taken from https://www.geeksforgeeks.org/
*/
#include <stdio.h>
#include <math.h> 
#include <stdlib.h>
int getMid(int s, int e) { return s + (e -s)/2; } 
int getSumUtil(int *st, int ss, int se, int qs, int qe, int si) 
{ 
    if (qs <= ss && qe >= se) 
        return st[si]; 
    if (se < qs || ss > qe) 
        return 0; 
    int mid = getMid(ss, se); 
    return getSumUtil(st, ss, mid, qs, qe, 2*si+1) + 
        getSumUtil(st, mid+1, se, qs, qe, 2*si+2); 
} 
void updateValueUtil(int *st, int ss, int se, int i, int diff, int si) 
{ 
    // Base Case: If the input index lies outside the range of 
    // this segment 
    if (i < ss || i > se) 
        return; 
 
    // If the input index is in range of this node, then update 
    // the value of the node and its children 
    st[si] = st[si] + diff; 
    if (se != ss) 
    { 
        int mid = getMid(ss, se); 
        updateValueUtil(st, ss, mid, i, diff, 2*si + 1); 
        updateValueUtil(st, mid+1, se, i, diff, 2*si + 2); 
    } 
} 
 
// The function to update a value in input array and segment tree. 
// It uses updateValueUtil() to update the value in segment tree 
void updateValue(int arr[], int *st, int n, int i, int new_val) 
{ 
    // Check for erroneous input index 
    if (i < 0 || i > n-1) 
    { 
        return; 
    } 
 
    // Get the difference between new value and old value 
    int diff = new_val - arr[i]; 
 
    // Update the value in array 
    arr[i] = new_val; 
 
    // Update the values of nodes in segment tree 
    updateValueUtil(st, 0, n-1, i, diff, 0); 
} 
 
// Return sum of elements in range from index qs (quey start) 
// to qe (query end). It mainly uses getSumUtil() 
int getSum(int *st, int n, int qs, int qe) 
{ 
    // Check for erroneous input values 
    if (qs < 0 || qe > n-1 || qs > qe) 
    {  
        return 0; 
    } 
 
    return getSumUtil(st, 0, n-1, qs, qe, 0); 
} 
 
// A recursive function that constructs Segment Tree for array[ss..se]. 
// si is index of current node in segment tree st 
int constructSTUtil(int arr[], int ss, int se, int *st, int si) 
{ 
    // If there is one element in array, store it in current node of 
    // segment tree and return 
    if (ss == se) 
    { 
        st[si] = arr[ss]; 
        return arr[ss]; 
    } 
 
    // If there are more than one elements, then recur for left and 
    // right subtrees and store the sum of values in this node 
    int mid = getMid(ss, se); 
    st[si] = constructSTUtil(arr, ss, mid, st, si*2+1) + 
            constructSTUtil(arr, mid+1, se, st, si*2+2); 
    return st[si]; 
} 
 
/* Function to construct segment tree from given array. This function 
allocates memory for segment tree and calls constructSTUtil() to 
fill the allocated memory */
int *constructST(int arr[], int n) 
{ 
    // Allocate memory for the segment tree 
 
    int x = (int)(ceil(log2(n))); 
 
    int max_size = 2*(int)pow(2, x) - 1; 
 
    int *st = (int*)malloc(max_size*sizeof(int)); 
 
    constructSTUtil(arr, 0, n-1, st, 0); 
 
    return st; 
} 
 
long long int countBits(long long int x)
{
    long long int count = 0;
    while(x > 0)
    {
        if( x%2 == 1 )
        {
            count++; 
        }
        x = x / 2;
    }
    return count;
}
int main() 
{
    int t;
    scanf("%d",&t); 
    while(t--)
    {
        int n;
        long long int x;
        scanf("%d",&n);
        int *b = (int*)malloc((n)*sizeof(int));
         
        for (int i = 0; i <n ; ++i)
        {
            scanf("%lld",&x);
            if(countBits(x) == 2)
            {
                b[i] = 1;
            }
            else
            {
                b[i] = 0;
            }
        }
 
        int *st = constructST(b, n);  
 
        long long int que,m,p,q;
        scanf("%lld",&que);
 
        for (int i = 0; i < que; ++i)
        {
            scanf("%lld %lld %lld",&m,&p,&q);
            if(m == 1)
            {     
                int one = 1 , zero = 0;
                
                if( countBits(q) == 2 )
                {
                    updateValue(b , st , n , p-1 , one); 
                }
                else
                {
                    updateValue(b , st , n , p-1 , zero);                     
                }
            }
            else
            {
                printf("%d\n",getSum(st, n, p-1, q-1));  
            }
        }
    }
 
    return 0; 
} 
