#define LOG_TAG "LedService"

#include <stdio.h>
#include "LedService.h" 

namespace android {
	void LedService::ledOn(void)
	{
		printf("LedService::ledOn(void)\n");
	}
}

