/********************************************************************************/
/* Module Name  : Can_Cfg.h							*/
/* Author       : Hossam						        */
/* Purpose      : Configuration File for CAN Driver				*/
/********************************************************************************/

#ifndef __CAN_CFG_H__
#define __CAN_CFG_H__

/*******************************************************************************
 *                           GPIO Pin Configurations                           *
 *******************************************************************************/

#define GPIO_PB4_CAN0RX                 (0x00011008)
#define GPIO_PB5_CAN0TX                 (0x00011408)

/*******************************************************************************
 *                           CAN Object Configurations                         *
 *******************************************************************************/

#define CAN0_TX_ID                      (2)
#define TX_OBJECT                       (2)

#define CAN0_RX_ID                      (1)
#define RX_OBJECT                       (1)

/*******************************************************************************
 *                            Bit Rate Configuration                           *
 *******************************************************************************/

#define Bit_Rate                        (500000)

/*******************************************************************************
 *                           Initialization Definitions                        *
 *******************************************************************************/

#define Data_Initialize                 (0)
#define Mask_Initialize                 (0)
#define bClrPendingInt                  (0)

#endif /* __CAN_CFG_H__ */