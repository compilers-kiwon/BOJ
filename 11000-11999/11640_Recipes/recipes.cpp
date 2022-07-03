#include    <iostream>
#include    <string>
#include    <vector>

using namespace std;

typedef struct{string name;float w,p;} Ingredient;

#define determine_scaling_factor(wp,dp) ((dp)/(wp))
#define get_scaled_main_weight(f,w)     ((f)*(w))
#define get_scaled_weight(w,p)          ((w)*(p)/100.0f)

void    input(vector<Ingredient>& ing,int& num_of_ingredients,
                    float& written_portion,float& desired_portion)
{
    cin>>num_of_ingredients>>written_portion>>desired_portion;

    for(int i=1;i<=num_of_ingredients;i++)
    {
        Ingredient  n;

        cin>>n.name>>n.w>>n.p;
        ing.push_back(n);
    }
}

Ingredient  find_main_ingredient(const vector<Ingredient>& ing)
{
    Ingredient  ret;

    for(int i=0;i<ing.size();i++)
    {
        if( ing[i].p == 100.0 )
        {
            ret = ing[i];
            break;
        }
    }

    return  ret;
}

void    print_recipe(int idx,const vector<Ingredient>& ing)
{
    cout<<"Recipe # "<<idx<<'\n';

    for(int i=0;i<ing.size();i++)
    {
        cout<<ing[i].name<<' '<<ing[i].w<<'\n';
    }

    cout<<"----------------------------------------\n";
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin>>T;
    cout.setf(ios::fixed);cout.precision(1);

    for(int t=1;t<=T;t++)
    {
        int                 R;
        float               P,D,scaling_factor;
        Ingredient          main_ingredient;
        vector<Ingredient>  recipe;

        input(recipe,R,P,D);

        main_ingredient = find_main_ingredient(recipe);
        scaling_factor = determine_scaling_factor(P,D);
        main_ingredient.w = get_scaled_main_weight(scaling_factor,main_ingredient.w);

        for(int i=0;i<recipe.size();i++)
        {
            recipe[i].w = get_scaled_weight(main_ingredient.w,recipe[i].p);
        }

        print_recipe(t,recipe);
    }

    return  0;
}