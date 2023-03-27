#include    <iostream>
#include    <string>

using namespace std;

#define MAX_SIZE  28

const int number[MAX_SIZE] = 
    {2,3,4,5,6,7,8,9,10,11,12,13,14,15,
     14,13,12,11,10,9,8,7,6,5,4,3,2,1};

#define get_num(n)  (((n)==1)?1:number[((n)-2)%MAX_SIZE])

int print(int num)
{
    for(int i=8;i>=1;i/=2)
    {
        cout<<(((num&i)==0)?"V":"딸기");
    }

    cout<<'\n';
    return  0;
}

int simulate(void)
{
    int N;

    cin>>N;
    print(get_num(N));

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin>>T;

    for(int i=1;i<=T;i++)
    {
        simulate();
    }

    return  0;
}