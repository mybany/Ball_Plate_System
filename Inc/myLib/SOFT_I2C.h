#ifndef _SOFT_I2C_H
#define _SOFT_I2C_H
#include "stm32f7xx_hal.h"

#define  u8 uint8_t
#define  u32 uint32_t
#define  u16 uint16_t

//IO��������
#define SDA_IN()	{GPIOB->MODER&=~(3<<(7*2));GPIOB->MODER|=0<<7*2;}//PB7����ģʽ
#define SDA_OUT()	{GPIOB->MODER&=~(3<<(7*2));GPIOB->MODER|=1<<7*2;}//PB7���ģʽ

//IO��������
#define IIC_SCL(n)  (n?HAL_GPIO_WritePin(GPIOB,GPIO_PIN_6,GPIO_PIN_SET):HAL_GPIO_WritePin(GPIOB,GPIO_PIN_6,GPIO_PIN_RESET)) //SCL
#define IIC_SDA(n)  (n?HAL_GPIO_WritePin(GPIOB,GPIO_PIN_7,GPIO_PIN_SET):HAL_GPIO_WritePin(GPIOB,GPIO_PIN_7,GPIO_PIN_RESET)) //SDA
#define READ_SDA    HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_7)  //����SDA



//IIC���в�������
void IIC_Init(void);                //��ʼ��IIC��IO��				 
void IIC_Start(void);				//����IIC��ʼ�ź�
void IIC_Stop(void);	  			//����IICֹͣ�ź�
void IIC_Send_Byte(u8 txd);			//IIC����һ���ֽ�
u8 IIC_Read_Byte(unsigned char ack);//IIC��ȡһ���ֽ�
u8 IIC_Wait_Ack(void); 				//IIC�ȴ�ACK�ź�
void IIC_Ack(void);					//IIC����ACK�ź�
void IIC_NAck(void);				//IIC������ACK�ź�

void IIC_Write_One_Byte(u8 daddr,u8 addr,u8 data);
u8 IIC_Read_One_Byte(u8 daddr,u8 addr);


#endif
