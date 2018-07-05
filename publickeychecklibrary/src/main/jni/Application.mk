APP_MODULES = libPublicKCheck
//APP_ABI    := armeabi armeabi-v7a arm64-v8a x86 x86_64
APP_ABI    := armeabi-v7a arm64-v8a x86 x86_64
//APP_STL    := stlport_shared
APP_STL    := stlport_static
//APP_STL    := gnustl_static

ifeq ($(NDK_DEBUG), 1)
    APP_OPTIM = debug
    APP_CFLAGS = -g -O0
else
    APP_OPTIM = release
    APP_CFLAGS = -O3
endif

APP_CPPFLAGS := -frtti -DCC_ENABLE_CHIPMUNK_INTEGRATION=1  -std=c++0x

APP_CPPFLAGS += -fexceptions