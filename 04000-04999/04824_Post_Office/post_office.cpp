#include    <iostream>
#include    <vector>
#include    <algorithm>

using namespace std;

#define THICKNESS   0
#define HEIGHT      1
#define LENGTH      2

#define NUM_OF_SIZE_INFORMATION 3

bool    input(vector<float>& size)
{
    bool    ret = false;

    for(int i=0;i<NUM_OF_SIZE_INFORMATION;i++)
    {
        float   f;

        cin>>f;
        size.push_back(f);

        if( f != 0.0 )
        {
            ret = true;
        }
    }

    return  ret;
}

void    sort_information(vector<float>& size)
{
    sort(size.begin(),size.end());
}

void    classify_item(vector<float>& item)
{
    if( item[THICKNESS]<0.25 || item[HEIGHT]<90.0 || item[LENGTH]<125.0 )
    {
        cout<<"not mailable\n";
        return;
    }

    if( item[THICKNESS]<=7.0 && item[HEIGHT]<=155.0 && item[LENGTH]<=290.0 )
    {
        cout<<"letter\n";
        return;
    }

    if( item[THICKNESS]<=50.0 && item[HEIGHT]<=300.0 && item[LENGTH]<=380.0 )
    {
        cout<<"packet\n";
        return;
    }

    if( item[THICKNESS]*2+item[HEIGHT]*2+item[LENGTH] <= 2100.0 )
    {
        cout<<"parcel\n";
        return;
    }

    cout<<"not mailable\n";
    return;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for(;;)
    {
        vector<float>   item;

        if( input(item) == false )
        {
            break;
        }

        sort_information(item);
        classify_item(item);
    }

    return  0;
}