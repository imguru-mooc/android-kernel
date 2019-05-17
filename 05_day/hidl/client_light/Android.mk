LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)
LOCAL_SHARED_LIBRARIES = liblog libutils libhidlbase android.hardware.light@2.0
LOCAL_SRC_FILES := light_client.cpp 
LOCAL_MODULE := light_client
include $(BUILD_EXECUTABLE)
