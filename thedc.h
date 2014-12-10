/*
* thedc.h
*
*  Created on: 2014��11��7��
*      Author: niehao
*/

#ifndef THEDC_H_
#define THEDC_H_
#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/debug.h"
#include "driverlib/fpu.h"
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"
#include "driverlib/pin_map.h"
#include "driverlib/rom.h"
#include "driverlib/sysctl.h"
#include "driverlib/timer.h"
#include "driverlib/uart.h"
#include "C:/ti/TivaWare_C_Series-2.0.1.11577/driverlib/uartstdio.h"

/*struct Player
{
	//С���ı��(1����4֮���ĳһ��)
	unsigned char player_loc;
	//С��1ͷβ���꼰����(���Ƕ��֣���ͷβ������һ��)
	unsigned char player1_head_x;
	unsigned char player1_head_y;
	unsigned char player1_rear_x;
	unsigned char player1_rear_y;
	unsigned char player1_score;
	//С��2ͷβ���꼰����(���Ƕ��֣���ͷβ������һ��)
	unsigned char player2_head_x;
	unsigned char player2_head_y;
	unsigned char player2_rear_x;
	unsigned char player2_rear_y;
	unsigned char player2_score;
	//С��3�������ڣ�����0��ͷβ���꼰����,(���Ƕ��֣���ͷβ������һ��)
	unsigned char player3_head_x;
	unsigned char player3_head_y;
	unsigned char player3_rear_x;
	unsigned char player3_rear_y;
	unsigned char player3_score;
	//С��4�������ڣ�����0��ͷβ���꼰����,(���Ƕ��֣���ͷβ������һ��)
	unsigned char player4_head_x;
	unsigned char player4_head_y;
	unsigned char player4_rear_x;
	unsigned char player4_rear_y;
	unsigned char player4_score;
	//�ӵ�ռ�����
	unsigned char available;
	//����ʣ��ʱ��
	unsigned char time;
	//���������źţ�1��ʾ��ʼ��0����
	unsigned char is_over;
	//��βУ��λ
	unsigned char end0;//0x0D;
	unsigned char end1;//0x0A;
};
struct Player info;
*/



extern char flag;
extern int t;
extern struct Player info;
extern struct Queue queue;
extern unsigned char Position[26];
extern int head_local[2],tail_local[2],center_local[2];
extern char S_flag;//������״̬
extern char senser_flag;//�ж����Ǹ�������
//move
#define ahead 0x4
#define back 0x8
#define stop 0xc
void move_stright(int);
void left_move();
void right_move();
void turn_left();
void turn_right();
void turn_left_back();
void turn_right_back();
int head(unsigned char,unsigned char);
void move_to(unsigned char,unsigned char);
void move_to_exact(unsigned char x,unsigned char y);
//ͨ�ź���
void UARTSend(const uint8_t *, uint32_t );
void UARTConfig();
void UARTIntHandler(void);

//������
void Timer0IntHandler(void);
void TimerConfig();
void Timer1IntHandler(void);
void GPIOA6INT(void);

//�߼�
void target1(int judge);
void target2(int judge);
void target3(int judge);
void target4(int judge);
extern void (*target[4])(int judge);
extern int check[4];
#endif /* THEDC_H_ */
