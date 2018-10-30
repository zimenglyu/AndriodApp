//
// Created by Zimeng on 10/29/2018.
//

#include "matrixtest.h"

long matrixtest::EigenMethod(int n) {
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
