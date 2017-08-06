#include "delay.h"

void delay_ms2(int32_t nms)
{
	int32_t temp;
	SysTick->LOAD = 8000*nms;
	SysTick->CTRL = 0x00;		//��ռ�����
	SysTick->CTRL = 0x01;		//ʹ�ܣ�����0���޶����������ⲿʱ��Դ
	do
	{
		temp = SysTick->CTRL;	//��ȡ��ǰ������ֵ
	}while((temp&0x01)&&(!(temp&(1<<16))));//�ȴ�ʱ�䵽��
	SysTick->CTRL = 0x00;		//�رռ�����
	SysTick->VAL = 0x00;		//��ռ�����
}

void delay_us2(int32_t nus)
{
	int32_t temp;
	SysTick->LOAD = 5*nus;
	SysTick->CTRL = 0x00;		//��ռ�����
	SysTick->CTRL = 0x01;		//ʹ�ܣ�����0���޶����������ⲿʱ��Դ
	do
	{
		temp = SysTick->CTRL;	//��ȡ��ǰ������ֵ
	}while((temp&0x01)&&(!(temp&(1<<16))));//�ȴ�ʱ�䵽��
	SysTick->CTRL = 0x00;		//�رռ�����
	SysTick->VAL = 0x00;		//��ռ�����
}

void delay_10us2(void)
{
	int32_t temp;
	SysTick->LOAD = 2500;
	SysTick->CTRL = 0x00;		//��ռ�����
	SysTick->CTRL = 0x01;		//ʹ�ܣ�����0���޶����������ⲿʱ��Դ
	do
	{
		temp = SysTick->CTRL;	//��ȡ��ǰ������ֵ
	}while((temp&0x01)&&(!(temp&(1<<16))));//�ȴ�ʱ�䵽��
	SysTick->CTRL = 0x00;		//�رռ�����
	SysTick->VAL = 0x00;		//��ռ�����
}
