#include <jni.h>


extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_secrureapiwithcpp_MainActivity_00024Keys_APIKey(JNIEnv *env, jobject thiz) {
    return env ->NewStringUTF("Ayzgfhsfgsdjh123jsdhf"); /* Here Api Key*/
}
extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_secrureapiwithcpp_MainActivity_00024Keys_APIKey1(JNIEnv *env, jobject thiz) {
    return env ->NewStringUTF("Another API");
}
extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_secrureapiwithcpp_MainActivity_00024Keys_APIKey2(JNIEnv *env, jobject thiz) {
    return env ->NewStringUTF("Another API 3");
}