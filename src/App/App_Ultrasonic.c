#include "App_Ultrasonic.h"
#include "Dri_Ultrasonic.h"
// ע�⣺OLED����Ҳ��Ҫ��Ӧ�޸�Ϊ8051���ݰ汾
// #include "Dri_OLED.h"  
#include <stdio.h>

/**
 * @brief ���������Ӧ�ó�ʼ��
 */
void App_Ultrasonic_Init(void)
{
    Ultrasonic_Init();
    
    // ���ʹ��OLED��ʾ����Ҫȷ��OLED����������8051
    // OLED_ShowString(0, 0, "Ultrasonic Test");
    // OLED_ShowString(0, 2, "Distance:");
    // OLED_ShowString(64, 2, "cm");
    // OLED_Refresh_Gram();
}

/**
 * @brief ��������ദ����
 */
void App_Ultrasonic_Process(void)
{
    unsigned int distance = 0;
    unsigned int i;
    char str[10];
    
    // ��ȡ����ֵ
    distance = Ultrasonic_GetDistance();
    
    // ��ʾ����ֵ (���ʹ��OLED����Ҫȷ��OLED����������8051)
    // sprintf(str, "%d", (int)distance);
    // OLED_ShowString(48, 2, "   ");  // ���֮ǰ��ʾ
    // OLED_ShowString(48, 2, str);
    // OLED_Refresh_Gram();
    
    // ��ʱһ��ʱ���ٽ�����һ�β���
    // ����ʱѭ��
    for(i = 0; i < 50000; i++);
}