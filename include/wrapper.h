#ifndef DEMO_WRAPPER_H
#define DEMO_WRAPPER_H

#ifdef __cplusplus
extern "C" {
#endif

void wrapper_SetBrightness(int brightness);

void wrapper_SetConfigValue(const char* path, int value);

void wrapper_SetConfigIP(int value1, int value2);

void wrapper_SetKmPort(const char* port);

void wrapper_KmnetManage(bool state);

void wrapper_KeyManage(bool state);

void wrapper_hidupdata();

#ifdef __cplusplus
}
#endif

#endif //DEMO_WRAPPER_H
