LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)
LOCAL_SRC_FILES:= my_major_app.c
LOCAL_MODULE := my_major_app
include $(BUILD_EXECUTABLE)

