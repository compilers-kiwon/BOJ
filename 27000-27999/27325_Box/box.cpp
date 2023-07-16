#include    <iostream>
#include    <string>

using namespace std;

#define MOVE_LEFT(pos)  (max((pos)-1,1))
#define MOVE_RIGHT(pos) (min((pos)+1,3))

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int     N,pos,cnt;
    string  str;

    cin>>N>>str;

    pos = 1;
    cnt = 0;
    
    for(int i=0;i<str.length();i++)
    {
        pos = (str[i]=='L')?
            MOVE_LEFT(pos):MOVE_RIGHT(pos);
        cnt += (pos==3)?1:0;    
    }

    cout<<cnt<<'\n';
    return  0;
}