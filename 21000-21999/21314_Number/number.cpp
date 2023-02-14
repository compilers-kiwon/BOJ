#include    <iostream>
#include    <string>

using namespace std;

#define TRUE    1
#define FALSE   0

#define determine_head_number(f)    ((f)?'5':'1')

#define fill_number_with_digit(num,len,digit) \
    {for(int i=0;i<(len);i++)(num).push_back((digit));}

int build_number(string& number,int digits,int five_flag)
{
    number.push_back(determine_head_number(five_flag));
    fill_number_with_digit(number,digits-(five_flag?0:1),'0');
    
    return  0;
}

int get_max_num(const string& str,string& max_num)
{
    int digits = 0;

    for(int i=0;i<str.length();i++)
    {
        if( str[i] == 'M' )
        {
            digits++;
        }
        else
        {
            build_number(max_num,digits,TRUE);
            digits = 0;
        }
    }

    if( digits != 0 )
    {
        fill_number_with_digit(max_num,digits,'1');
    }

    return  0;
}

int get_min_num(const string& str,string& min_num)
{
    int digits = 0;

    for(int i=0;i<str.length();i++)
    {
        if( str[i] == 'M' )
        {
            digits++;
        }
        else
        {
            if( digits != 0 )
            {
                build_number(min_num,digits,FALSE);
            }
            
            build_number(min_num,0,TRUE);
            digits = 0;
        }
    }

    if( digits != 0 )
    {
        build_number(min_num,digits,FALSE);
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string  num,max_num,min_num;

    cin>>num;

    get_max_num(num,max_num);
    get_min_num(num,min_num);

    cout<<max_num<<'\n'<<min_num<<'\n';

    return  0;
}