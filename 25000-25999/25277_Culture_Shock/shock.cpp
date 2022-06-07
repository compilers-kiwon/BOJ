#include    <iostream>
#include    <string>

using namespace std;

#define NUM_OF_FORBIDDEN_WORDS  4

const string    forbiddien[NUM_OF_FORBIDDEN_WORDS] = {"he","him","she","her"};

bool    is_forbidden(const string& str)
{
    bool    ret = false;

    for(int i=0;i<NUM_OF_FORBIDDEN_WORDS;i++)
    {
        if( str == forbiddien[i] )
        {
            ret = true;
            break;
        }
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N,cnt;

    cin>>N;
    cnt = 0;

    for(int i=1;i<=N;i++)
    {
        string  w;

        cin>>w;
        cnt += (is_forbidden(w)?1:0);
    }

    cout<<cnt<<'\n';

    return  0;
}