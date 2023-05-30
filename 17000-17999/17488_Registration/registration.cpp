#include    <iostream>
#include    <vector>
#include    <algorithm>

using namespace std;

#define MAX_SIZE        (1000+1)
#define END_OF_INPUT    -1

static int  N,M,L[MAX_SIZE];
static vector<int> registered[MAX_SIZE];
static vector<int> my_courses[MAX_SIZE];

#define break_if_true(cond) {if((cond))break;}

int get_limits(void)
{
    for(int course=1;course<=M;course++)
    {
        cin>>L[course];
    }

    return  0;
}

int get_registration_info(void)
{
    for(int student=1;student<=N;student++)
    {
        for(;;)
        {
            int course;

            cin>>course;
            break_if_true(course==END_OF_INPUT);
            registered[course].push_back(student);
        }
    }

    return  0;
}

int finalize_registration(void)
{
    for(int course=1;course<=M;course++)
    {
        if( registered[course].size() <= L[course] )
        {
            for(int i=0;i<registered[course].size();i++)
            {
                int student = registered[course][i];
                my_courses[student].push_back(course);
            }

            L[course] -= registered[course].size();
            registered[course].clear();
        }
    }

    return  0;
}

int print_courses(void)
{
    for(int student=1;student<=N;student++)
    {
        if( my_courses[student].empty() )
        {
            cout<<"망했어요"<<'\n';
            continue;
        }

        sort(my_courses[student].begin(),my_courses[student].end());

        for(int i=0;i<my_courses[student].size();i++)
        {
            int course = my_courses[student][i];
            cout<<course<<(i==my_courses[student].size()-1?'\n':' ');
        }
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>N>>M;
    get_limits();

    // 1. First registration
    get_registration_info();
    finalize_registration();

    // 2. Second registration
    get_registration_info();
    finalize_registration();

    print_courses();
    return  0;
}