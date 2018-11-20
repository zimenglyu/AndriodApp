#include <jni.h>
#include <string>
#include <Eigen>
#include <chrono>
#include <dlib/array.h>


#include "includes/matrixtest.h"


extern "C" JNIEXPORT jstring JNICALL

Java_com_example_zimeng_myapplication_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {

    matrixtest* mt = new matrixtest();
        int n = 500;
        float eigenResult = mt->EigenMethod(n);
        float opencvResult = mt->OpenCVMethod(n);
        float dlibResult = mt-> DilbMethod(n);
        std::stringstream ss;
        ss << "Eigen: " << eigenResult << "ms OpenCV: " << opencvResult << "ms Dlib: " << dlibResult <<"ms";
//        ss << eigenResult<<" ms";
        const std::string tmp = ss.str();
        const char *cstr = tmp.c_str();
        return env->NewStringUTF(cstr);


}