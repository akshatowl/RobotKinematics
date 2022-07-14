#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#define pi 3.14159265
//Inverse Kinematics of a 2-dof RR robotic arm
int main()
{

    float link1,link2,x,y,base,elbow,endeff;
    printf("enter end effector coordinates\n");
    scanf("%f%f",&x,&y);
    printf("Enter link length(2)",&link1,&link2);
    scanf("%f%f",&link1,&link2);
    float m=atan2(y,x);
    float r=sqrt((x)*(x)+(y)*(y));
    float t=(link1*link1+r*r-link2*link2)/(2.0*r*link1);
    float u=(link1*link1+link2*link2-r*r)/(2.0*link1*link2);
    float v=(link2*link2+r*r-link1*link1)/(2.0*link2*r);
    if(t<=1.0&&t>=-1.0)
    {
     printf("Base Angles:%f&%f\n",(m+acosf(t))*180.0/pi,(m-cosf(t))*180.0/pi);
    }
    else{
        printf("INVALID");
    }

    if(u<=1.0&&u>=-1.0)
    {
        printf("Elbow:%f",acosf(u)*180.0/pi);
    }
    else{
        printf("INVALID\n");
    }
    if(v<=1.0&&v>=-1.0)
    {

        printf("End effector:%f",(pi-acosf(v))*180.0/pi);
    }
    else{
        printf("INVALID");
    }

    return 0;

}
