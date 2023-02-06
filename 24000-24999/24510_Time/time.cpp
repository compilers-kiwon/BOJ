#include    <iostream>
#include    <string>

using namespace std;

int get_num_of_keyword(const string& str,
                        const string& keyword)
{
    int     ret;
    size_t  pos;

    for(pos=ret=0;
        pos<str.length()&&(pos=str.find(keyword,pos))!=string::npos;
        ret++,pos+=keyword.length());

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N,max_cnt;

    cin>>N;
    max_cnt = 0;

    for(int i=1;i<=N;i++)
    {
        string  str;

        cin>>str;
        max_cnt = max(max_cnt,
            get_num_of_keyword(str,"for")+get_num_of_keyword(str,"while"));
    }

    cout<<max_cnt<<'\n';

    return  0;
}