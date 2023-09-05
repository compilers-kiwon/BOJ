#include    <iostream>
#include    <vector>
#include    <algorithm>

using namespace std;

typedef vector<vector<int>> Triangle;

#define INF             0x7FFFFFFF
#define ROTATE_ANGLE    120
#define MAX_ANGLE       360

Triangle rotate(const Triangle& t)
{
    Triangle ret;
    int h,len; 
    
    h = 1;
    len = t.size(); 

    for (int i=len-1;i>=0;i--,h++) {
        vector<int> n;

        for (int j=0;j<h;j++) {
            n.insert(n.begin(),t[len-1-j][i]);
        }

        ret.push_back(n);
    }

    return  ret;
}

int read_triangle(Triangle& t,int len)
{
    for (int i=1;i<=len;i++) {
        vector<int> n;

        for (int j=1;j<=i;j++) {
            int num;

            cin>>num;
            n.push_back(num);
        }

        t.push_back(n);
    }

    return  0;
}

int compare(const Triangle& t1,const Triangle& t2)
{
    int ret = 0;
    int len = t1.size();

    for (int i=0;i<len;i++) {
        for (int j=0;j<=i;j++) {
            ret += (t1[i][j]!=t2[i][j])?1:0;
        }
    }
    
    return  ret;
}

Triangle get_symmetry(const Triangle& t)
{
    Triangle    ret;

    for (int i=0;i<t.size();i++) {
        ret.push_back(t[i]);
        reverse(ret.back().begin(),ret.back().end());
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N,min_diff;
    Triangle A,B,cur;

    cin>>N;
    min_diff = INF;

    read_triangle(A,N);
    read_triangle(B,N);

    cur = A;
    min_diff = min(min(min_diff,compare(cur,B)),
                    compare(get_symmetry(cur),B));

    for (int i=ROTATE_ANGLE;i<MAX_ANGLE;i+=ROTATE_ANGLE) {
        cur = rotate(cur);
        min_diff = min(min(min_diff,compare(cur,B)),
                        compare(get_symmetry(cur),B));
    }
    
    cout<<min_diff<<'\n';
    return  0;
}