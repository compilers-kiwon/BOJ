#include    <iostream>

using namespace std;

static int  N;

int get_lower_number(int& start_number,int& end_number,
                        int& current_digits,int& current_length)
{
    for(current_digits=1;;current_digits++)
    {
        int num_of_numbers = end_number-start_number;
        int next_length = current_length+(current_digits*num_of_numbers);

        if( next_length >= N )
        {
            break;
        }

        current_length = next_length;
        start_number *= 10;
        end_number *= 10;
    }

    return  0;
}

int get_digit(int& number,int& length_of_number,int& total_length)
{
    int ret;

    for(;;number++,total_length+=length_of_number)
    {
        if( total_length+length_of_number >= N )
        {
            int diff = total_length+length_of_number-N;

            for(int i=1;i<=diff;i++)
            {
                number /= 10;
            }

            ret = number%10;
            break;
        }
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int current_digits,current_length,start_number,end_number;

    cin>>N;
    current_length = 0;

    start_number = 1;
    end_number = 10;

    get_lower_number(start_number,end_number,current_digits,current_length);
    cout<<get_digit(start_number,current_digits,current_length)<<'\n';

    return  0;
}