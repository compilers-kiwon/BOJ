#include    <iostream>
#include    <string>

using namespace std;

#define LEFT        0
#define FACE        1
#define RIGHT       2
#define MAX_SIZE    3

#define PUNCH       '@'
#define LEFT_FACE   '('
#define RIGHT_FACE  ')'

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    
    string  str;
    int     cnt[MAX_SIZE];

    cin>>str;
    fill(cnt,cnt+MAX_SIZE,0);

    for(int i=0,p=LEFT;i<str.length();i++)
    {
        switch(str[i])
        {
            case PUNCH:cnt[p]++;break;
            case LEFT_FACE:case RIGHT_FACE:p++;break;
            default:/*do nothing*/;break;   
        }
    }

    cout<<cnt[LEFT]<<' '<<cnt[RIGHT]<<'\n';

    return  0;
}