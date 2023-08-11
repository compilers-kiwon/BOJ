#include    <iostream>
#include    <string>

using namespace std;

#define INF 0x7FFFFFFF

int get_num_of_difference(int current_difference,
                    const string& s1,const string& s2)
{
    int cnt = 0;

    for (int i=0;i<s1.length();i++) {
        if(s1[i]!=s2[i] &&
                ++cnt==current_difference) {
            break;
        }
    }

    return  cnt;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;

    cin>>n;

    for (int i=1;i<=n;i++) {
        int     w,min_diff;
        string  sascha,dic,most_likely;

        cin>>sascha>>w;
        min_diff = INF;

        for (int j=1;j<=w;j++) {
            int cur_diff;

            cin>>dic;
            cur_diff = get_num_of_difference(min_diff,sascha,dic);

            if (cur_diff < min_diff) {
                min_diff = cur_diff;
                most_likely = dic;
            }
        }

        cout<<most_likely<<'\n';
    }

    return  0;
}