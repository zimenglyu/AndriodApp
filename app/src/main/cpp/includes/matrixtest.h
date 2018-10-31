//
// Created by Zimeng on 10/29/2018.
//

#include <Eigen>
#include <opencv/cv.h>
#include <opencv2/core.hpp>
#include <dlib/matrix.h>

#ifndef MYAPPLICATION_MATRIXTEST_H
#define MYAPPLICATION_MATRIXTEST_H


class matrixtest {

public:
    long EigenMethod(int n);
    long OpenCVMethod(int n);
    long DilbMethod(int n);

};


#endif //MYAPPLICATION_MATRIXTEST_H
