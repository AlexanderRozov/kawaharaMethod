#include <iostream>
#include <vector>
#include <fstream>
#include <math.h>

/*
 diffur solver*/

struct Point {
    double x;
    double y;
    double z;

    double value;
};


void InitPoints(int &N, int &M, double &eps, std::vector<std::vector<Point>> &points) {


    for (int j = 0; j < M; ++j) {
        for (int i = 0; i < N; ++i) {
            Point p;
            p.x += i * eps;
            p.y += j * eps;
            p.value = 0;
            points[i][j] = p;
        }
    }
}

void pointsTOfile(int &N, int &M, std::vector<std::vector<Point>> points) {
    std::ofstream point_file;
    point_file.open("example.csv");
    for (int j = 0; j < M; ++j) {
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

double T;

double F(double x, double y) {
    return sin(x * y);
}

void Boundaries_and_initConditions(int &N, int &M, double &eps, std::vector<std::vector<Point>> &points) {
    T = 0;
    for (auto p: points) {

    }

}

int main() {

    using namespace std;
    int M = 100;
    int N = 100;

    double eps = 0.001;

    std::vector<std::vector<Point>> points(N, std::vector<Point>(M));

    InitPoints(N, M, eps, points);
    pointsTOfile(N, M, points);


    std::cout << "Hello, World!" << std::endl;
    return 0;
}


