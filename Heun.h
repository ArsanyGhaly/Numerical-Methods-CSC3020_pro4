#if !defined (HEUN_H)
#define HEUN_H

#include "MultiVarAndEqnsFunction.h"
#include "Function.h"

class Heun
{
   private:

   public:
 double* rk4Multiple(MultiVarAndEqnsFunction* f, double h, double* xy, double upper_bound); //needed for non-self-starting Heun
 double* heunMultiple(MultiVarAndEqnsFunction* f, double h, double* xy0, double upper_bound, int numeq, double tol);
 double* stepsHeunMultiple(MultiVarAndEqnsFunction* f, double upper_bound, double h, double* xy, int numeq, double tol); //needs two previous steps

};

#endif