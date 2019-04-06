//SDOJ #2583 ÊÖÌ×
//Language:C++

#include <cstdio>
#include <algorithm>

int a[10086]={0};
int tmp[10086]={0},ans=0;

void Merge(int l,int m,int r)  {  
    int i = l;   
    int j = m + 1;   
    int k = l;   
    while(i <= m && j <= r)   
	   {   
	          ans += 1; 
        if(a[i] > a[j])        
		  {   
            tmp[k++] = a[j++];   
          }   
        else          
	  	{   
            tmp[k++] = a[i++];   
        }   
    }   
    while(i <= m) tmp[k++] = a[i++];   
    while(j <= r) tmp[k++] = a[j++];   
    for(int i=l;i<=r;i++)   
        a[i] = tmp[i];   
}

void Merge_sort(int l,int r) 
  
{   

    if(l < r)   
    {   
        int m = (l + r) >> 1;

        Merge_sort(l,m);   
        Merge_sort(m+1,r);   
        Merge(l,m,r);   
    }   
} 

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=2*n;i++)
	{
		scanf("%d",&a[i]);
	}
	Merge_sort(a[1],a[n]);
	printf("%d",ans);
	return 0;
}
