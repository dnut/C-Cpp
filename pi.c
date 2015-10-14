// Copyright Drew Nutter
#include <stdio.h>
#include <time.h>
#include <math.h>
int i;						//individual iteration counter
long long int d;				//distance from center
long long int x;				//x coordinate
long long int y;				//y coordinate
long long int r = 2147483648/2;			//radius
long long int xs;				//x squared
long long int ys;				//y squared
long double in;					//count within circle
long double out;				//count outside circle
long double pi;					//value of pi averaged at each loop
long long int big;				//largest radius so far
int j;						//main loop counter
int k;						//final calculations counter
long double ji[1000000];			//array containing 
long long int ni;				//scaled in counter
long int tuo;					//scaled out counter
long double fli;				//value of pi compiled from all data at the end
int inp;					//#iterations
main(){						//main entire code
srand(time(NULL));
printf ("\n=====================================================================================\n");
printf ("----------------------------------- PI CALCULATOR -----------------------------------\n");
printf ("Please indicate the number of calculation cycles (10^7 calculations each) you desire.\n");
printf ("Choose a value and press enter:\n");
scanf ("%d",&inp);				//accept numerical input
printf ("Please be patient, %d calculations are taking place!\n",inp);
for (j=0;j<inp;j++){				//begin main loop given number of cycles
  in = 0;					//set counts to zero for each iteration
  out = 0;
  for (i=0;i<12000000;i++){			//begin iteration. one iteration contains 12M calculations
    x = rand() - r;				//get "random" coordinates
    y = rand() - r;				//subtract r to center circle/square around origin of (0,0)
    xs = x*x;					//find the square of each coordinate
    ys = y*y;
    d = sqrt(xs + ys);				//pythagoras says
    if (d < r){					//inside circle?
      in++;
    }
    else{					//outside circle?
      out++;
    }
    /* This segment of code will find the largest radius so far
    if (d > big){
      big = d;
    }*/
  }						//iteration end
  int all = in + out;				//total number of events
  ni = ni + in/inp;				//scale down "in" counter according to #iterations to prevent overflow
  tuo = tuo + out/inp;				//same as above for "out." add with previous scaled counts
  ji[j] = 4*in/all;				//save array value for this iteration's calculated pi
  printf ("Calculation %d out of %d is %1.30Lf\n",j+1,inp,ji[j]);
}
in=ni;						//computer does not like using ni and tuo to find average
out=tuo;					//it gives value of pi as 3.00000 unless this is done
int all = in + out;				//total scaled data
for (k=0;k<inp;k++){
  pi = pi + ji[k];				//each iterations pi calculation added
}
pi = pi/inp;					//find average pi value for iterations added
fli = 4*in/all;					//pi calculated based on cumulative scaled in/all
printf ("The average calculated pi is %1.30Lf.\nThe comprehensively calculated pi is %1.30Lf.\n",pi,fli);
return 0;
}
