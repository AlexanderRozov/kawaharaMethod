#include <iostream>
#include <vector>
#include <fstream>
#include <math.h>
#include "Grid.h"
#include "Kawahara.h"

/*
 diffur solver*/

namespace diffur {


    void Solve();

    double T = 0;

    double F(double x, double y) {
        return sin(x * y);
    }

}

int main() {

    using namespace std;
    using namespace diffur;

//    int M = 100;
//    int N = 100;
//    double eps = 0.001;
//
//    Grid g(N,M,eps);
//    g.Init();
//    g.boundaries();
//    g.Solve();
//    g.PointsTOfile("points.txt");

    Kawahara a;

    a.solve();
    std::cout << "Computations Finish" << std::endl;
    return 0;
}



