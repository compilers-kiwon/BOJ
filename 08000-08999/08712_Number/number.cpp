#include    <iostream>
#include    <vector>
#include    <deque>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n,num;
    vector<deque<int>>  grid;

    cin>>n;
    num = 1;

    for (int row=1;row<=n;row++) {
        deque<int>  dq;

        for (int col=1;col<=n;col++) {
            if (row%2 == 1) {
                dq.push_back(num++);
            } else {
                dq.push_front(num++);
            }
        }

        grid.push_back(dq);
    }

    for (int row=0;row<grid.size();row++) {
        for (;!grid[row].empty();grid[row].pop_front()) {
            cout<<grid[row].front()<<
                    (grid[row].size()==1?'\n':' ');
        }
    }

    return  0;
}