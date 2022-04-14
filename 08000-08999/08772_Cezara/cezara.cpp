#include    <iostream>
#include    <string>

using namespace std;

const string    table = "abcdefghijklmnopqrstuvwxyz";

#define get_index(c)    ((int)((c)-'a'))

int get_offset(char src,char dst)
{
    int src_pos,dst_pos,ret;

    for(src_pos=0;src!=table[src_pos];src_pos++);
    for(dst_pos=0;dst!=table[dst_pos];dst_pos++);

    for(int offset=0;offset<table.size();offset++)
    {
        if( (src_pos+offset)%table.size() == dst_pos )
        {
            ret = offset;
            break;
        }
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int Z;

    cin>>Z;

    for(int z=1;z<=Z;z++)
    {
        int     N,reverse_offset;
        string  str,result;
        char    head;

        cin>>N>>str>>head;
        reverse_offset = table.size()-get_offset(head,str[0]);

        for(int i=0;i<str.length();i++)
        {
            int idx;

            idx = (get_index(str[i])+reverse_offset)%table.size();
            result.push_back(table[idx]);
        }

        cout<<result<<'\n';
    }

    return  0;
}