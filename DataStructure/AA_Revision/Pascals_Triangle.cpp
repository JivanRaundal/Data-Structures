//Pascal's Triangle

#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"\nHow many rows ? ";
    cin>>n;

    int i,j,val;
    for(i=0; i<n; i++)
    {
        val = 1;        // iCo = 1;
        for(j=0; j<=i; j++)
        {
            cout<<" "<<val;           
            val = val * (i-j) / (j+1);      //i.e. iCj+1 = iCj * (i-j) / (j+1); 
        }
        cout<<"\n";
    }

    return 0;
}