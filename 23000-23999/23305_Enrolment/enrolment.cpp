#include    <iostream>

using namespace std;

#define MAX_SIZE    (1000000+1)

static int  N,A[MAX_SIZE],B[MAX_SIZE];

#define read_and_count_numbers(table,size) \
    {for(int i=1;i<=(size);i++){int n;cin>>n;table[(n)]++;}}

#define get_num_of_insufficient_seats(expected,actual)  (max((expected)-(actual),0))

int input(void)
{
    cin>>N;

    read_and_count_numbers(A,N);
    read_and_count_numbers(B,N);

    return  0;
}

int get_cnt_of_unsatiated_students(void)
{
    int ret = 0;

    for(int i=1;i<=MAX_SIZE;i++)
    {
        ret += get_num_of_insufficient_seats(B[i],A[i]);
    }
    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<get_cnt_of_unsatiated_students()<<'\n';

    return  0;
}