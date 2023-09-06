#include    <iostream>
#include    <string>

using namespace std;

#define END_OF_INPUT            "#"
#define is_tail_pos(idx,str)    ((idx)==(str).length()-1)

string  get_glued(const string& num)
{
    int     cnt[0x100] = {0,};
    string  ret;

    for (int i=1;i<num.length();i++) {
        if (num[i-1] == num[i]) cnt[num[i]]++;
    }

    for (char c='0';c<='9';c++) {
        if(cnt[c] != 0) ret.push_back(c);
    }

    return  ret; 
}

int print_glued(string g)
{
    for (int i=0;i<g.length();i++) {
        cout<<g[i]<<' '<<g[i]<<" glued"<<
                (is_tail_pos(i,g)?"\n":" and ");
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for (;;) {
        string  s1,s2,s3;

        cin>>s1;
        if(s1 == END_OF_INPUT) break;
        
        cin>>s2>>s3;
        print_glued(get_glued(s2));
    }

    return  0;
}