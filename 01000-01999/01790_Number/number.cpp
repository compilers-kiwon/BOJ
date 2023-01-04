#include    <iostream>
#include    <cmath>

using namespace std;

typedef long long int   int64;

#define shift_digit(l,s)    (pow(10,(l)-((s)==0?(l):(s))))

bool    input(int64& num,int64& digit)
{
    bool    ret = true;

    cin>>num>>digit;

    if( num <= 9 )
    {
        cout<<((digit>num)?-1:digit)<<'\n';
        ret = false;
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int64   N,k,current_length,total_length;
    int64   start_num,end_num,answer;

    if( input(N,k) == false )
    {
        return  0;
    }

    total_length = 0;
    current_length = 1;

    for(start_num=1,end_num=9,answer=-1;;
            current_length++,start_num*=10,end_num=end_num*10+9)
    {
        int64   tmp;

        end_num = min(end_num,N);
        tmp = total_length+(end_num-start_num+1)*current_length;

        if( tmp >= k )
        {
            int64   num_of_required,rest,last_number;

            rest = (k-total_length)%current_length;
            num_of_required = (k-total_length)/current_length+(rest==0?0:1);
            
            last_number = start_num+num_of_required-1;
            answer = (last_number/(int64)shift_digit(current_length,rest))%10;

            break;
        }

        if( end_num == N )
        {
            break;
        }

        total_length = tmp;
    }

    cout<<answer<<'\n';

    return  0;
}