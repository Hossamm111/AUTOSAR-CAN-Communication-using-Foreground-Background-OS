/********************************************************************************/
/* Module Name  : APP.h							        */
/* Author       : Hossam						        */
/* Purpose      : Header File for Application Layer				*/
/********************************************************************************/

#ifndef __APP_H__
#define __APP_H__

/*******************************************************************************
 *                              File Includes                                  *
 *******************************************************************************/

#include "../../BSW/Service Layer/Operating System/OS.h"

/*******************************************************************************
 *                              Function Prototypes                            *
 *******************************************************************************/

extern void APP_INIT (void);

extern void APP_START (void);

extern void LED_Mode (uint8);

extern void Send_Command (uint8);

extern void Receive_Command (void);

#endif /* __APP_H__ */
