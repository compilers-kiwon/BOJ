#include    <iostream>
#include    <string>

using namespace std;

#define MAX_HOUR    12

const int hour_table[MAX_HOUR] =
        {12,1,2,3,4,5,6,7,8,9,10,11};

#define FORWARD     0
#define BACKWARD    1
#define MAX_DIR     2

const int offset_table[MAX_DIR] = {1,11};

#define pass_hour(h,d)  (((h)+offset_table[(d)])%MAX_HOUR)

#define TRUE    1
#define FALSE   0

int simulate(int expected_hour,int& dir,
                string card_type,int card_hour)
{
    int     ret = FALSE;
    bool    reverse_event,sync_event;
        
    reverse_event = ((card_type=="HOURGLASS")?true:false);
    sync_event = (expected_hour==card_hour?true:false);
    
    if( reverse_event != sync_event )
    {
        if( reverse_event )
        {
            dir = (dir+1)%MAX_DIR;
        }
        else
        {
            ret = TRUE;
        }
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N,dir;

    cin>>N;
    dir = FORWARD;

    for(int i=1,h=1;i<=N;i++,h=pass_hour(h,dir))
    {
        int     X;
        string  S;

        cin>>S>>X;
        cout<<hour_table[h]<<' '<<
            (simulate(hour_table[h],dir,S,X)?"YES":"NO")<<'\n';
    }

    return  0;
}