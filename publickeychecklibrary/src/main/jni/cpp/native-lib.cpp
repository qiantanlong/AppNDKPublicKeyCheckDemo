#include <jni.h>
#include <string>
#include "getK.h"
#include <cstring>

#ifdef __cplusplus
extern "C" {
#endif
char *AUTH_KEY = "11111";
JNIEXPORT jstring

JNICALL
Java_com_hongzhen_publickeychecklibrary_CheckUtils_getKey(
        JNIEnv *env, jclass thizz,
        jobject job /* this */) {
//    jboolean result = getCourseKeyFromC(env, thizz, job);
    MyK myK;
    jboolean result = myK.getCK(env, thizz, job);
    if (result) {
        return env->NewStringUTF(AUTH_KEY);
    } else {
        return env->NewStringUTF("error");
    }

#ifdef __cplusplus
}
}
#endif
