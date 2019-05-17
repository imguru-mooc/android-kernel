LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)
LOCAL_SHARED_LIBRARIES = liblog libutils libhidlbase android.hardware.samples@1.0
LOCAL_SRC_FILES := client.cpp 
LOCAL_MODULE := my_client
include $(BUILD_EXECUTABLE)
