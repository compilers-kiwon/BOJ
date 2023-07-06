#include    <iostream>
#include    <queue>

using namespace std;

#define get_numbers(size,q) \
    for(int i=1;i<=(size);i++){int num;cin>>num;(q).push(num);}

#define print_numbers(q) \
    {for(;!(q).empty();(q).pop())cout<<(q).front()<<'\n';}

int input(queue<int>& A,queue<int>& B)
{
    int N,M;

    cin>>N>>M;

    get_numbers(N,A);
    get_numbers(M,B);

    return  0;
}

int merge(queue<int>& A,queue<int>& B)
{
    for(;!A.empty()&&!B.empty();)
    {
        int n;

        if( A.front() <= B.front() )
        {
            n = A.front();
            A.pop();    
        }
        else
        {
            n = B.front();
            B.pop();
        }

        cout<<n<<'\n';
    }

    print_numbers(A);print_numbers(B);
    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    queue<int>  A,B;

    input(A,B);
    merge(A,B);

    return  0;
}