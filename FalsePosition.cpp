#include "FalsePosition.h"
#include <math.h>

double* FalsePosition::falsePosition(Function* f, double l, double u, double tol, int max)
{
   if (max < 0) 
   {
      max = 10;
   }

   double fl = f->evaluate(l);
  
   double fu = f->evaluate(u);
 

   if (fl * fu > 0)  //a zero has not been properly bracketed
   {
      return new double[0];
   }

   double r = u - (fu * (l - u)) / (fl - fu);
   double fr = f->evaluate(r);
  

   int iter = 1;
   double error = tol + 1;

   while (error > tol && iter < max)  
   {
      double rold = r;

      double temp = fr * fl;
      if (temp > 0)
      { 
         l = r;
         fl = fr;
      }
      else if (temp < 0)
      {
         u = r;
         fu = fr;
      }
      else  //hit the zero by chance
      {
         error = 0;
         break;
      }

      r = u - fu * (u - l) / (fu - fl);
      fr = f->evaluate(r);
     

      if (fabs(r) > .0001)  //avoid divide by zero
      {
         error = fabs( (r - rold) / r);  //approximate error (problematic for false position)
        
      }
      else
      {
         error = 1;
      }

      iter++;
   }
      
   double* temp = new double[3];
   temp[0] = r;
   temp[1] = error;
   temp[2] = iter;

   return temp;
}
