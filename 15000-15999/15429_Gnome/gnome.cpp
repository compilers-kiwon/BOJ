#include    <iostream>

using namespace std;

#define MAX_SIZE    (1000+1)

int input(int gnome[])
{
    int g;

    cin>>g;

    for(int i=1;i<=g;i++)
    {
        cin>>gnome[i];
    }

    return  g;
}

int find_king(int size,int g[])
{
    int pos;

    for(pos=2;pos<size;pos++)
    {
        if( g[pos-1]+1 != g[pos] )
        {
            break;
        }
    }

    return  pos;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;

    cin>>n;

    for(int i=1;i<=n;i++)
    {
        int g,gnome[MAX_SIZE];

        g = input(gnome);
        cout<<find_king(g,gnome)<<'\n';
    }

    return  0;
}