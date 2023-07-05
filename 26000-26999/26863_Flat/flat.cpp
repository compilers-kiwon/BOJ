#include    <iostream>
#include    <set>

using namespace std;

#define MAX_SIZE    4

bool    same_length(int arr[])
{
    set<int>    s;

    for(int i=1;i<=MAX_SIZE;i++)
    {
        s.insert(arr[i]);
    }

    return  (s.size()==1);
}

int input(int legs[],int& pad)
{
    for(int i=1;i<=MAX_SIZE;i++)
    {
        cin>>legs[i];
    }

    cin>>pad;

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int a[MAX_SIZE+1],b;
    
    input(a,b);

    if( same_length(a) == true )
    {
        cout<<"1\n";
        return  0;
    }
    
    for(int i=1;i<=MAX_SIZE;i++)
    {
        a[i] += b;

        if( same_length(a) == true )
        {
            cout<<"1\n";
            return  0;
        }

        a[i] -= b;
    }

    cout<<"0\n";
    return  0;
}