#include    <iostream>
#include    <set>

using namespace std;

int     get_max_num(int a,int b,int c)
{
    return  max(a,max(b,c));
}

bool    is_right_triangle(int a,int b,int c)
{
    return  ((a*a)+(b*b)+(c*c)==get_max_num(a,b,c)*get_max_num(a,b,c)*2);
}

bool    is_same_set(int a,int b,int c,int d,int e,int f)
{
    set<int>    s1,s2;

    s1.insert(a);s1.insert(b);s1.insert(c);
    s2.insert(d);s2.insert(e);s2.insert(f);

    return  (s1==s2);
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int a,b,c,d,e,f;

    cin>>a>>b>>c>>d>>e>>f;

    if( is_right_triangle(a,b,c) && is_same_set(a,b,c,d,e,f) )
    {
        cout<<"YES\n";
    }
    else
    {
        cout<<"NO\n";
    }

    return  0;
}