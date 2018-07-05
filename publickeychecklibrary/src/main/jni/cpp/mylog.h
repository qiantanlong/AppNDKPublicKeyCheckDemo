//
// Created by hongzhen on 2018/7/4.
//

#ifndef NDKDEBUGDEMO_MYLOG_H
#define NDKDEBUGDEMO_MYLOG_H
//
// Created by hongzhen on 2018/5/11.
//
#include <android/log.h>
#ifndef NOSIGNAGINDEMO2_MYLOG_H
#define NOSIGNAGINDEMO2_MYLOG_H
#define TAG "myDemo-jni" // 这个是自定义的LOG的标识
#define LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,TAG,__VA_ARGS__) // 定义LOGD类型
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,TAG ,__VA_ARGS__) // 定义LOGI类型
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN,TAG ,__VA_ARGS__) // 定义LOGW类型
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,TAG ,__VA_ARGS__) // 定义LOGE类型
#define LOGF(...) __android_log_print(ANDROID_LOG_FATAL,TAG ,__VA_ARGS__) // 定义LOGF类型
#endif //NOSIGNAGINDEMO2_MYLOG_H
#endif //NDKDEBUGDEMO_MYLOG_H
