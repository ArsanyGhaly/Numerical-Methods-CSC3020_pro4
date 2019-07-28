#if !defined (SAILBOATMAST_H)
#define SAILBOATMAST_H

#include "MultiVarAndEqnsFunction.h"
#include "Function.h"
#include "Heun.h"
class SailboatMast : MultiVarAndEqnsFunction
{
   private:

   public:
      double* evaluate(double* xy); 

};

#endif
