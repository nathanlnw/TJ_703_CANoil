d/*
     Device_CAN.h
*/
#ifndef  _RT_Dev_CAN
#define _RT_Dev_CAN

#include <rthw.h>
#include <rtthread.h>
#include "stm32f4xx.h"
#include "usart.h"
#include "board.h"
#include <serial.h>




#define CANTESTInit 1
#define CANTESTTX 1
#define CANTESTRX 0

#define CANBufSize   100

typedef enum {FAILED = 0, PASSED = !FAILED} TestStatus;


typedef struct _OIL
{  
  u32  Oil_current;  // 0.1L/H
  u32  Oil_per_second_dot1ml;  //  ml/s   ����ÿ��  0.1 ml
  u32  Oil_deltaPacket_stuff_dot1ml;    // ÿ�η���ʱ��   
  u32  Day_Oil_consumpate_dot1mL;    //ÿ���ͺ�0.1ml
  u32  Day_Oil_use;  // �������ĵ����� 0.1L
  u32  Day_Oil_use_bak;// �����ͺ�bak
  u32  Total_Oil_use;  // 0.1 L  �ܹ�����  
  u32  Check_save_counter; // ��ʱ��� �Ƿ��������仯counter
  u8   Deltasaveflag; //   ��� ��ʼִ�д洢�仯����

}OIL;

extern OIL  Oil_Cau; 


extern TestStatus TestRx;
extern u8	CAN_initOver; 
extern CanRxMsg RxMessageData;

extern u32   CANBuffer_wr;//--------- Debug ----------
extern u32   Can_RXnum;
extern u32   Can_sdnum;  
extern u32   Can_same;
extern u32   Can_loudiao;
extern u32   Can_notsame;     

extern u8	 CAN_speed_used_Flag;   //  ��ʾʹ��CAN	�ٶ� ��־λ   
extern u16   Spd_CAN;  // ��CAN ȡ���ٶ�  
extern u32   Oil_USE;
extern u32   Distance_CAN; //  ��CAN ��ȡ�����




extern void  CAN_timer_ISR_OneSecond(void);
extern void  Can_timer_check(void); 
extern void  CANGPIO_Configuration(void);
extern void  CAN_App_Init(void); 
extern TestStatus CAN_TX(void);
extern TestStatus CAN_RX(void);
extern u8 CANTXData(u8 *Instr,u8 len);//len=0~8
extern u8 CANTXStr(u8 *Instr,u32 len); 
//extern u8 CANRXStr(void);
extern u8  CAN1_Rx_Process(void);
extern void  can_oil_write(u32 TotalOil,u32 DayOil); 
extern void can_oil_day_change(void);  







#endif

