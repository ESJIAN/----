#include "Dri_Ultrasonic.h"

/**
 * @brief  瓒呭０娉紶鎰熷櫒鍒濆鍖�
 */
void Ultrasonic_Init(void)
{
    // 鍒濆鍖栧紩鑴氱姸鎬�
    TRIG = 0;  // 鍒濆Trig寮曡剼涓轰綆鐢靛钩
    // ECHO涓鸿緭鍏ュ紩鑴氾紝鏃犻渶鍒濆鍖�
}

/**
 * @brief  鍙戦€佽秴澹版尝瑙﹀彂淇″彿
 */
void Ultrasonic_Trigger(void)
{
    // 鍙戦€佽嚦灏�10us鐨勯珮鐢靛钩鑴夊啿
    TRIG = 1;
    _nop_(); _nop_(); _nop_(); _nop_(); _nop_();
    _nop_(); _nop_(); _nop_(); _nop_(); _nop_();
    _nop_(); _nop_(); _nop_(); _nop_(); _nop_();
    TRIG = 0;
}

/**
 * @brief  鑾峰彇璺濈鍊� (鍗曚綅: cm)
 * @retval 璺濈鍊�(cm)
 */
unsigned int Ultrasonic_GetDistance(void)
{
    unsigned int duration = 0;
    unsigned int distance = 0;
    
    // 鍙戦€佽Е鍙戜俊鍙�
    Ultrasonic_Trigger();
    
    // 绛夊緟Echo寮曡剼鍙橀珮鐢靛钩
    while(!ECHO);
    
    // 璁＄畻楂樼數骞虫寔缁椂闂�
    while(ECHO)
    {
        duration++;
        // 闃叉鏃犻檺绛夊緟
        if(duration > 50000) 
            break;
    }
    
    // 璺濈璁＄畻鍏紡: 璺濈 = (楂樼數骞虫椂闂� * 澹伴€�(340m/s)) / 2
    // 绠€鍖栧悗: 璺濈 = 楂樼數骞虫椂闂� / 58 (绾︾瓑浜�)
    distance = duration / 58;
    
    return distance;
}