#include    <iostream>
#include    <vector>
#include    <map>
#include    <algorithm>
#include    <cmath>

using namespace std;

typedef long long int   int64;

typedef struct{
    int64 d;vector<int64> hp;
    vector<int64>::iterator available;
} State;

typedef pair<int,int>   Gradient;   //first: dx, second: dy

static int  N,M;
static map<Gradient,State>  quadrant;

#define get_sign(n) ((n)>0?1:-1)

int get_gcd(int dx,int dy)
{
    int big = max(dx,dy);
    int small = min(dx,dy);

    for (int mod=big%small;mod!=0;mod=big%small) {
        big = small;
        small = mod;
    }

    return  small;
}

int input(void)
{
    vector<pair<int64,Gradient>>    balloon;

    cin>>N>>M;

    for (int i=1;i<=N;i++)
    {
        int     dx,dy,gcd;
        int64   hp;

        cin>>dx>>dy>>hp;

        if (dx == 0) {
            balloon.push_back({hp,{0,get_sign(dy)}});
            continue;
        }

        if (dy == 0) {
            balloon.push_back({hp,{get_sign(dx),0}});
            continue;
        }

        gcd = get_gcd(abs(dx),abs(dy));
        balloon.push_back({hp,{dx/gcd,dy/gcd}});
    }

    sort(balloon.begin(),balloon.end());

    for (int i=0;i<N;i++) {
        quadrant[balloon[i].second].hp.push_back(balloon[i].first);
        quadrant[balloon[i].second].d = 0;
        quadrant[balloon[i].second].available = 
                quadrant[balloon[i].second].hp.begin();
    }

    return  0;
}

int simulate(void)
{
    for (int i=1;i<=M;i++) {
        int     dx,dy,gcd;
        int64   damage;

        cin>>dx>>dy>>damage;

        if (dx == 0) dy=get_sign(dy);
        else if (dy == 0) dx=get_sign(dx);
        else {
            gcd = get_gcd(abs(dx),abs(dy));
            dx /= gcd;
            dy /= gcd;
        }

        map<Gradient,State>::iterator   it;
        if ((it=quadrant.find({dx,dy})) == quadrant.end()) {
            cout<<N<<'\n';
            continue;
        }

        State&  t = it->second;
        vector<int64>::iterator updated =
            upper_bound(t.available,t.hp.end(),(t.d+=damage));

        N -= updated-t.available;
        cout<<N<<'\n';

        if (updated == t.hp.end()) {
            quadrant.erase(it);
        } else {
            t.available = updated;
        }       
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    simulate();

    return  0;
}