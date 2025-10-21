#ifndef __DRI_ULTRASONIC_H
#define __DRI_ULTRASONIC_H
#include <STC89C5xRC.H>

// ���������������Ŷ���
#define TRIG P10  // Trig�������ӵ�P1.0
#define ECHO P11  // Echo�������ӵ�P1.1

// ��������
void Ultrasonic_Init(void);
void Ultrasonic_Trigger(void);
unsigned int Ultrasonic_GetDistance(void);

#endif