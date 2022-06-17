#include    <iostream>
#include    <string>

using namespace std;

#define NONE    0
#define LEFT    1
#define RIGHT   2

const string    left_chrs = "qwertasdfgzxcvb";
const string    right_chrs = "yuiophjklnm";

int keyboard[0x100];

void    init(void)
{
    for(int i=0;i<left_chrs.length();i++)
    {
        keyboard[left_chrs[i]] = LEFT;
    }

    for(int i=0;i<right_chrs.length();i++)
    {
        keyboard[right_chrs[i]] = RIGHT;
    }
}

int     get_num_of_hand_changes(const string& str)
{
    int ret = -1;
    int current,prev;

    prev = NONE;

    for(int i=0;i<str.length();i++)
    {   
        current = keyboard[str[i]];

        if( prev != current )
        {
            ret++;
        }

        prev = current;
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    init();

    for(;;)
    {
        string  str;

        cin>>str;

        if( str == "#" )
        {
            break;
        }

        cout<<get_num_of_hand_changes(str)<<'\n';
    }

    return  0;
}