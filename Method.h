//
// Created by fog54 on 20.12.2021.
//

#ifndef UNTITLED2_METHOD_H
#define UNTITLED2_METHOD_H


#include <string>

class Method
        {
        public:
    Method(int n, int m, double eps);
    virtual void Init();
    virtual void PointsTOfile(std::string file_name);
    virtual void boundaries();
    virtual double F(double x, double y);

};


#endif //UNTITLED2_METHOD_H
