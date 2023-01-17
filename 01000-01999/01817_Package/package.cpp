#include    <iostream>
#include    <vector>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int         N,M;
    vector<int> boxes;

    cin>>N>>M;
    boxes.push_back(M);

    for(int i=1;i<=N;i++)
    {
        int book;

        cin>>book;

        if( boxes.back()+book > M )
        {
            boxes.push_back(book);
        }
        else
        {
            boxes.back() += book;
        }
    }

    boxes.erase(boxes.begin());
    cout<<boxes.size()<<'\n';

    return  0;
}