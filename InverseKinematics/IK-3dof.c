#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#define pi 3.141592
/*Geometric approach for INVERSE KINEMATICS OF A 3-DOF planar RRR robotic arm
Base is fixed at origin*/

void interpoints(float *xi,float *yi,float x,float y,float theta,float link) //Finds coordinates of 3rd joint
{
    *xi=x-link*cos(theta);
    *yi=y-link*cos(theta);
}

void corrector(float *x,float *y) //if entered point is outside Configuration Space
{
    printf("Base Angle:%f Elbow Angle: 180.00 Gamma parameter:%f",atan2f(*y,*x)*180.0/pi,atan2f(*y,*x)*180.0/pi);//straight line of length link1+link2+link3 to be closest to point outside C-space
}

int main()
{
    float x,y,link1,link2,link3,xi,yi,gamma;  //x,y:end-effector coordinates,gamma is the angle made with respect to x axis by 3rd link
    printf("Enter end effector coordinates\n");
    scanf("%f%f",&x,&y);
    printf("Enter gamma parameter\n");
    scanf("%f",&gamma);
    printf("Enter the link lengths\n");
    scanf("%f%f%f",&link1,&link2,&link3);
   if(sqrtf(x*x+y*y)<=link1+link2+link3)
   {
      interpoints(&xi,&yi,x,y,gamma*pi/180.0,link3);
   }
   else{
      corrector(&x,&y);
      return 0;
   }
    float slopei=atan2(yi,xi);  //angle made by line joining origin with joint 3 coordinates
    float r=sqrtf(xi*xi+yi*yi); //distance of joint 3 from origin
    float t=(link1*link1+r*r-link2*link2)/(2.0*link1*r);   //cosine rule input equation computed separately
    float u=(link1*link1+link2*link2-r*r)/(2.0*link1*link2);
    float v=(link2*link2+r*r-link1*link1)/(2.0*link2*r);
    if(t>=-1&&t<=1)
    {
      printf("Base Angles:%f and %f\n",(slopei+acosf(t))*180.0/pi,(slopei-acosf(t))*180.0/pi);//2 solutions for base angles about line joining origin and 3rd joint coordinate
    }
    else{
        printf("INVALID\n");
    }

    if(u>=-1&&u<=1) //specifying validity of cos inverse
    {
        printf("Elbow Angle:%f",acosf(u)*180.0/pi);
    }
    else{
        printf("INVALID\n");
    }
   if(v>=-1&&v<=1)
   {
       printf("\tLINK 3 angles:%f",(pi-acosf(v))*180.0/pi);
   }
   else{
    printf("INVALID\n");
    printf("\nReconfigured OUTPUT:\n");
    corrector(&x,&y);
   }
return 0;
}

//Correction feature is automatic if the point is outside configuration space.The arm will try to adjust as close to the point
//all angles outputted are with respect to links

