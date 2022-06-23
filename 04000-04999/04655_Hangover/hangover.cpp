#include    <iostream>

using namespace std;

#define MAX_NUM_OF_CARDS    300

float   card_len[MAX_NUM_OF_CARDS+1];

void    init(void)
{
    for(int i=1;i<=MAX_NUM_OF_CARDS;i++)
    {
        float   prev_len = card_len[i-1];

        card_len[i] = prev_len+(1.0/(float)(i+1));
    }
}

int     get_num_of_required_cards(float target_len)
{
    int ret;

    for(ret=1;;ret++)
    {
        if( card_len[ret] >= target_len )
        {
            break;
        }
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    init();

    for(float n;;)
    {
        cin>>n;

        if( n == 0.0 )
        {
            break;
        }

        cout<<get_num_of_required_cards(n)<<" card(s)\n";
    }

    return  0;
}