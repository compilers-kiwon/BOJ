#include    <iostream>
#include    <string>

using namespace std;

#define EXPECTED_DURATION 64

int duration_table[0x100];

void    init(void)
{
    duration_table['W'] = 64;
    duration_table['H'] = 32;
    duration_table['Q'] = 16;
    duration_table['E'] = 8;
    duration_table['S'] = 4;
    duration_table['T'] = 2;
    duration_table['X'] = 1;
}

int     get_sum_of_duration(const string& measure)
{
    int ret = 0;

    for(int i=0;i<measure.length();i++)
    {
        ret += duration_table[measure[i]];
    }

    return  ret;
}

int     find_right_duration(const string& str)
{
    int     ret = 0;
    string  measure;

    for(int i=0;i<str.length();i++)
    {
        if( str[i] == '/' )
        {
            if( get_sum_of_duration(measure) == EXPECTED_DURATION )
            {
                ret++;
            }

            measure.clear();
        }
        else
        {
            measure.push_back(str[i]);
        }
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

        if( str == "*" )
        {
            break;
        }

        cout<<find_right_duration(str)<<'\n';
    }

    return  0;
}