#include    <iostream>
#include    <vector>

using namespace std;

#define MAX_SIZE    (2000+1)

typedef long long int   int64;

static int  N,M,Q;
static int64 A[MAX_SIZE],W[MAX_SIZE],B_out;

typedef struct{
    vector<int> input;
    vector<int64> W;
    int64 B;
} Node;

int get_node(Node& n)
{
    int C;

    cin>>C;

    for(int i=0;i<C;i++)
    {
        int input_idx;

        cin>>input_idx;
        n.input.push_back(input_idx);
    }

    for(int i=0;i<C;i++)
    {
        int64   weight;

        cin>>weight;
        n.W.push_back(weight);
    }

    cin>>n.B;
    return  0;
}

int get_neural_model(void)
{
    vector<Node>    nodes;
    vector<int64>   w_out;
    
    for(int i=0;i<M;i++)
    {
        Node n;

        get_node(n);
        nodes.push_back(n);
    }

    for(int i=0;i<M;i++)
    {
        int64   w;

        cin>>w;
        w_out.push_back(w);
    }

    cin>>B_out;
    
    for(int i=0;i<M;i++)
    {
        B_out += w_out[i]*nodes[i].B;

        for(int j=0;j<nodes[i].input.size();j++)
        {
            int input_idx = nodes[i].input[j];
            int64 w = nodes[i].W[j];

            W[input_idx] += w*w_out[i];
        }
    }

    return  0;
}

int64   simulate(void)
{
    int64   ret = B_out;

    for(int i=1;i<=N;i++)
    {
        ret += A[i]*W[i];
    }

    return  ret;
}

int read_inputs(void)
{
    for(int i=1;i<=N;i++)
    {
        cin>>A[i];
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>N>>M>>Q;

    vector<Node>    n;

    get_neural_model();
    
    for(int i=1;i<=Q;i++)
    {
        read_inputs();
        cout<<simulate()<<'\n';
    }

    return  0;
}