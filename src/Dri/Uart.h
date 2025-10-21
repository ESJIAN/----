#ifndef __UART_H
#define __UART_H

#include <STC89C5xRC.H>

// 串口初始化函数
void Uart_Init();

// 串口发送一个字节
void Uart_SendByte(unsigned char dat);

// 串口发送字符串
void Uart_SendString(char *str);

// 串口发送十六进制数据
void Uart_SendHex(unsigned char hex);

#endif