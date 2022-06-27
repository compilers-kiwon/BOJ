#include    <iostream>
#include    <string>

using namespace std;

const string    letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

#define get_index(c)            (int)((c)-'A')
#define shift_letter(c,offset)  (letters[(get_index((c))+(offset))%letters.length()])

char    find_most_used_letter(const string& str)
{
    int     cnt[0x100],max_num;
    char    ret;

    fill(&cnt['A'],&cnt['Z'+1],0);

    for(int i=0;i<str.length();i++)
    {
        cnt[str[i]]++;
    }

    max_num = 0;

    for(char c='A';c<='Z';c++)
    {
        if( cnt[c] > max_num )
        {
            ret = c;
            max_num = cnt[c];
        }
    }

    return  ret;
}

int     get_offset_for_encoding(char src,char dst)
{
    int offset;

    for(offset=0;;offset++)
    {
        char    shifted = shift_letter(src,offset);

        if( shifted == dst )
        {
            break;
        }
    }

    return  offset;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int     n,offset;
    char    c;
    string  str,decoded;

    cin>>n>>c>>str;
    offset = get_offset_for_encoding(find_most_used_letter(str),c);

    for(int i=0;i<str.length();i++)
    {
        decoded.push_back(shift_letter(str[i],offset));
    }

    cout<<decoded<<'\n';

    return  0;
}