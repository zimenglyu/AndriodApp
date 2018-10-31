//
// Created by Zimeng on 10/29/2018.
//

#include "matrixtest.h"
#include <android/log.h>

long matrixtest::EigenMethod(int n) {
  //  Eigen::Matrix2f A = Eigen::Matrix2f::Random(n, n);
   // Eigen::Matrix2f B = Eigen::Matrix2f::Random(n, n);
    Eigen::MatrixXd A = Eigen::MatrixXd::Random(n, n);
    Eigen::MatrixXd B = Eigen::MatrixXd::Random(n, n);
//    std::chrono auto start;
//    auto start=std::chrono::high_resolution_clock::now();
    Eigen::MatrixXd C(n, n);
    auto start = std::chrono::high_resolution_clock::now();
    C = (A * B);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    auto Dtime = duration.count();
    return Dtime;
}

long matrixtest::OpenCVMethod(int n) {
    cv::Mat M1(n,n, CV_64F);
    cv::Mat M2(n,n, CV_64F);
    cv::Mat M3(n,n, CV_64F);
    double low = 1.0;
    double high= 100.0;


    cv::randu(M1, cv::Scalar(low), cv::Scalar(high));
    cv::randu(M2, cv::Scalar(low), cv::Scalar(high));

//    __android_log_print(ANDROID_LOG_DEBUG, "Data: ", "Hello");


    auto start = std::chrono::high_resolution_clock::now();
    M3=M1*M2;
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    auto Dtime = duration.count();
    return Dtime;
}

long matrixtest::DilbMethod(int n) {

    dlib::matrix<double> m1(n,n);
    dlib::matrix<double> m2(n,n);
    dlib::matrix<double> m3(n,n);
    auto start = std::chrono::high_resolution_clock::now();
    m3=m1*m2;
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    auto Dtime = duration.count();
    return Dtime;
}
