#include <iostream>
using namespace std;

int binarySearch(int[], int, int, int);

int main()
{
   int num[10] = {60,61,62,63,64,65};
   int search_num, loc=-1;

   cout<<"Enter the Roll number that you want to search in Data base: ";
   cin>>search_num;

   loc = binarySearch(num, 0, 6, search_num);

   if(loc != -1)
   {
      cout<<search_num<<" Roll number found in the Data base at the location: "<<loc<<endl;
      cout<<"mahins-MacBook-Air:~ mahinmittal$ ";
   }
   else
   {
      cout<<"Roll number  not found";
   }
   return 0;
}

int binarySearch(int a[], int first, int last, int search_num)
{
   int middle;
   if(last >= first)
   {
 middle = (first + last)/2;

      if(a[middle] == search_num)
      {
         return middle+1;
      }


      else if(a[middle] < search_num)
      {
         return binarySearch(a,middle+1,last,search_num);
      }


      else
      {
         return binarySearch(a,first,middle-1,search_num);
      }

   }
   
   return -1;
}
