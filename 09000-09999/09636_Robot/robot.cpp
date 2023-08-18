#include    <iostream>
#include    <string>

using namespace std;

#define get_min_pos(upper,lower,unknown)    ((upper)-(lower)-(unknown))
#define get_max_pos(upper,lower,unknown)    ((upper)-(lower)+(unknown))

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin>>T;

    for (int t=1;t<=T;t++) {
        string  str;
        int     u,r,d,l,q;

        cin>>str;
        u = r = d = l = q = 0;

        for (int i=0;i<str.length();i++) {
            switch (str[i]) {
                case 'U':u++;break;
                case 'R':r++;break;
                case 'D':d++;break;
                case 'L':l++;break;
                case '?':q++;break;
                default:/*do nothing*/;break;
            }
        }

        cout<<get_min_pos(r,l,q)<<' '<<get_min_pos(u,d,q)<<' '
                <<get_max_pos(r,l,q)<<' '<<get_max_pos(u,d,q)<<'\n';
    }

    return  0;
}