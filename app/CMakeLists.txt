set(pathToProject /Users/zimenglyu/Documents/git/AndriodApp)
set(pathToOpenCv /Users/zimenglyu/Documents/cpplibs/libraries/OpenCV-android-sdk)
set(pathToDlib /Users/zimenglyu/Documents/cpplibs/libraries/DlibFolder)
set(pathToTensorflowLite /Users/zimenglyu/Documents/cpplibs/libraries/tensorflow-lite/distribution)

# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

set(CMAKE_VERBOSE_MAKEFILE on)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

include_directories(${pathToOpenCv}/sdk/native/jni/include)

include_directories(${pathToDlib})

include_directories(/Users/zimenglyu/Documents/cpplibs/libraries/Eigen)

include_directories(src/main/cpp/includes)

#include_directories(/Users/zimenglyu/Documents/cpplibs/libraries/dlib)
# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

add_library( lib_opencv SHARED IMPORTED )

set_target_properties(lib_opencv PROPERTIES IMPORTED_LOCATION ${pathToProject}/app/src/main/jniLibs/${ANDROID_ABI}/libopencv_java3.so)

add_library( # Sets the name of the library.
             native-lib

             # Sets the library as a shared library.
             SHARED

             # Provides a relative path to your source file(s).
             src/main/cpp/native-lib.cpp
             src/main/cpp/matrixtest.cpp )

add_library(libtensorflowLite SHARED IMPORTED)

set_target_properties(libtensorflowLite PROPERTIES IMPORTED_LOCATION
    ${pathToTensorflowLite}/lib/${ANDROID_ABI}/libtensorflowLite.so)

target_include_directories(native-lib PRIVATE
            ${pathToTensorflowLite}/include)

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library( # Sets the name of the path variable.
              log-lib

              # Specifies the name of the NDK library that
              # you want CMake to locate.
              log )

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
                       native-lib

                       libtensorflowLite

                        # NOTE: this is important to get opencv to compile
                        lib_opencv

                       # Links the target library to the log library
                       # included in the NDK.
                       ${log-lib} )
#target_link_libraries(native-lib
#                        dlib::dlib
#                        log)