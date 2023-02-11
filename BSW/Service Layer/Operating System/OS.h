/********************************************************************************/
/* Module Name  : OS.h							        */
/* Author       : Hossam						        */
/* Purpose      : Header File for Operating System			        */
/********************************************************************************/

#ifndef __OS_H__
#define __OS_H__

/*******************************************************************************
 *                              File Includes                                  *
 *******************************************************************************/

#include <stdio.h>
#include "../../../Libraries/Std_Types.h"
#include "../../../RTE/RTE.h"
#include "../../ECUAL/IO Module/Button Module/Button.h"
#include "../../ECUAL/IO Module/LED Module/Led.h"
#include "../../ECUAL/CAN Interface Module/can_int.h"
#include "../../ECUAL/Timer Module/Timer.h"
#include "../../MCAL/Port Driver/Port.h"
#include "OS_Cfg.h"

/*******************************************************************************
 *                            Function Prototypes                              *
 *******************************************************************************/
   
extern void Scheduler_Start       (void);

extern void Master_Scheduler      (void);

extern void Slave_Scheduler       (void);

extern void CallBack_LED_Mode     (void(*Led_Mode)(uint8), uint8);

extern void CallBack_Send_Command (void(*Send_Command)(uint8), uint8);

#endif /* __OS_H__ */
