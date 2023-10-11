#include    <iostream>
#include    <vector>
#include    <deque>
#include    <algorithm>

using namespace std;

int input(deque<int>& file_size)
{
    int         N,X,S;
    vector<int> tmp;

    cin>>N>>X;

    for (int i=1;i<=N;i++) {
        cin>>S;
        tmp.push_back(S);
    }

    sort(tmp.begin(),tmp.end());

    for (int i=0;i<tmp.size();i++) {
        file_size.push_back(tmp[i]);
    }

    return  X;
}

int simulate(deque<int>& file_size,int disc_size)
{
    int ret = 0;

    for (;!file_size.empty();) {
        if ((file_size.size() != 1) &&
                (file_size.front()+file_size.back() <= disc_size)) {
            file_size.pop_front();
        }

        ret++;
        file_size.pop_back();
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin>>T;

    for (int t=1;t<=T;t++) {
        deque<int>  file_size;
        int disc_size = input(file_size);

        cout<<"Case #"<<t<<": "
            <<simulate(file_size,disc_size)<<'\n';
    }

    return  0;
}