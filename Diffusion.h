#if !defined (DIFFUSION_H)
#define DIFFUSION_H

#include "MultiVarAndEqnsFunction.h"
#include "Function.h"

class Diffusion : public MultiVarAndEqnsFunction, public Function
{
   private:
		double D; 
		double K;
   public:
   Diffusion()
   {
	   
   }
      double* evaluate(double* xy); 
	  double evaluate(double x); 

};

#endif