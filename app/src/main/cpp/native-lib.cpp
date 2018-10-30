#include <jni.h>
#include <string>
#include <Eigen>
#include <chrono>
#include "includes/matrixtest.h"

extern "C" JNIEXPORT jstring JNICALL



Java_com_example_zimeng_myapplication_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {

//    using namespace std::chrono;
//    Eigen::MatrixXd A = Eigen::MatrixXd::Random(500,500);
//    Eigen::MatrixXd B = Eigen::MatrixXd::Random(500,500);
////    std::chrono auto start;
////    auto start=std::chrono::high_resolution_clock::now();
//    Eigen:: MatrixXd C(500,500);
//    auto start = std::chrono::high_resolution_clock::now();
//    C = (A*B);
//    auto stop = std::chrono::high_resolution_clock::now();
//    auto duration=std::chrono::duration_cast<std::chrono::milliseconds>(stop-start);

    matrixtest* mt = new matrixtest();

        long Duration = mt->EigenMethod(500);
        std::stringstream ss;
        ss << Duration;

        const std::string tmp = ss.str();
        const char *cstr = tmp.c_str();

        return env->NewStringUTF(cstr);


}