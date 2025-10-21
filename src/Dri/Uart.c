#include "Uart.h"

/**
 * ���ڳ�ʼ������
 */
void Uart_Init()
{
    SCON = 0x50;   // ����Ϊģʽ1��8λ���ݣ��������
    TMOD |= 0x20;  // ���ö�ʱ��1Ϊģʽ2��8λ�Զ���װ
    TH1 = 0xFD;    // ����������Ϊ9600 (����11.0592MHz)
    TL1 = 0xFD;
    TR1 = 1;       // ������ʱ��1
    ES = 1;        // �������ж�
    EA = 1;        // �������ж�
}

/**
 * ���ڷ���һ���ֽ�
 * @param dat Ҫ���͵�����
 */
void Uart_SendByte(unsigned char dat)
{
    SBUF = dat;
    while(!TI);    // �ȴ��������
    TI = 0;        // ������ͱ�־λ
}

/**
 * ���ڷ����ַ���
 * @param str Ҫ���͵��ַ���
 */
void Uart_SendString(char *str)
{
    while(*str)
    {
        Uart_SendByte(*str++);
    }
}

/**
 * ���ڷ���ʮ����������
 * @param hex Ҫ���͵�ʮ����������
 */
void Uart_SendHex(unsigned char hex)
{
    unsigned char temp;
    
    // ���͸�4λ
    temp = (hex >> 4) & 0x0F;
    if(temp < 10)
        Uart_SendByte(temp + '0');
    else
        Uart_SendByte(temp - 10 + 'A');
    
    // ���͵�4λ
    temp = hex & 0x0F;
    if(temp < 10)
        Uart_SendByte(temp + '0');
    else
        Uart_SendByte(temp - 10 + 'A');
}