#include "Uart.h"

/**
 * 串口初始化函数
 */
void Uart_Init()
{
    SCON = 0x50;   // 设置为模式1，8位数据，允许接收
    TMOD |= 0x20;  // 设置定时器1为模式2，8位自动重装
    TH1 = 0xFD;    // 波特率设置为9600 (晶振11.0592MHz)
    TL1 = 0xFD;
    TR1 = 1;       // 启动定时器1
    ES = 1;        // 允许串口中断
    EA = 1;        // 开启总中断
}

/**
 * 串口发送一个字节
 * @param dat 要发送的数据
 */
void Uart_SendByte(unsigned char dat)
{
    SBUF = dat;
    while(!TI);    // 等待发送完成
    TI = 0;        // 清除发送标志位
}

/**
 * 串口发送字符串
 * @param str 要发送的字符串
 */
void Uart_SendString(char *str)
{
    while(*str)
    {
        Uart_SendByte(*str++);
    }
}

/**
 * 串口发送十六进制数据
 * @param hex 要发送的十六进制数据
 */
void Uart_SendHex(unsigned char hex)
{
    unsigned char temp;
    
    // 发送高4位
    temp = (hex >> 4) & 0x0F;
    if(temp < 10)
        Uart_SendByte(temp + '0');
    else
        Uart_SendByte(temp - 10 + 'A');
    
    // 发送低4位
    temp = hex & 0x0F;
    if(temp < 10)
        Uart_SendByte(temp + '0');
    else
        Uart_SendByte(temp - 10 + 'A');
}