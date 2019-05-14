LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)
LOCAL_SRC_FILES:= myapp.c
LOCAL_MODULE := myapp
include $(BUILD_EXECUTABLE)

