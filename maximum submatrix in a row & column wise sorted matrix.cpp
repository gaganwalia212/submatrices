//function to calculate the sum of all the given sub-matrices
#include<iostream>
using namespace std;

void maximum_submatrix(int**a,int m,int n)
{
int maximum=INT_MIN;
int li,lj;
for(int i=0;i<m;i++)
{
    for(int j=0;j<n;j++)
    {
        if(a[i][j]>maximum)
        {
            maximum=a[i][j];
            li=i;
            lj=j;
        }
    }
}
cout<<"( "<<li<<","<<lj<<")"<<" ("<<m-1<<","<<n-1<<")"<<endl;
}

void postfix_sum_matrix(int**a,int m,int n)
{
   //row wise addition
   for(int i=m-2;i>=0;i--)
   {
       for(int j=0;j<n;j++)
        a[i][j]+=a[i+1][j];
   }

   //column wise addition
   for(int j=n-2;j>=0;j--)
   {
       for(int i=0;i<m;i++)
        a[i][j]+=a[i][j+1];
   }
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
     postfix_sum_matrix(a,m,n);
    maximum_submatrix(a,m,n);


     for(int i=0;i<m;i++)
        delete[]a[i];
     delete[]a;
 }
