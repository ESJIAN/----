#ifndef __DRI_ULTRASONIC_H
#define __DRI_ULTRASONIC_H
#include <STC89C5xRC.H>

// 超声波传感器引脚定义
#define TRIG P10  // Trig引脚连接到P1.0
#define ECHO P11  // Echo引脚连接到P1.1

// 函数声明
void Ultrasonic_Init(void);
void Ultrasonic_Trigger(void);
unsigned int Ultrasonic_GetDistance(void);

#endif