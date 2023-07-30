#include    <iostream>
#include    <string>
#include    <map>
#include    <cmath>

using namespace std;

#define CYCLE_LENGHT    12
#define MAX_NUM_OF_COWS 100

#define get_zodiac_idx(y)   ((y)%CYCLE_LENGHT)

static string  animal_table[CYCLE_LENGHT] = {
    "Ox","Tiger","Rabbit","Dragon","Snake","Horse",
    "Goat","Monkey","Rooster","Dog","Pig","Rat"
};

static map<string,int>  birth_year;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;

    cin>>N;
    birth_year["Bessie"] = 
        CYCLE_LENGHT*(MAX_NUM_OF_COWS+1);

    for(int i=1;i<=N;i++)
    {
        string  cow1,born,in,prev_next,
                animal,year,from,cow2;

        cin>>cow1>>born>>in>>
            prev_next>>animal>>year>>from>>cow2;

        int cur_year = birth_year[cow2];
        int offset = (prev_next=="next")?1:-1;

        for(birth_year[cow1]=cur_year+offset;
            animal!=animal_table[get_zodiac_idx(birth_year[cow1])];
            birth_year[cow1]+=offset);

        if( cow1 == "Elsie" )
        {
            break;
        } 
    }

    cout<<abs(birth_year["Bessie"]-birth_year["Elsie"])<<'\n';
    return  0;
}