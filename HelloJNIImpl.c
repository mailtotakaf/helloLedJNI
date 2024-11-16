#include <jni.h>
#include "HelloJNI.h"
#include <stdio.h>

JNIEXPORT void JNICALL Java_HelloJNI_printHello(JNIEnv *env, jobject obj) {
    printf("Hello World from JNI!\n");
    return;
}
