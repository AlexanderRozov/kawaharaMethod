//
// Created by fog54 on 19.12.2021.
//

#include <fstream>
#include <valarray>
#include "Grid.h"

namespace diffur {

    Grid::Grid(int n, int m, double eps) {

        N = n;
        M = m;
        Eps = eps;

        points = std::vector<std::vector<Point>> (N, std::vector<Point>(M));

    }

    void Grid::Init() {
        for (int j = 0; j < M; ++j)
        {
            for (int i = 0; i < N; ++i)
            {
                Point p;
                p.x += i * Eps;
                p.y += j * Eps;
                p.value = 0;
                points[i][j] = p;
            }
        }
    }

    void Grid::PointsTOfile(std::string file_name)
    {
        std::ofstream point_file;
        point_file.open(file_name);

        for (int j = 0; j < M; ++j)
        {
            point_file << "X" << "  " << "Y" << "  " << "Z" << "\n";
            for (int i = 0; i < N; ++i) {
                point_file << points[i][j].x << ";" << points[i][j].y << ";" << points[i][j].value;
                //  point_file << points[i][j].x<<"  "<<points[i][j].y<<"  "<<points[i][j].value;
                point_file << "\n";
                //   point_file << points[i][j].value;

            }

        }
        point_file.close();
    }
    void Grid::Solve()
    {
        for (int j = 1; j < M-1; j++)
        {
            for (int i = 1; i < N-1; i++)
            {

                {
                    points[i][j].value = (points[i+1][j].value+points[i-1][j].value+points[i][j+1].value+points[i][j-1].value)/4;
                }
            }


        }
    }

    void Grid::boundaries()
    {
        for (int j = 0; j < M; j++)
        {
            for (int i = 0; i < N; i++)
            {
                if (i == 0 || j == 0
                 || i == N || j == M)
                {
                    points[i][j].value = F(points[i][j].x, points[i][j].y);
                }
            }


        }
    }

    double Grid::F(double x, double y)
    {
        return sin(x*y);
    }


}