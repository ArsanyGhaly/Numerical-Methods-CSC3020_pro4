#include "Heun.h"
#include <math.h>
#include "SailboatMast.h"
#include <iostream>
#include "Diffusion.h" 

using namespace std; 

double* Heun::rk4Multiple(MultiVarAndEqnsFunction* f, double h, double* xy,double upper_bound) 
{
	
	double* new_xy = new double[3]; 
	new_xy[0] = 0; 
	new_xy[1]= xy[1]; 
double curr_x = xy[0]; 
while(curr_x < upper_bound)
{
	

	double* FA = f->evaluate(xy);
	double* update_xy = new double[3];
	double k1 = FA[2];
	double* fz = new double[3]; 
	fz[0] = xy[0] + h/2; 
	fz[1] = xy[1] + ((h * k1)/2); 
	fz = f->evaluate(fz); 
	double k2 = fz[2]; 
	
	fz[1] = xy[1] + (k2 * h )/ 2; 
	fz = f->evaluate(fz); 
	double k3  = fz[2]; 
	
	fz[0] = xy[0] + h; 
	fz[1] = xy[1] + (k3 * h); 
	fz = f->evaluate(fz); 
	double k4 = fz[2]; 
	new_xy[1]= xy[2] + (k3* h) / 2; 
	new_xy[2] = xy[1] +((k1 + ( 2 *k2) + (2 * k3) + k4) / 6);
	double* _xy = f->evaluate(new_xy); 
	
	
	curr_x += h;
	new_xy[0]=curr_x;
	xy[0] = curr_x;
	xy[1] = new_xy[1]; 
	xy[2]= _xy[2];
	
}
	return new_xy;
}
double* Heun::heunMultiple(MultiVarAndEqnsFunction* f, double h, double* xy0, double upper_bound, int numeq, double tol)
{
	
		xy0 = this->rk4Multiple(f,h,xy0,upper_bound); 
	
	
	return xy0; 
}
double* Heun::stepsHeunMultiple(MultiVarAndEqnsFunction* f, double upper_bound, double h, double* xy, int numeq, double tol)
{
	
	return heunMultiple(f,h,xy,upper_bound,numeq,tol); 
	
	
}
