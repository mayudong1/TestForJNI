#include <jni.h>

static const char * classname = "com/example/testforjni/MainActivity";

JNIEXPORT jint JNICALL jni_Add(JNIEnv* env,jobject thiz, jint a, jint b){
	return a + b;
}

static JNINativeMethod methods[] = {
    {"Add",            "(II)I",        (void *)jni_Add},
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