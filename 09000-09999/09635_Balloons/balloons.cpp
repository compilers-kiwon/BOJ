#include    <iostream>
#include    <string>

using namespace std;

#define MAX_SIZE    (100+1)
#define MAX_STATE   4

const static string s[MAX_STATE] = {
    "OKAY","EASY","HARD","BOTH"
};

int input(int& N,int& X,int& Y,int arr[])
{
    cin>>N>>X>>Y;

    for(int i=1;i<=N;i++)
    {
        cin>>arr[i];
    }

    return  0;
}

int check_assignment(int easiest,int hardest,
                        int num_of_problems,int arr[])
{
    int ret = 0;

    ret += (arr[1]==easiest)?1:0;
    ret += (arr[num_of_problems]==hardest)?2:0;

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin>>T;

    for(int t=1;t<=T;t++)
    {
        int N,X,Y,arr[MAX_SIZE];

        input(N,X,Y,arr);
        cout<<s[check_assignment(X,Y,N,arr)]<<'\n';
    }

    return  0;
}