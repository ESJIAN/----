#include "App_Ultrasonic.h"
#include "Dri_Ultrasonic.h"
// 注意：OLED驱动也需要相应修改为8051兼容版本
// #include "Dri_OLED.h"  
#include <stdio.h>

/**
 * @brief 超声波测距应用初始化
 */
void App_Ultrasonic_Init(void)
{
    Ultrasonic_Init();
    
    // 如果使用OLED显示，需要确保OLED驱动已适配8051
    // OLED_ShowString(0, 0, "Ultrasonic Test");
    // OLED_ShowString(0, 2, "Distance:");
    // OLED_ShowString(64, 2, "cm");
    // OLED_Refresh_Gram();
}

/**
 * @brief 超声波测距处理函数
 */
void App_Ultrasonic_Process(void)
{
    unsigned int distance = 0;
    unsigned int i;
    char str[10];
    
    // 获取距离值
    distance = Ultrasonic_GetDistance();
    
    // 显示距离值 (如果使用OLED，需要确保OLED驱动已适配8051)
    // sprintf(str, "%d", (int)distance);
    // OLED_ShowString(48, 2, "   ");  // 清除之前显示
    // OLED_ShowString(48, 2, str);
    // OLED_Refresh_Gram();
    
    // 延时一段时间再进行下一次测量
    // 简单延时循环
    for(i = 0; i < 50000; i++);
}