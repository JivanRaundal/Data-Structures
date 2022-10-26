// WAP to insert element inside the array in such a way that array remains sorted.

#include<iostream>
using namespace std;

int main()
{
    int num[8] = {3,7,11,15};
    int front = 0;
    int rear = 3;

    cout<<"\nBEFORE\n";
    for(int i=front; i<=rear; i++)
    {
        cout<<" "<<num[i];
    }

    int x;
    cout<<"\nEnter element : ";
    cin>>x;
    int i;
    for(i=rear; i>=front && num[i]>x; i--)
    {
        num[i+1] = num[i];
    }
    num[i+1] = x;
    rear++;

    cout<<"\n\nAFTER\n";
    for(int i=front; i<=rear; i++)
    {
        cout<<" "<<num[i];
    }

    return 0;
}