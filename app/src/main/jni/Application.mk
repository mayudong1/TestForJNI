APP_OPTIM := release
APP_PLATFORM := android-14
APP_ABI := armeabi-v7a, arm64-v8a
NDK_TOOLCHAIN_VERSION=4.9
APP_PIE := false
APP_ALLOW_MISSING_DEPS := true

APP_STL := gnustl_static

APP_CFLAGS := -O3 -Wall \
    -DANDROID -DNDEBUG

