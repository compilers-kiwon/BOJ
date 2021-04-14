#include    <iostream>
#include    <vector>
#include    <string>
#include    <algorithm>

using namespace std;

#define MAX_SIZE    0x100

typedef struct _WORD_INFO   Word;
struct _WORD_INFO
{
    int             ptr;
    vector<string>  w;
};

int     K,N;
string  z;
Word    word[MAX_SIZE];

#define inc_ptr(p,size) (((p)+1)%(size))

void    input(void)
{
    cin>>K>>N;

    for(int i=1;i<=K;i++)
    {
        string  s;

        cin>>s;
        word[s[0]].w.push_back(s);
    }

    for(int i=1;i<=N;i++)
    {
        char    c;

        cin>>c;
        z.push_back(c);
    }
}

void    init(void)
{
    for(char c='a';c<='z';c++)
    {
        if( word[c].w.empty() )
        {
            continue;
        }

        word[c].ptr = 0;
        sort(word[c].w.begin(),word[c].w.end());
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    init();

    for(int i=0;i<N;i++)
    {
        char&   c = z[i];
        Word&   zag = word[c];

        cout<<zag.w[zag.ptr]<<'\n';
        zag.ptr = inc_ptr(zag.ptr,zag.w.size());
    }

    return  0;
}