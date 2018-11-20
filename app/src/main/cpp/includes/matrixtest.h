//
// Created by Zimeng on 10/29/2018.
//

#include <Eigen>
#include <opencv/cv.h>
#include <opencv2/core.hpp>
#include <dlib/matrix.h>
#include <android/log.h>

//#define  LOG_TAG    "Eigen"
//#define  LOGD(...)  __android_log_print(ANDROID_LOG_INFO, LOG_TAG, )
//#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)
#ifndef MYAPPLICATION_MATRIXTEST_H
#define MYAPPLICATION_MATRIXTEST_H


class matrixtest {

public:
    float EigenMethod(int n);
    float OpenCVMethod(int n);
    float DilbMethod(int n);
    void drawGraph(long mat[], std::string name );
};


#endif //MYAPPLICATION_MATRIXTEST_H
