#include "Int_OLED.h"
#include "App_Ultrasonic.h"
#include "Time_Delay.h"
#include "Uart.h"

unsigned int distance = 0;

void SystemInit()
{
    Int_OLED_Init();
    Int_OLED_Clear();
    App_Ultrasonic_Init();
    Uart_Init();  // ��ʼ������
}

void main()
{
    SystemInit();
    
    while (1) 
    {

        distance = Ultrasonic_GetDistance();
        if (distance >= 400) 
        {
            // �ֲ�����
            Int_OLED_ShowStr(0, 0, "                  ");
            Int_OLED_ShowStr(13, 0, " ");
            
            Int_OLED_ShowStr(0, 1, "Out of range");
        }
        else
        {
            // �ֲ�����
            Int_OLED_ShowStr(0, 1, "                  ");

            Int_OLED_ShowStr(0, 0, "Distance");
            Int_OLED_ShowNum(9, 0, distance);
            Int_OLED_ShowStr(13, 0, "cm");
        }
        
        
        // ͨ�����ڷ��;���ֵ

        //Uart_SendHex((distance >> 8) & 0xFF);
        //Uart_SendHex(distance & 0xFF);
        
    }
}