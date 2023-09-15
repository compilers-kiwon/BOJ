#include    <iostream>
#include    <string>

using namespace std;

typedef pair<string,int>    Round;  // first: name, second: num_of_persons

#define NUM_OF_ROUNDS   (4)
#define MAX_RANK        (30000)

const static Round  r[NUM_OF_ROUNDS] = {
    {"World Finals",25},{"Round 3",1000},
    {"Round 2",4500},{"Round 1",MAX_RANK}
};

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin>>T;

    for (int t=1;t<=T;t++) {
        int rank;

        cin>>rank;
        cout<<"Case #"<<t<<": ";
        
        for (int i=0;i<NUM_OF_ROUNDS;i++) {
            if (rank <= r[i].second) {
                cout<<r[i].first<<'\n';
                break;
            }
        }
    }

    return  0;
}