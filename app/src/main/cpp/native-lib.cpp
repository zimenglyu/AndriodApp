#include <jni.h>
#include <string>
#include <Eigen>
#include <chrono>
#include <dlib/array.h>

#include <tensorflow/lite/kernels/register.h>
#include <tensorflow/lite/model.h>
#include <tensorflow/lite/op_resolver.h>
#include <tensorflow/lite/string_util.h>
#include <tensorflow/lite/kernels/kernel_util.h>
#include <tensorflow/lite/kernels/op_macros.h>

#include <tensorflow/lite/c/builtin_op_data.h>
#include <tensorflow/lite/c/c_api_internal.h>
#include <tensorflow/lite/kernels/internal/tensor.h>

#include <android/asset_manager.h>

#include "includes/matrixtest.h"


extern "C" JNIEXPORT jstring JNICALL

Java_com_example_zimeng_myapplication_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {



    std::unique_ptr<tflite::FlatBufferModel> model;
    std::unique_ptr<tflite::Interpreter> interpreter;
    model = tflite::FlatBufferModel::BuildFromFile("keras_cifar10.tflite");

    if (!model) {
        __android_log_print(ANDROID_LOG_INFO, "FlatBufferModel", "shit it failed"  );
    }
    else {
        __android_log_print(ANDROID_LOG_INFO, "FlatBufferModel", "it passed"  );
    }


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