/********************************************************************************/
/* Module Name  : APP.c							        */
/* Author       : Hossam						        */
/* Purpose      : Initialize & Start the Application				*/
/********************************************************************************/

#include "APP.h"

/********************************************************************************/
/* Function Name: void APP_INIT (void)			                        */
/* Inputs       : None		                                                */
/* Outputs      : None				 	                        */
/* Reentrancy   : Non-Reentrant				 			*/
/* Synchronous  : Synchronous							*/
/* Description  : Initialize the Application	                                */
/********************************************************************************/

void APP_INIT (void)
{
  Port_Init(&Port_Configuration);
  
  Timer_Init();
  
  CAN_Interface_Init();
}

/********************************************************************************/
/* Function Name: void APP_START (void)			                        */
/* Inputs       : None		                                                */
/* Outputs      : None				 	                        */
/* Reentrancy   : Non-Reentrant				 			*/
/* Synchronous  : Synchronous							*/
/* Description  : Start the Application	                                        */
/********************************************************************************/

void APP_START (void)
{
  APP_INIT();
  
  Scheduler_Start();
}
