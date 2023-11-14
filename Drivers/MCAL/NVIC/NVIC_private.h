/*=================================================================================*/
/*  File        : NVIC_private.h                                                   */
/*  Description : This Private file includes NVIC Driver macros for stm32f401CC    */
/*  Author      : Tarek Ahmed Abd El Wahab. Embedded SW Engineer                   */
/*  Date        : 14/6/2023                                                        */
/*  Linkedin    : https://www.linkedin.com/in/tarek-el-shafei-647698205/           */
/*  Git account : https://github.com/Tarek1482000?tab=repositories                 */
/*  mail        : tarekahmed0128@gmil.com                                          */
/*=================================================================================*/

/* File Gaurd*/
#ifndef NVIC_PRIVATE_H_
#define NVIC_PRIVATE_H_


/*================================================================================================================*/
/**************************************       Private Macros & struct       ***************************************/
/*================================================================================================================*/

#define INVIC_BASE_ADDERSS      0xE000E100
#define NVIC_REG                ((volatile NVIC_Memory_t*)(INVIC_BASE_ADDERSS))

#define   VECTKEY               0x05FA0000
#define   SCB_AIRCR             *((volatile u32*)(0xE000ED0C))
typedef struct 
{
	/*
       0x180    -   0x11C   =   64 Byte  HEX
       64 Bytes / 4 = 25 REG DEC
       [25 - 1] (REG 0x180 not in our calculation) = 24 REG

	 */
	volatile u32 ISER[32];
	volatile u32 ICER[32];
	volatile u32 ISPR[32];
	volatile u32 ICPR[32];

	/*
    u32 ISER[8];
	u32 Reserved1[24];
	u32 ICER[8];
    u32 Reserved2[24];
	u32 ISPR[8];
    u32 Reserved3[24];
	u32 ICPR[8];
    u32 Reserved4[24];
	 */

	/*
    0x400   -   0x31c   = 0XE4 Byte HEX
    Dec = (0XE4 bytes /4 ) - 1 = 56 REG    
    [56 - 1] >>>>> (REG 0x400 not in our calculation)          
    IABR 8 + Reserved 56  = 64 / 2 =32 ,32
	 */
	volatile u32 IABR[64];

	/* 60*4 = 240 REGS(4bits)  + 4 SCB registers(4bits)  + 4 Reserved (4bits) */
	volatile u8 IPR[248];
}NVIC_Memory_t;



#endif /* NVIC_PRIVATE_H_ */
