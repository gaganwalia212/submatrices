//function to calculate the sum of all the given sub-matrices
#include<iostream>
using namespace std;

//count that in how sub-matrices is an element occurs
//remember that each sub-matrix is represented by top left and bottom right element
//for an element (i,j)..i>=li and j>=lj and i<=bi and j<=bj
//so total number of candidates for top left elements=(i+1)*(j+1)
//similarly total number of candidates for bottom left elements=(m-i)*(n-j)
//O(n^2) time
int sum_submatrix(int ** a,int m,int n)
 {
     int sum=0;
   for(int i=0;i<m;i++)
   {
       for(int j=0;j<n;j++)
       {
           int no_of_submatrices=(i+1)*(j+1)*(m-i)*(n-j);
           sum+=a[i][j]*no_of_submatrices;
       }
   }
     return sum;
 }

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
