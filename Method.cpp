//
// Created by fog54 on 20.12.2021.
//

#include "Method.h"
#include <cmath>

int n = 100,p = 3;
double h,tau,t,time_stop;

int step;


double h_3 = pow(h,3);
double h_5 = h_3* pow(h,2);

double alpha = 1,beta = 2,Gamma = 3;

inline double du_dx(const double u[],int j) // first derivative
{
    return (u[j+1]-u[j-1])/(2*h);
}
inline double du_dx3(const double u[],int j) // third derivative
{
    return (u[j+2]-2*u[j+1]+2*u[j-1]-u[j-2])/(2*h_3);
}
inline double du_dx5(const double u[],int j) // five derivative
{
    return (u[j+3]-4*u[j+2]+5*u[j+1]-5*u[j-1]+
    4*u[j-2]-u[j+3])/(2*h_5);
}

double* swap;

void Method::solve()
{
    double * u_p = (double *)calloc(n+2*p,sizeof (double ));
    double * u_c = (double *)calloc(n+2*p,sizeof (double ));
    double * u_n = (double *)calloc(n+2*p,sizeof (double ));

    while (t<time_stop)
    {
        for(int j = p;j<n+p;++j)
        {
            u_n[j] = u_p[j] + 2*tau*(alpha* pow(u_c[j],2)* du_dx(u_c,j)+
                    beta * du_dx3(u_c,j) - Gamma * du_dx5(u_c,j));
            ;
#ifdef PERIODBOUND
            for(int j = p;j<p;++j)
                u_n[j] = u_n[j-n];
            for(int j = n+p;j < n+p*2;++j)
                u_n[j] = u_n[j-n];
#endif

            t = tau*step;step++;
            swap = u_n;
            u_n = u_p;
            u_p  = u_c;
            u_c = swap;
        }

    }
}
