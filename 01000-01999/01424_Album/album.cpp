#include    <iostream>

using namespace std;

int main(void)
{
    int N,L,C,min_num_of_required;

    cin>>N>>L>>C;
    min_num_of_required = N;

    int max_num_of_songs_per_one = min(N,(C+1)/(L+1));

    for(int i=1;i<=max_num_of_songs_per_one;i++)
    {
        if( i%13 == 0 )
        {
            continue;
        }

        int additional = 0;
        int num_of_remaining_songs = N%i;

        if( num_of_remaining_songs != 0 )
        {
            additional++;

            if( num_of_remaining_songs%13==0 && (i-1)%13==0 )
            {
                additional++;
            }
        }
        
        min_num_of_required = min(min_num_of_required,N/i+additional);
    }

    cout<<min_num_of_required<<'\n';
    return  0;
}