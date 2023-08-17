#include    <iostream>
#include    <string>

using namespace std;

#define NEXT_EXPTECTED(e)   ((e)=='I'?'O':'I')

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int     N,cnt;
    char    expected;
    string  S;

    cin>>N>>S;
    expected = 'I';
    cnt = 0;

    for(int i=0;i<N;i++,expected=NEXT_EXPTECTED(expected))
    {
        cnt += (S[i]!=expected)?1:0;
    }

    cout<<cnt<<'\n';
    return  0;
}