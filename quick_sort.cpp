#include<bits/stdc++.h>
using namespace std;
int partition(int *a,int start,int end)
{
    int pivot=a[end];
    
    
    int P_index=start;
    int i,t; 
    for(i=start;i<end;i++)
    {
    	if(a[i]<=pivot)
        {
            t=a[i];
            a[i]=a[P_index];
            a[P_index]=t;
            P_index++;
        }
     }
     
      t=a[end];
      a[end]=a[P_index];
      a[P_index]=t;
    
  
     return P_index;
 }
 void Quicksort(int *a,int start,int end)
 {
    if(start<end)
    {
         int P_index=partition(a,start,end);
             Quicksort(a,start,P_index-1);
             Quicksort(a,P_index+1,end);
    }
}
int main()
{
    int n;
        cout<<"Enter count  of Roll number you wat to Sort: ";
        cin>>n;
        int a[n];
        cout<<"Enter Roll number one-by-one:\n";
        for(int i=0;i<n;i++)
       {
    	 cin>>a[i];
       }
      Quicksort(a,0,n-1);
      cout<<"Sorted list of Roll numbers:\n";
      for(int i=0;i<n;i++)
      {
    	 cout<<a[i]<<" "<<endl;
      }
     cout<<" mahins-MacBook-Air:~ mahinmittal$ ";
    return 0;
}
