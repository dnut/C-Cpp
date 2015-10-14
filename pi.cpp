#include <stdio.h>
#include <time.h>
#include <math.h>
#include <iostream>
#include "boost/random.hpp"
#include "boost/generator_iterator.hpp"
long double x;						//x coordinate
long double y;						//y coordinate
long double xs;						//x squared
long double ys;						//y squared
long double d;						//distance from center
long double in;						//count within circle
long double out;					//count outside circle
long double pi;						//pi
long double all;					//total count
int i;							//counter for each iteration
int j;							//counter for number of cycles chosen
long double r = 1.15;					//radius of circle
long double inp;					//number of cycles
long double big;
int conti;
int multi;
using namespace std;					//declare standard namespace
int main() {
  printf ("\n=====================================================================================\n");
  printf ("--------------------------------- PI CALCULATOR 2.0 ---------------------------------\n");
  printf ("Please indicate the number of calculation cycles (10^6 calculations each) you desire.\n");
  printf ("Choose a value and press enter:\n");
  scanf ("%Lf",&inp);					//accept numerical input
  typedef boost::mt19937 RNGType;			//boost will use mersenne twister generator
  RNGType rng(time(0));   				//seed using time
  boost::uniform_real<long double> neg2plus(-1,1);	//distribution neg2plus is -1 to 1 as long double numbers
  boost::variate_generator< RNGType, boost::uniform_real<long double> >   //bring random number into neg2plus distrib
  randoo(rng, neg2plus);				//define randoo as function using rng seed on neg2plus range
  while (conti == 0){
    for (j=1;j<inp+1;j++){				//main loop to repeat cycles according to input
      for (i=0;i<1000000;i++){				//10^6 calculations per cycle
        x = randoo();					//random x
        y = randoo();					//random y
        xs = x*x;
        ys = y*y;
        d = sqrt(xs + ys);				//pythagoras says
        if (d < 1){					//in circle?
  	  in++;
        }
        else{						//outside circle?
	  out++;
        }
      /* Use this to identify largest x
      if (x > big){
        big = x;
      } */
      /* Use this to print every detail of every calculation
      printf ("x %5.10Lf, y %5.10Lf, xs %5.10Lf, ys %5.10Lf, d %5.10Lf, in %5.0Lf, out %5.0Lf\n",x,y,xs,ys,d,in,out);
      */
      }
    pi = 4*in/(in+out);					//cumulatively calculate pi based on all data
    printf ("After %.0Lf cycles, pi is approximated to be: %1.20Lf\n",j+inp*multi,pi); //combine when repeated
    }
    printf ("\nWould you like to continue this process? If you choose to do so, this will enable you\n");
    printf ("to continue using the data you have already compiled and combine it with new data. If\n");
    printf ("this is what you would like, please enter 0 and the same number of loops will repeat.\n");
    printf ("If you would like to finish, please enter any other number.\n");
    scanf ("%d",&conti);				//scan input
    if (conti == 0){					//add to multiplier for counter in display
      multi++;
    }
  }
  printf ("\nCongratulations! You have calculated pi to be: %1.20Lf \n",pi);
  /*printf ("%1.20Lf\n",big); Use this to display largest x*/
}
