#include    <iostream>

using namespace std;

#define print_char_for_width(w,c) \
        {for(int i=1;i<=(w);i++)cout<<(c);cout<<'\n';}

int print_triangle(int n,char c)
{
    for(int h=1,w=1;h<=n;h++,w++)
    {
        print_char_for_width(w,c);
        c = (c+1>'Z')?'A':c+1;
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;

    cin>>N;

    for(int i=1;i<=N;i++)
    {
        int     h;
        char    c;

        cin>>h>>c;
        print_triangle(h,c);
        cout<<'\n';
    }

    return  0;
}