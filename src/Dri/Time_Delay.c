#include "Time_Delay.h"

/**
 * 微秒级延时函数
 * @param us 延时微秒数
 */
void Delay_us(unsigned int us)
{
    while(us--)
    {
        // 大约1us的延时，根据STC89C5xRC在11.0592MHz晶振下的测试
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
 * 毫秒级延时函数
 * @param ms 延时毫秒数
 */
void Delay_ms(unsigned int ms)
{
    unsigned int i;
    while(ms--)
    {
        for(i = 0; i < 120; i++)  // 调整此数值可校准延时
        {
            Delay_us(8);          // 通过微秒延时实现毫秒延时
        }
    }
}