#include    <iostream>
#include    <string>

using namespace std;

#define IMPOSSIBLE  (-1)

int get_num_of_chrs(const string& str,int cnt[])
{
    for (int i=0;i<str.length();i++) {
        cnt[str[i]]++;
    }

    return  0;
}

int get_num_of_required_wildcards(int src_cnt[],int dst_cnt[])
{
    int ret = 0;

    for (char c='a';c<='z';c++) {
        if (dst_cnt[c] > src_cnt[c]) return IMPOSSIBLE;
        ret += src_cnt[c]-dst_cnt[c];
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int cnt[2][0x100] = {{0,},{0,}};
    string  src,dst;

    cin>>src>>dst;
    
    get_num_of_chrs(src,cnt[0]);
    get_num_of_chrs(dst,cnt[1]);

    int r = get_num_of_required_wildcards(cnt[0],cnt[1]);

    cout<<(r!=IMPOSSIBLE&&
            r==cnt[1]['*']?'A':'N')<<'\n';
    return  0;
}