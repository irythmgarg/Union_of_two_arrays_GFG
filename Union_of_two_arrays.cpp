/*
Given two arrays a[] and b[] of size n and m respectively. The task is to find the number of elements in the union between these two arrays.
Union of the two arrays can be defined as the set containing distinct elements from both the arrays.
 If there are repetitions, then only one occurrence of element should be printed in the union.

Input:
5 3
1 2 3 4 5
1 2 3
Output: 
5
Explanation: 
1, 2, 3, 4 and 5 are the
elements which comes in the union set
of both arrays. So count is 5.

*/
#include<iostream>
using namespace std;
#include<vector>
 int doUnion(int a[], int m, int b[], int n) 
  {
     vector<int>v;
     int i=0;//first pointer
     int j=0;//second pointer
      while(i<m and j<n)
     {
     
      if(a[i]<=b[j])
          {
               if(v.empty() ||v[v.size()-1]!=a[i])
               {
                     v.push_back(a[i]);  
               }
               i++;
          }
          else 
          {
               if(v.empty() ||v[v.size()-1]!=b[j])
               {
                     v.push_back(b[j]); 
               }
               j++;
          }   
     }
     while(i<m)// if i is still <m
     {
           if(v.empty() ||v[v.size()-1]!=a[i])
               {
                     v.push_back(a[i]);    
               } i++;
     }
     while(j<n)// if j is still <n
     {
           if(v.empty() ||v[v.size()-1]!=b[j])
               {
                     v.push_back(b[j]);
               }
                j++;
     }
     return v.size();
    }
int main()
{
     int m;//no of elements in first array
     cin>>m;
     int n;//no of elements in second array
     cin>>n;
     int a[m];//first array
        int b[n];//second array
        for(int i=0;i<m;i++)
        {
             cin>>a[i];
        }
        for(int i=0;i<n;i++)
        {
           cin>>b[i];
        }
        cout<<doUnion(a,m,b,n);//size of union of arrays
}