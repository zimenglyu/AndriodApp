//
// Created by Zimeng on 10/29/2018.
//

#include "matrixtest.h"
#include <android/log.h>

float matrixtest::EigenMethod(int n) {

    Eigen::MatrixXd A = Eigen::MatrixXd::Random(n, n);
    Eigen::MatrixXd B = Eigen::MatrixXd::Random(n, n);
//    std::chrono auto start;
//    auto start=std::chrono::high_resolution_clock::now();
//    long long T [100];
    Eigen::MatrixXd C(n, n);
    float avgtime;
    float TimeAcc=0;
//    __android_log_print(ANDROID_LOG_INFO, " ,", "%d", 12345 );
    for (int i=0; i<100; i++){
        auto start = std::chrono::high_resolution_clock::now();
        C = A * B;
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
        auto Dtime = duration.count();
        TimeAcc +=Dtime;
//        T[i]=Dtime;
        __android_log_print(ANDROID_LOG_INFO, "Eigen", "%lld", Dtime );
        }

    avgtime=TimeAcc/100;

    return avgtime;
}

float matrixtest::OpenCVMethod(int n) {
    cv::Mat M1(n,n, CV_64F);
    cv::Mat M2(n,n, CV_64F);
    cv::Mat M3(n,n, CV_64F);
    double low = 1.0;
    double high= 100.0;
    cv::randu(M1, cv::Scalar(low), cv::Scalar(high));
    cv::randu(M2, cv::Scalar(low), cv::Scalar(high));
    float avgtime;
    float TimeAcc=0;

    for (int i=0; i<100; i++){
        auto start = std::chrono::high_resolution_clock::now();
        M3=M1*M2;
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
        auto Dtime = duration.count();
        TimeAcc +=Dtime;
        __android_log_print(ANDROID_LOG_INFO, "OpenCV", "%lld",Dtime  );
//        T[i]=Dtime;
    }
//    drawGraph(T, "opencv");
    avgtime=TimeAcc/100;
    return avgtime;
}

float matrixtest::DilbMethod(int n) {

    dlib::matrix<double> m1(n,n);
    dlib::matrix<double> m2(n,n);
    dlib::matrix<double> m3(n,n);
//    long T [100];
    float avgtime;
    float TimeAcc=0;
    for (int i=0; i<100; i++){
        auto start = std::chrono::high_resolution_clock::now();
        m3=m1*m2;
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
        auto Dtime = duration.count();
        TimeAcc +=Dtime;
        __android_log_print(ANDROID_LOG_INFO, "Dilb", "%lld",Dtime  );
//        T[i]=Dtime;
    }
//    drawGraph(T, "Dlib");
    avgtime=TimeAcc/100;
    return avgtime;
}

void matrixtest::drawGraph(long mat[], std::string name ){
    std::ofstream outputFile;

    std::string filename = name + ".csv";
    outputFile.open(filename);

    for (int counter = 0; counter <  100; counter++)
    {
        outputFile  << mat[counter] << "," << std::endl;
    }

    outputFile.close();
}
