#include    <iostream>

using namespace std;

#define    NUM_OF_STUDENTS            30
#define    NUM_OF_WORK_DONE_STUDENTS  28

int    main(void)
{
    bool    students[NUM_OF_STUDENTS+1];
    
    for(int i=1;i<=NUM_OF_STUDENTS;i++)
    {
        students[i] = false;
    }
    
    for(int i=1;i<=NUM_OF_WORK_DONE_STUDENTS;i++)
    {
        int    n;
        
        cin>>n;
        students[n] = true;
    }
    
    for(int i=1;i<=NUM_OF_STUDENTS;i++)
    {
        if( students[i] == false )
        {
            cout<<i<<endl;
        }
    }
    
    return    0;
}
