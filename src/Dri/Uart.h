#ifndef __UART_H
#define __UART_H

#include <STC89C5xRC.H>

// ���ڳ�ʼ������
void Uart_Init();

// ���ڷ���һ���ֽ�
void Uart_SendByte(unsigned char dat);

// ���ڷ����ַ���
void Uart_SendString(char *str);

// ���ڷ���ʮ����������
void Uart_SendHex(unsigned char hex);

#endif