#include "Time_Delay.h"

/**
 * ΢�뼶��ʱ����
 * @param us ��ʱ΢����
 */
void Delay_us(unsigned int us)
{
    while(us--)
    {
        // ��Լ1us����ʱ������STC89C5xRC��11.0592MHz�����µĲ���
        _nop_();
        _nop_();
        _nop_();
        _nop_();
        _nop_();
        _nop_();
        _nop_();
        _nop_();
        _nop_();
        _nop_();
        _nop_();
        _nop_();
    }
}

/**
 * ���뼶��ʱ����
 * @param ms ��ʱ������
 */
void Delay_ms(unsigned int ms)
{
    unsigned int i;
    while(ms--)
    {
        for(i = 0; i < 120; i++)  // ��������ֵ��У׼��ʱ
        {
            Delay_us(8);          // ͨ��΢����ʱʵ�ֺ�����ʱ
        }
    }
}