#include    <iostream>
#include    <string>

using namespace std;

#define read_and_write(n)   {cin>>(n);cout<<(n)<<'\n';}

int get_and_print_set_menu(void)
{
    int d;

    read_and_write(d);

    for(int i=1;i<=d;i++)
    {
        string  dish;
        read_and_write(dish);
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;

    cin>>n;
    get_and_print_set_menu();

    return  0;
}