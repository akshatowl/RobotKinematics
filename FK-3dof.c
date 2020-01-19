#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#define pi 3.141592

void polarxy(float theta,float *x,float *y,float link) //to get cartesian coordinates from angle
{
    *x=link*cosf(theta);
    *y=link*sinf(theta);

}
void calc(float *x03,float *y03,float theta1,float theta2,float theta3,float link1,float link2,float link3)
{
    float x01,y01,x12,y12,x23,y23;

    polarxy(theta1,&x01,&y01,link1);
    polarxy(theta2,&x12,&y12,link2);
    polarxy(theta3,&x23,&y23,link3);

    *x03=x01+x12+x23;    //resultant x component
    *y03=y01+y12+y23;   //resultant y coordinate

}
int main()
{
    float theta1,theta2,theta3,link1,link2,link3,thetai1,thetai2,x,y;
    int cond=0;
    printf("Enter link lengths\n");
    scanf("%f%f%f",&link1,&link2,&link3);
    printf("Enter 3 angle parameters\n");
    scanf("%f%f%f",&theta1,&theta2,&theta3);

    if(theta2>=0.0&&theta2<180.0)    //finding out net angle with respect to coordinate frame
    {
        thetai1=theta1+theta2;
       cond++;
    }
  
    else if(theta2>-180.0&&theta2<0.0){
        thetai1=theta1-theta2;
       cond++;
    }
     else
    {
        printf("INVALID\n");
    }

    if(theta3>=0.0&&theta3<180.0)
    {
        thetai2=thetai1+theta3;
       cond++;
    }
   else if(theta3>-180.0&&theta3<0.0){
        thetai2=thetai1-theta3;
       cond++;
    }
    else 
    {
        printf("INVALID\n");
    }
    
    calc(&x,&y,theta1*pi/180.0,thetai1*pi/180.0,thetai2*pi/180.0,link1,link2,link3);
   if(cond==2)
   {
    printf("End-effector X:%f\tEnd-effector Y:%f\n",x,y);
   }
    return 0;
}
//theta 1 is angle wrt base and theta2 is angle of link2 with respect to link1
// thetai1 is angle with respect to x-axis
//thetai2 is angle of link3 wrt x-axis
//cond is just a conditional variable which allows us to print only if both angles follow the specified conditions


