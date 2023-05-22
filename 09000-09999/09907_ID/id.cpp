#include    <iostream>

using namespace std;

#define LENGTH_OF_DIGITS    7
#define MAX_REMAINDER       11

const static int weight[] = {2,7,6,5,4,3,2};
const static char* map = "JABCDEFGHIZ";

int get_sum_of_weights(int num)
{
    int ret = 0;

    for(int i=LENGTH_OF_DIGITS-1;i>=0;i--,num/=10)
    {
        ret += (num%10)*weight[i];
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;

    cin>>n;
    cout<<map[get_sum_of_weights(n)%MAX_REMAINDER]<<'\n';

    return  0;
}