#if !defined (FALSEPOSITION_H)
#define FALSEPOSITION_H

#include "MultiVarAndEqnsFunction.h"
#include "Function.h"

class FalsePosition
{
   private:

   public:
      static double* falsePosition(Function* f, double l, double u, double tol, int max);

};

#endif
