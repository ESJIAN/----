#include "Dri_Ultrasonic.h"
#include <intrins.h>  // ������������ͷ�ļ�������_nop_()����

/**
 * @brief ��������������ʼ��
 */
void Ultrasonic_Init(void)
{
    // ��ʼ��TRIG����Ϊ�͵�ƽ
    TRIG = 0;   // ��ʼ��Trig����Ϊ�͵�ƽ
    // ECHO���Ų���Ҫ��ʼ�������ָ�������״̬
}

/**
 * @brief ���ͳ����������ź�
 */
void Ultrasonic_Trigger(void)
{
    // ��������10us�ĸߵ�ƽ����
    TRIG = 1;
    _nop_(); _nop_(); _nop_(); _nop_(); _nop_();
    _nop_(); _nop_(); _nop_(); _nop_(); _nop_();
    _nop_(); _nop_(); _nop_(); _nop_(); _nop_();
    TRIG = 0;
}

/**
 * @brief ��ȡ����ֵ (��λ: cm)
 * @retval ����ֵ(cm)
 */
unsigned int Ultrasonic_GetDistance(void)
{
    unsigned int duration = 0;
    unsigned int distance = 0;
    
    // ���ʹ����ź�
    Ultrasonic_Trigger();
    
    // �ȴ�ECHO���ű�ߵ�ƽ
    while(!ECHO);
    
    // ����ߵ�ƽ����ʱ��
    while(ECHO)
    {
        duration++;
        // ��ֹ���޵ȴ�
        if(duration > 50000) 
            break;
    }
    
    // ������㹫ʽ: ���� = (�ߵ�ƽʱ�� * ����(340m/s)) / 2
    // �򻯺�: ���� = �ߵ�ƽʱ�� / 58 (Լ����)
    distance = duration / 58;
    
    return duration;
}