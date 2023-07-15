#include    <iostream>
#include    <string>

using namespace std;

#define MAX_SIZE        0x100
#define init_arr(arr)   {for(int i=0;i<sizeof((arr));i++)(arr)[i]=i;}

static char conversion[MAX_SIZE];

int build_conversion_table(void)
{
    int n;

    cin>>n;
    init_arr(conversion);

    for(int i=1;i<=n;i++)
    {
        char    src,dst;

        cin>>src>>dst;
        conversion[src] = dst;
    }

    return  0;
}

int do_conversion(void)
{
    int     m;
    string  s;

    cin>>m;

    for(int i=1;i<=m;i++)
    {
        char    c;

        cin>>c;
        s.push_back(conversion[c]);
    }

    cout<<s<<'\n';
    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    build_conversion_table();
    do_conversion();

    return  0;
}