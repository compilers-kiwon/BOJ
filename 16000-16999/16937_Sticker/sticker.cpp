#include    <iostream>

using namespace std;

#define MAX_SIZE    (100+1)

typedef pair<int,int>   Sticker;

#define check_size(a,b,c,d,e,f) \
    (max((a),(b))<=(c)&&(d)+(e)<=(f))

#define get_area(s1,s2) \
    ((s1).first*(s1).second+(s2).first*(s2).second)

void    input(int& height,int& width,
                int& num_of_stickers,Sticker* s)
{
    cin>>height>>width>>num_of_stickers;

    for(int i=1;i<=num_of_stickers;i++)
    {
        cin>>s[i].first>>s[i].second;
    }
}

bool    is_fit(int height,int width,
                Sticker s1,Sticker s2)
{
    int h1 = s1.first;
    int w1 = s1.second;

    int h2 = s2.first;
    int w2 = s2.second;

    return  check_size(h1,h2,height,w1,w2,width)
                ||check_size(h1,w2,height,w1,h2,width)
                ||check_size(w1,h2,height,h1,w2,width)
                ||check_size(w1,w2,height,h1,h2,width)
                ||check_size(w1,w2,width,h1,h2,height)
                ||check_size(w1,h2,width,h1,w2,height)
                ||check_size(h1,w2,width,w1,h2,height)
                ||check_size(h1,h2,width,w1,w2,height);
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    
    int     H,W,N;
    Sticker s[MAX_SIZE];

    input(H,W,N,s);

    int max_area = 0;

    for(int i=1;i<N;i++)
    {
        for(int j=i+1;j<=N;j++)
        {
            if( is_fit(H,W,s[i],s[j]) == true )
            {
                max_area = max(max_area,get_area(s[i],s[j]));
            }
        }
    }

    cout<<max_area<<'\n';

    return  0;
}