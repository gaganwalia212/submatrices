//function to calculate the sum of all the given sub-matrices
#include<iostream>
using namespace std;
//sum of each sub-matrix
//O(n^2)time complexity
 int cal_sum(int**a,int li,int lj,int bi,int bj)
 {

     int s=0;
     for(int i=li;i<=bi;i++)
     {
         for(int j=lj;j<=bj;j++)
            {
                s+=a[i][j];
            }

     }

     return s;
 }

 //finding all the possible sub-matrices
 //each sub-matrix can be represented by two elements:
 //1. the top left element-li,lj
 //2. the bottom right element- bi,bj
 //bi>=li and bj>=lj
 int sum_submatrix(int ** a,int m,int n)
 {
     int sum=0;
     //first two iterations for top left element
     for(int li=0;li<m;li++)
     {
         for(int lj=0;lj<n;lj++)
         {
             //next two iterations for finding bottom right element
             for(int bi=li;bi<m;bi++)
             {
                 for(int bj=lj;bj<n;bj++)
                    sum=sum+cal_sum(a,li,lj,bi,bj);

             }
         }
     }
     return sum;
 }
 //overall time complexity-O(n^6)..brute force method

 int main()
 {
     int m,n;
     cin>>m>>n;
     int ** a=new int *[m];
     for(int i=0;i<m;i++)
        a[i]=new int [n];
     for(int i=0;i<m;i++)
     {
         for(int j=0;j<n;j++)
            cin>>a[i][j];
     }

     cout<<sum_submatrix(a,m,n)<<endl;
     for(int i=0;i<m;i++)
        delete[]a[i];
     delete[]a;
 }
