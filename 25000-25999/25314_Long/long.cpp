#include    <iostream>

using namespace std;

#define SIZE_OF_LONG    4

int main(void)
{
    int N;

    cin>>N;

    for(int i=0;i<N;i+=SIZE_OF_LONG)
    {
        cout<<"long ";
    }

    cout<<"int\n";

    return  0;
}