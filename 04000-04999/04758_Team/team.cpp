#include    <iostream>
#include    <string>
#include    <vector>

using namespace std;

#define MAX_POSITIONS   3

const struct{
    string  p;
    double  speed,weight,strength;
} requirement[MAX_POSITIONS] = {{"Wide Receiver",4.5,150.0,200.0},
                                {"Lineman",6.0,300.0,500.0},
                                {"Quarterback",5.0,200.0,300.0}};

int get_position(vector<string>& result,
                    double s,double w,double st)
{
    for(int i=0;i<MAX_POSITIONS;i++)
    {
        if( s<=requirement[i].speed 
            && w>=requirement[i].weight
            && st>=requirement[i].strength )
        {
            result.push_back(requirement[i].p);
        }
    }
    
    return  result.size();
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for(;;)
    {
        double  s,w,st;

        cin>>s>>w>>st;

        if( s==0.0 && w==0.0 && st==0.0 )
        {
            break;
        }

        vector<string>  position;

        if( get_position(position,s,w,st) == 0 )
        {
            cout<<"No positions\n";
        }
        else
        {
            for(int i=0;i<position.size();i++)
            {
                cout<<position[i]<<' ';
            }
            cout<<'\n';
        }
    }
}