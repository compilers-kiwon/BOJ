#include    <iostream>
#include    <cmath>

using namespace std;

int main(void)
{
    for(;;)
    {
        float   D,RH,RV,H,W;

        scanf("%f %f %f",&D,&RH,&RV);

        if( D==0.0f && RH==0.0f && RV==0.0f )
        {
            break;
        }

        H = (9.0f*D)/(16.0f*sqrt(1.0f+81.0f/256.0f));
        W = D/sqrt(1.0f+81.0f/256.0f);

        printf("Horizontal DPI: %.02f\n",RH/W);
        printf("Vertical DPI: %.02f\n",RV/H);
    }

    return  0;
}