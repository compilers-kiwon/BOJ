#include    <iostream>

using namespace std;

int print_number(int num_of_holes)
{
    cout<<((num_of_holes%2==0)?"":"4");

    for(int i=0;i<(num_of_holes/2);i++)
    {
        cout<<8;
    }

    cout<<'\n';
    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int h;

    cin>>h;

    switch(h)
    {
        case 0:cout<<1<<'\n';break;
        case 1:cout<<0<<'\n';break;
        default:print_number(h);break;
    }

    return  0;
}