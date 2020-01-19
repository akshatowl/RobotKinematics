#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define pi 3.14159265


void polarxy(float link,float theta,float *a,float *b) //polar coordinates to Cartesian system conversion function
{
    *a=link*cosf(theta);
    *b=link*sinf(theta);
}

void compute(float theta1,float theta2,float *x02,float *y02,float L1,float L2)
{
    float x01,y01,x12,y12;
    polarxy(L1,theta1,&x01,&y01);
    polarxy(L2,theta2,&x12,&y12);


    *x02=x01+x12; //x02 end effector_X
    *y02=y01+y12; //y02 end effector_Y
}


int main()
{
    float link1,link2,x,y,x1,y1,angle1,angle2,angle3;
    printf("Enter the constant link length(2)\n");
    scanf("%f%f",&link1,&link2);
    printf("Enter the angles wrt frames desired\n");
    scanf("%f%f",&angle1,&angle2);
    if(angle2>=0.00&&angle2<180.00)       //angle2 wrt link1
    {
        angle3=angle1+angle2;  //angle3 is angle of link2 wrtxy (ease of computing
    }
    else if(angle2<0.00&&angle2>-180.00){
        angle3=angle1-angle2;
    }

    if(angle2>=180.00||angle2<=-180.00) //impossible set
    {
        printf("IMPOSSIBLE CONFIG");
    }
    else{
    compute(angle1*pi/180.0,angle3*pi/180.0,&x,&y,link1,link2); //degree conversion
    printf("X:%f\tY:%f\n",x,y);
    }

  return 0;
}
