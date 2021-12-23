//
// Created by fog54 on 19.12.2021.
//

#ifndef UNTITLED2_GRID_H
#define UNTITLED2_GRID_H

#include <vector>
#include <string>

namespace diffur {
    template<typename T>
    double f(double x, double y);

    struct Point {
        double x;
        double y;
        double z;

        double value;
    };


    class Grid {
    public:
        Grid(int n, int m, double eps);
        void Init();
        void PointsTOfile(std::string file_name);
        void boundaries();
        void Solve();

        double F(double x, double y);
        std::vector<std::vector<Point>> points;

    private:
        int N, M;
        double Eps;
    };


#endif //UNTITLED2_GRID_H
}