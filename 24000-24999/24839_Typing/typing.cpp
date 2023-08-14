#include    <iostream>
#include    <string>

using namespace std;

#define IMPOSSIBLE  -1

int compare(const string& I,const string& P)
{
    int i_pos,p_pos,cnt;

    for (i_pos=p_pos=cnt=0;
            i_pos<I.length()&&p_pos<P.length();p_pos++) {
        cnt += (I[i_pos]!=P[p_pos])?1:0;
        i_pos += (I[i_pos]==P[p_pos])?1:0;
    }

    return  (i_pos!=I.length())?IMPOSSIBLE:P.length()-p_pos+cnt;
}

int print(int n,int result)
{
    cout<<"Case #"<<n<<": ";

    if (result == IMPOSSIBLE) cout<<"IMPOSSIBLE\n";
    else cout<<result<<'\n';

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin>>T;

    for (int i=1;i<=T;i++) {
        string  I,P;

        cin>>I>>P;
        print(i,compare(I,P));
    }

    return  0;
}