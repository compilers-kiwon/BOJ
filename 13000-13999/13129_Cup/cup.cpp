#include    <iostream>

using namespace std;

#define get_init_height(A,B,N)  ((A)*(N)+(B))
#define stack_cup(height,cup)   ((height)+=(cup))

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int A,B,N,h;

    cin>>A>>B>>N;
    h = get_init_height(A,B,N);

    for(int i=1;i<=N;i++)
    {
        cout<<h<<' ';
        stack_cup(h,B);
    }

    return  0;
}