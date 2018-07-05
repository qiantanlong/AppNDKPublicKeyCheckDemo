//
// Created by hongzhen on 2018/6/15.
//
#include <iostream>
#include <jni.h>
#include <cstring>
#include "getK.h"
#include "mylog.h"

using namespace std;
bool MyK::getCK(JNIEnv *env, jclass thizz, jobject contextObject) {

//    string RELEASE_KSY="your key";替换成自己的，下方日志会输出。如果是正式签名文件，可以保存到本地后，再粘贴过来，进行验证
    string RELEASE_KSY="308201dd30820146020101300d06092a864886f70d010105050030373116301406035504030c0d416e64726f69642044656275673110300e060355040a0c07416e64726f6964310b3009060355040613025553301e170d3137303632373031323033315a170d3437303632303031323033315a30373116301406035504030c0d416e64726f69642044656275673110300e060355040a0c07416e64726f6964310b300906035504061302555330819f300d06092a864886f70d010101050003818d00308189028181009f797705bb9c515c8c937ad561978bf9e6ddc180e1646f354c2ca4b2f89be003809c4b733943c305755e17b857f59805f30e1a13d629cebe2460679f4b6f61080aa89e7b7965a0bb23611efd386e39df569b0931e2dfd0bbf867ebd99f8a8fb113783796e0c67d6889cd5b9291b6a91c7fd6ed4ceca7c670d2ee459382dad1c30203010001300d06092a864886f70d01010505000381810086e508a029ecdb53b1ea57fd28a090049099f111add307d23e9b193f19cee6d94d71d9ba2bc2a84ca17c09e0c2572ef4ee0eabace2388eb46b2c3324f02bc02288d20806df489d50dc3d7bcbd4abb4215d46afa9fd6d2cf985ce6809fc61e5dac7703c96f66d5adcd2f2a3b62832b35edf7dfa2ff3d83bd7dd85e97f590e7303";
    jclass native_class = env->GetObjectClass(contextObject);
    jmethodID pm_id = env->GetMethodID(native_class, "getPackageManager",
                                       "()Landroid/content/pm/PackageManager;");
    jobject pm_obj = env->CallObjectMethod(contextObject, pm_id);
    jclass pm_clazz = env->GetObjectClass(pm_obj);
// 得到 getPackageInfo 方法的 ID
    jmethodID package_info_id = env->GetMethodID(pm_clazz, "getPackageInfo",
                                                 "(Ljava/lang/String;I)Landroid/content/pm/PackageInfo;");
    jclass native_classs = env->GetObjectClass(contextObject);
    jmethodID mId = env->GetMethodID(native_classs, "getPackageName", "()Ljava/lang/String;");
    jstring pkg_str = static_cast<jstring>(env->CallObjectMethod(contextObject, mId));
// 获得应用包的信息
    jobject pi_obj = env->CallObjectMethod(pm_obj, package_info_id, pkg_str, 64);
// 获得 PackageInfo 类
    jclass pi_clazz = env->GetObjectClass(pi_obj);
// 获得签名数组属性的 ID
    jfieldID signatures_fieldId = env->GetFieldID(pi_clazz, "signatures",
                                                  "[Landroid/content/pm/Signature;");
    jobject signatures_obj = env->GetObjectField(pi_obj, signatures_fieldId);
    jobjectArray signaturesArray = (jobjectArray) signatures_obj;
    jsize size = env->GetArrayLength(signaturesArray);
    jobject signature_obj = env->GetObjectArrayElement(signaturesArray, 0);
    jclass signature_clazz = env->GetObjectClass(signature_obj);
    jmethodID string_id = env->GetMethodID(signature_clazz, "toCharsString",
                                           "()Ljava/lang/String;");
    jstring str = static_cast<jstring>(env->CallObjectMethod(signature_obj, string_id));
    char *c_msg = (char *) env->GetStringUTFChars(str, 0);
    LOGI("%s",c_msg);
    if (RELEASE_KSY.compare(c_msg) == 0)//签名一致  返回合法的 api key，否则返回错误
    {
        return true;
    } else {
        return false;
    }
}
