#include    <iostream>
#include    <vector>

using namespace std;

const static int FOR_SALE = 1;
const static int NOT_FOR_SALE = 0;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N,K,P,num_of_available;

    cin>>N>>K>>P;
    num_of_available = 0;

    for (int bundle=1;bundle<=N;bundle++) {
        int num_of_not_for_sale = 0;

        for (int bread=1;bread<=K;bread++) {
            int state;
            cin>>state;
            num_of_not_for_sale += (state==NOT_FOR_SALE?1:0);
        }

        num_of_available += (num_of_not_for_sale<P?1:0);
    }

    cout<<num_of_available<<'\n';
    return  0;
}