#include "Diffusion.h"
#include "Heun.h"
#include <iostream> 
#include "FalsePosition.h"
#include "MultiVarAndEqnsFunction.h"

using namespace std; 

double* Diffusion::evaluate(double* xy)
{
	 D = 0.000015; 
	K = 0.000005;
// D * (((d2) * A) / (dx^2)) - K * A
double* new_xy = new double[3]; 

new_xy[0] = xy[0]; 


 
new_xy[1] = xy[1]; 

new_xy[2] = ((K * xy[1]) / D); 

return new_xy; 
}


double Diffusion::evaluate(double A)
{
	Heun* h1 = new Heun();
	double* xy = new double[3];
	xy[0] = 0.0; 
	xy[1] = A; 
	xy[2] = 0.0; 
	xy = h1->rk4Multiple(this, 0.1, xy, 0.1);
	return (xy[2] - 0.1); // was - 0.1 at 4cm concentration is 0; 
}



int main() 
{
 Heun* h1 = new Heun();
Diffusion* diffusion_problem = new Diffusion(); 
double* xy = new double[3];


//xy = h1->rk4Multiple(diffusion_problem, 0.1, xy, 4); 

FalsePosition* fp = new FalsePosition(); 
double* z = fp->falsePosition(diffusion_problem, -30, 4, 0.001,150); // integral from 0 to 4
xy[1] = z[0];

xy = h1->stepsHeunMultiple(diffusion_problem, 4, 0.1, xy, 2, 0.01);

cout << "x = " << xy[0] << endl; 
cout << "z = " << xy[1] << endl; 
cout << "A = " << xy[2] << endl; 

cout << endl; 
cout << endl; 
cout << endl;  


return 0; 
}