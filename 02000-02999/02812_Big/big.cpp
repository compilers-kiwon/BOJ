#include    <iostream>
#include    <vector>
#include    <string>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int             N,K;
    string          num;
    vector<char>    st;

    cin>>N>>K>>num;

    for(int i=0;i<N;i++)
    {
        if( K==0 || st.empty() )
        {
            st.push_back(num[i]);
            continue;
        }

        for(;!st.empty()&&K>0&&st.back()<num[i];K--,st.pop_back());
        st.push_back(num[i]);
    }

    for(;K>0;K--) st.pop_back();
    for(int i=0;i<st.size();i++) cout<<st[i];

    cout<<'\n';
    return  0;
}