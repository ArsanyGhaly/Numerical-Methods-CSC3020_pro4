#if !defined (FUNCTION_H)
#define FUNCTION_H

class Function
{
   private:

   public:
      Function() {};
      ~Function() {};
      virtual double evaluate(double x) = 0;
};

#endif
