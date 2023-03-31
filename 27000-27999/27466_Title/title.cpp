#include    <iostream>
#include    <string>
#include    <queue>

using namespace std;

#define MAX_SIZE    300000
#define TAIL_SIZE   3

const static string vowel = "AEIOU";

typedef struct{int num,p[2];} State;

static int      N,M;
static string   S,T;
static State    pos[MAX_SIZE];

#define is_vowel(c) (vowel.find((c))!=string::npos)

#define TRUE    1
#define FALSE   0

#define FOUND_AA    2

int init(void)
{
    for(int i=0;i<N;i++)
    {
        if( i != 0 )
        {
            pos[i] = pos[i-1];
        }

        if( S[i] != 'A' )
        {
            continue;
        }

        switch(pos[i].num)
        {
            case    0:
            case    1:
                pos[i].p[pos[i].num] = i;
                pos[i].num++;
                break;
            case    2:
                swap(pos[i].p[0],pos[i].p[1]);
                pos[i].p[1] = i;
                break;
            default:
                // do nothing
                break;
        }
    }

    return  0;
}

int get_title(void)
{
    for(int i=M-1;i<N;i++)
    {
        if( is_vowel(S[i]) || pos[i].num!=FOUND_AA )
        {
            continue;
        }

        int head = pos[i].p[0];

        if( head+TAIL_SIZE >= M )
        {
            T = S.substr(0,M-TAIL_SIZE)+"AA"+S[i];
            return  TRUE;
        }
    }

    return  FALSE;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>N>>M>>S;
    init();

    cout<<(get_title()==TRUE?"YES\n"+T:"NO")<<'\n';

    return  0;
}