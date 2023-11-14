/*=================================================================================*/
/*  File        : RCC_Private.h                                                    */
/*  Description : This Private file includes RCC Driver macros for stm32f401CC     */
/*  Author      : Tarek Ahmed Abd El Wahab. Embedded SW Engineer                   */
/*  Date        : 12/6/2023                                                        */
/*  Linkedin    : https://www.linkedin.com/in/tarek-el-shafei-647698205/           */
/*  Git account : https://github.com/Tarek1482000?tab=repositories                 */
/*  mail        : tarekahmed0128@gmil.com                                          */
/*=================================================================================*/

/* File Gaurd*/
#ifndef MCAL_RCC_RCC_PRIVATE_H_
#define MCAL_RCC_RCC_PRIVATE_H_
/*================================================================================================================*/
/*******************************************       Private Macros       *******************************************/
/*================================================================================================================*/

/*============     Standard Types    ============*/
#include "../../LIB/STD_TYPES.h"

/*============     RCC Base Address    ============*/
#define RCC_BASE_ADDRESS	0x40023800
/*============     [RCC] Registers Ptr ============*/
#define RCC_REG	        ((volatile RCC_Memory_t*)(RCC_BASE_ADDRESS))
/*============     [RCC] Registers     ============*/
typedef struct
{
    volatile u32 RCC_CR;
    volatile u32 RCC_PLLCFGR;
    volatile u32 RCC_CFGR;
    volatile u32 RCC_CIR;
    volatile u32 RCC_AHB1RSTR;
    volatile u32 RCC_AHB2RSTR;
    volatile u32 Reserved1;
    volatile u32 Reserved2;
    volatile u32 RCC_APB1RSTR;
    volatile u32 RCC_APB2RSTR;
    volatile u32 Reserved3;
    volatile u32 Reserved4;
    volatile u32 RCC_AHB1ENR;
    volatile u32 RCC_AHB2ENR;
    volatile u32 Reserved5;
    volatile u32 Reserved6;
    volatile u32 RCC_APB1ENR;
    volatile u32 RCC_APB2ENR;
    volatile u32 Reserved7;
    volatile u32 Reserved8;
    volatile u32 RCC_AHB1LPENR;
    volatile u32 RCC_AHB2LPENR;
    volatile u32 Reserved9;
    volatile u32 Reserved10;
    volatile u32 RCC_APB1LPENR;
    volatile u32 RCC_APB2LPENR;
    volatile u32 Reserved11;
    volatile u32 Reserved12;
    volatile u32 RCC_BDCR;
    volatile u32 RCC_CSR;
    volatile u32 Reserved13;
    volatile u32 Reserved14;
    volatile u32 RCC_SSCGR;
    volatile u32 RCC_PLLI2SCFGR;
    volatile u32 RCC_DCKCFGR;
    }RCC_Memory_t;



/*============     [RCC_CR] Register     ============*/                           
    #define HSION              0                           
    #define HSIRDY             1                           
    #define Res                2                           
    #define HSITRIM0           3                           
    #define HSITRIM1           4                           
    #define HSITRIM2           5                           
    #define HSITRIM3           6                           
    #define HSITRIM4           7                           
    #define HSICAL0            8                           
    #define HSICAL1            9                           
    #define HSICAL2            10                           
    #define HSICAL3            11                           
    #define HSICAL4            12                           
    #define HSICAL5            13                           
    #define HSICAL6            14                           
    #define HSICAL7            15                           
    #define HSEON              16                           
    #define HSERDY             17                           
    #define HSEBYP             18                           
    #define CSSON              19    
    #define PLLON              24                           
    #define PLLRDY             25                           
    #define PLLI2SON           26                           
    #define PLLI2SRDY          27
/*====================================================*/ 



/*============  [RCC_PLLCFGR] Register    ============*/                           
    #define PLLM0               0                           
    #define PLLM1               1                           
    #define PLLM2               2                            
    #define PLLM3               3                           
    #define PLLM4               4                           
    #define PLLM5               5                           
    #define PLLN0               6                           
    #define PLLN1               7                           
    #define PLLN2               8                           
    #define PLLN3               9                           
    #define PLLN4               10                           
    #define PLLN5               11                           
    #define PLLN6               12                           
    #define PLLN7               13                           
    #define PLLN8               14                           
    #define PLLP0               16                           
    #define PLLP1               17                           
    #define PLLSRC              22                           
    #define PLLQ0               24                           
    #define PLLQ1               25  
    #define PLLQ2               26                         
    #define PLLQ3               27      
/*====================================================*/ 




/*=============  [RCC_CFGR] Register    ==============*/                           
    #define SW0                   0                           
    #define SW1                   1                           
    #define SWS0                  2                            
    #define SWS1                  3                           
    #define HPRE0                 4                           
    #define HPRE1                 5                           
    #define HPRE2                 6                           
    #define HPRE3                 7                           
    #define PPRE1_0               10                          
    #define PPRE1_1               11                        
    #define PPRE1_2               12                          
    #define PPRE2_0               13                          
    #define PPRE2_1               14                         
    #define PPRE2_2               15                          
    #define RTCPRE0               16                          
    #define RTCPRE1               17                         
    #define RTCPRE2               18                         
    #define RTCPRE3               19                        
    #define RTCPRE4               20                         
    #define MCO1_0                21
    #define MCO1_1                22                       
    #define I2SSCR                23
    #define MCO1PRE0              24                           
    #define MCO1PRE1              25                         
    #define MCO1PRE2              26                         
    #define MCO2PRE0              27                           
    #define MCO2PRE1              28                           
    #define MCO2PRE2              29  
    #define MCO2_0                30                       
    #define MCO2_1                31  
/*====================================================*/ 



/*============    [RCC_AHB1ENR] Register  =============*/                           
    #define GPIOAEN             0                           
    #define GPIOBEN             1                           
    #define GPIOCEN             2                           
    #define GPIODEN             3                           
    #define GPIOEEN             4                           
    #define GPIOHEN             7                           
    #define CRCEN               12                           
    #define DMA1EN              21                           
    #define DMA2EN              22                                                                      
/*====================================================*/ 



/*============    [RCC_AHB2ENR] Register  =============*/                           
    #define OTGFSEN             7                                                                                             
/*====================================================*/ 





/*============    [RCC_APB1ENR] Register  =============*/                           
    #define TIM2EN                0                           
    #define TIM3EN                1                           
    #define TIM4EN                2                           
    #define TIM5EN                3                           
    #define WWDGEN                11                           
    #define SPI2EN                14                           
    #define SPI3EN                15                           
    #define USART2EN              17                           
    #define I2C1EN                21
    #define I2C2EN                22
    #define I2C3EN                23
    #define PWREN                 28                                                                     
/*====================================================*/ 



/*============    [RCC_APB2ENR] Register  =============*/                           
    #define TIM1EN                0                           
    #define USART1EN              4                           
    #define USART6EN              5                           
    #define ADC1EN                8                           
    #define SDIOEN                11                           
    #define SPI1EN                12                           
    #define SPI4EN                13                           
    #define SYSCFG                14                           
    #define TIM9EN                16
    #define TIM10EN               17
    #define TIM11EN               18                                                                                         
/*====================================================*/ 











#endif /* MCAL_RCC_RCC_PRIVATE_H_ */
