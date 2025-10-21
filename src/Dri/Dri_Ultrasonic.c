#include "Dri_Ultrasonic.h"
#include <intrins.h>  // 包含内联函数头文件，用于_nop_()函数

/**
 * @brief 超声波传感器初始化
 */
void Ultrasonic_Init(void)
{
    // 初始化TRIG引脚为低电平
    TRIG = 0;   // 初始化Trig引脚为低电平
    // ECHO引脚不需要初始化，保持浮空输入状态
}

/**
 * @brief 发送超声波触发信号
 */
void Ultrasonic_Trigger(void)
{
    // 发送至少10us的高电平脉冲
    TRIG = 1;
    _nop_(); _nop_(); _nop_(); _nop_(); _nop_();
    _nop_(); _nop_(); _nop_(); _nop_(); _nop_();
    _nop_(); _nop_(); _nop_(); _nop_(); _nop_();
    TRIG = 0;
}

/**
 * @brief 获取距离值 (单位: cm)
 * @retval 距离值(cm)
 */
unsigned int Ultrasonic_GetDistance(void)
{
    unsigned int duration = 0;
    unsigned int distance = 0;
    
    // 发送触发信号
    Ultrasonic_Trigger();
    
    // 等待ECHO引脚变高电平
    while(!ECHO);
    
    // 计算高电平持续时间
    while(ECHO)
    {
        duration++;
        // 防止无限等待
        if(duration > 50000) 
            break;
    }
    
    // 距离计算公式: 距离 = (高电平时间 * 声速(340m/s)) / 2
    // 简化后: 距离 = 高电平时间 / 58 (约等于)
    distance = duration / 58;
    
    return duration;
}