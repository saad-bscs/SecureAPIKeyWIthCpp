#Protect API key from Reverse engineering by using native C++ code

Steps to follow: 

1- First install NDK and CMake by opening sdk manager from Tools section. Under sdk manager, navigate to sdk tools and install NDK(side by side)
and CMake.

2- Now make a folder under Project -> src -> main directory and name it cpp.

3- Create new class CMakeLists.txt and second class native-lib.cpp

4- Open CMakeLists.txt and write below code,

    cmake_minimum_required(VERSION 3.10.2)
    add_library(
    native-lib
    SHARED
    native-lib.cpp
    )
    target_link_libraries(
    native-lib
    ${log-lib}
    )

5- Now open build.gradle(app) and add below code under android section,

    externalNativeBuild {
    cmake {
    path "src/main/cpp/CMakeLists.txt"
    }
    }

In newer versions of android studio, build.gradle.kts file is present, so the code will be like this,

    externalNativeBuild {
    cmake {
    path ("src/main/cpp/CMakeLists.txt")
    }
    }

6- Now open MainActivity or fragment and write below code before onCreate method,

    object Keys {
    init {
    System.loadLibrary("native-lib")
    }
    external fun APIKey() : String
    }

After writing above code, it will highlight red on APIKey(), hover on APIKey(), it will show Create JNI function for APIKey(), click on it and it will
create a function in native-lib.cpp class like below,

    extern "C"
    JNIEXPORT jstring JNICALL
    Java_com_example_secrureapiwithcpp_MainActivity_00024Keys_APIKey(JNIEnv *env, jobject thiz) {
    return env ->NewStringUTF("Ayzgfhsfgsdjh123jsdhf"); /* Here write your Api Key*/

7- Now access your APIKey like below,

    Log.e("API-Key: ",""+Keys.APIKey())

That's it from my side. See code if you have any confusion. Keep learning.