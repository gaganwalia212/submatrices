//finding sum of all possible sub-matrices
//O(n^4)
#include<iostream>
using namespace std;
//store cumulative sum in matrix
void convert_to_cummulative(int ** a,int m,int n)
{
    //storing cumulative sum column wise
    for(int i=0;i<m;i++)
    {
        for(int j=1;j<n;j++)
            a[i][j]+=a[i][j-1];
    }
    //storing cumulative sum row wise
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<m;j++)
            a[j][i]+=a[j-1][i];
    }
}

//sum of sub-matrix
//each element (i,j) represents the sum of sub-matrix from (0,0) to(i,j)
//for any (li,lj) and (bi,bj) in a cumulative matrix
//required sum=a[bi][bj]-a[li-1][bj]-a[bi][lj-1]+a[li-1][lj-1]
int sum_submatrix(int ** a,int m,int n)
{
    int s=0;
    for(int li=0;li<m;li++)
    {
        for(int lj=0;lj<n;lj++)
        {
            for(int bi=li;bi<m;bi++)
            {
                for(int bj=lj;bj<n;bj++)
                {
                    if(li&&lj)
                        s+=a[bi][bj]-a[li-1][bj]-a[bi][lj-1]+a[li-1][lj-1];
                    else if(!li&&!lj)
                        s+=a[bi][bj];
                    else if(!li&&lj)
                        s+=a[bi][bj]-a[bi][lj-1];
                    else if(li&&!lj)
                        s+=a[bi][bj]-a[li-1][bj];


                }
            }
        }

    }
    return s;
}

int main()
{
    int m,n ,**a;
    cin>>m>>n;
    a=new int * [m];
    for(int i=0;i<m;i++)
        a[i]=new int [n];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
            cin>>a[i][j];
    }
    convert_to_cummulative(a,m,n);

    cout<<sum_submatrix(a,m,n)<<endl;
    for(int i=0;i<m;i++)
        delete[]a[m];
    delete []a;
}
