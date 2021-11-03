#include <jni.h>
#include <string.h>

static const char * classname = "com/example/testforjni/MainActivity";

JNIEXPORT jint JNICALL jni_Add(JNIEnv* env,jobject thiz, jint a, jint b){
	return a + b;
}


JNIEXPORT void JNICALL jni_StringAdd(JNIEnv* env,jobject thiz, jstring str1, jstring str2){
    const char *nativeStr1 = (*env)->GetStringUTFChars(env, str1, 0);
    const char *nativeStr2 = (*env)->GetStringUTFChars(env, str2, 0);

    int len1 = strlen(nativeStr1);
    int len2 = strlen(nativeStr2);

    char* res = NULL;
    if(len1 + len2 > 0){
        res = (char*)malloc(len1 + len2);
    }
    if(res != NULL){
        strcpy(res, nativeStr1);
        strcat(res, nativeStr2);
    }
    jstring javaStr = (*env)->NewStringUTF(env, res);

    jclass testClass = (*env)->FindClass(env,classname);
    jmethodID mid = (*env)->GetMethodID(env, testClass, "callByNative", "(Ljava/lang/String;)V");
    (*env)->CallVoidMethod(env, thiz, mid, javaStr);

    (*env)->DeleteLocalRef(env, javaStr);
    (*env)->ReleaseStringUTFChars(env, str1, nativeStr1);
    (*env)->ReleaseStringUTFChars(env, str2, nativeStr2);
}

static JNINativeMethod methods[] = {
    {"Add",            "(II)I",        (void *)jni_Add},
    {"StringAdd",            "(Ljava/lang/String;Ljava/lang/String;)V",        (void *)jni_StringAdd},
};

jint JNI_OnLoad(JavaVM* vm, void* reserved){
	JNIEnv *env;
	if ((*vm)->GetEnv(vm,(void**) &env, JNI_VERSION_1_4) != JNI_OK)
    {
        return -1;
    }
    jclass testClass = (*env)->FindClass(env,classname);
    if ((*env)->RegisterNatives(env, testClass, methods, sizeof(methods) / sizeof(methods[0])) < 0) {
    	return -1;
    }
	return JNI_VERSION_1_4;
}

void JNI_OnUnload(JavaVM *vm, void *reserved){
}