#include    <iostream>
#include    <string>

using namespace std;

#define OMIT_SYMBOL "..."
#define OMIT_LENGTH 25

#define get_mid_str(str,sub_len,total_len) \
    ((str).substr((sub_len),(total_len)-(2*(sub_len))))

#define get_head_str(str,sub_len,total_len) ((str).substr(0,(sub_len)))

#define get_tail_str(str,sub_len,total_len) \
    ((str).substr((total_len)-(sub_len),(sub_len)))

#define HEAD_STR_LEN    9
#define MID_STR_LEN     11
#define TAIL_STR_LEN    10

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int     N;
    string  str;

    cin>>N>>str;

    if( N <= OMIT_LENGTH )
    {
        cout<<str<<'\n';
    }
    else
    {
        string  mid = get_mid_str(str,MID_STR_LEN,N);
        
        if( mid.find('.')==string::npos ||
                mid.find('.')==mid.length()-1 )
        {
            cout<<get_head_str(str,MID_STR_LEN,N)
                <<OMIT_SYMBOL
                <<get_tail_str(str,MID_STR_LEN,N)<<'\n';
        }
        else
        {
            cout<<get_head_str(str,HEAD_STR_LEN,N)
                <<OMIT_SYMBOL<<OMIT_SYMBOL
                <<get_tail_str(str,TAIL_STR_LEN,N)<<'\n';
        }
    }

    return  0;
}