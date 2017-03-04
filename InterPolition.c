#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    FILE *f=fopen("data.txt","r");
    double lower=1,datup=80,datlow=10,mf;
    int upper,x,middle,p=2,datmid;
    fseek(f,0,2);
    upper=ftell(f)/4;
    fseek(f,0,0);
    fscanf(f,"%d\n",&datlow);
    fseek(f,(upper-1)*4,0);
    fscanf(f,"%d\n",&datup);
    printf("which value are you looking for?:\n");
    scanf("%d",&x);
    while(lower<upper)
    {
        mf=lower+(x-datlow)*(upper-lower)/(datup-datlow);
        printf("%f----\n",mf);
        middle=ceil(mf);
        fseek(f,(middle-1)*4,0);
        fscanf(f,"%d\n",&datmid);
        printf("The middle is =%d\n",middle);
        if(x==datmid)
        {
            printf("I found it!!--Data Middle is=%d\nThe Total probe number is:%d",datmid,p);
            break;
        }
        else if(x<datmid)
          {
                upper=middle-1;
            p++;
          }
        else
            {
                lower=middle+1;
              p++;
            }
        fseek(f,(lower-1)*4,0);
        fscanf(f,"%d\n",&datlow);
        fseek(f,(upper-1)*4,0);
         fscanf(f,"%d\n",&datup);
    }
    if(x!=datmid)
        printf("Sorry I could not find your number\nThe total probe number is : %d",p);

    return 0;
}
