LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)
LOCAL_SRC_FILES:= my_read_app.c
LOCAL_MODULE := my_read_app
include $(BUILD_EXECUTABLE)

