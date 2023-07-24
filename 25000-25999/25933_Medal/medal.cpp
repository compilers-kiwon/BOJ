#include    <iostream>
#include    <string>
#include    <map>

using namespace std;

#define TRUE    1
#define FALSE   0

enum {
    NONE = 0,
    COUNT = 1,
    COLOR = 2,
    BOTH = 3
};

static map<int,string>  how_to_win = {
    {NONE,"none"},{COUNT,"count"},
    {COLOR,"color"},{BOTH,"both"}
};

typedef struct{int g,s,b;}   Medal;

#define input(n)    (cin>>(n).g>>(n).s>>(n).b)
#define print(n)    (cout<<(n).g<<' '<<(n).s<<' '<<(n).b<<' ')

#define get_sum_of_medals(n)    ((n).g+(n).s+(n).b)
#define win_by_color(a,b)       {if((a)!=(b))return((a)>(b)?TRUE:FALSE);}

int compare_color(const Medal& u,const Medal& r)
{
    win_by_color(u.g,r.g);
    win_by_color(u.s,r.s);
    win_by_color(u.b,r.b);

    return  FALSE;
}

int simulate(const Medal& u,const Medal& r)
{
    int ret = NONE;

    if( get_sum_of_medals(u) > get_sum_of_medals(r) )
    {
        ret += COUNT;
    }

    if( compare_color(u,r) )
    {
        ret += COLOR;
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;

    cin>>n;

    for(int i=1;i<=n;i++)
    {
        Medal   USA,Russia;

        input(USA);
        input(Russia);

        print(USA);
        print(Russia);
        
        cout<<'\n'<<how_to_win[simulate(USA,Russia)]<<"\n\n";
    }

    return  0;
}