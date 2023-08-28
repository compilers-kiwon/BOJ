#include    <iostream>
#include    <string>
#include    <cmath>

using namespace std;

const string color = "RGBY";

#define get_colors(s,cnt) \
    {for(int i=0;i<(s).length();i++)(cnt)[(s)[i]]++;}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string  src,dst;
    int     src_color[0x100] = {0,};
    int     dst_color[0x100] = {0,};

    cin>>src>>dst;
    
    get_colors(src,src_color);
    get_colors(dst,dst_color);

    int diff = 0;

    for (int i=0;i<color.length();i++) {
        char    c = color[i];
        diff += abs(src_color[c]-dst_color[c]);
    }

    cout<<diff/2<<'\n';
    return  0;
}