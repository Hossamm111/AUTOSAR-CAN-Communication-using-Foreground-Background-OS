/********************************************************************************/
/* Module Name  : Systick.c							*/
/* Author       : Hossam						        */
/* Purpose      : Use SysTick Timer Services					*/
/********************************************************************************/

#include "Systick.h"

/*******************************************************************************
 *                              Global Variables                               *
 *******************************************************************************/

uint8_t Systick_Flag = 0;

/********************************************************************************/
/* Function Name: void SysTick_Init (void)					*/
/* Inputs       : None		                                                */
/* Outputs      : None				 			        */
/* Reentrancy   : Non-Reentrant				 			*/
/* Synchronous  : Synchronous							*/
/* Description  : Initialize SysTick Timer	 				*/
/********************************************************************************/

void SysTick_Init (void)
{
  SysTickDisable();
  
  SysTickPeriodSet(SysTick_Load);
  
  SysTickIntEnable();
  
  SysTickEnable();
}

/********************************************************************************/
/* Function Name: void systickHandler (void)					*/
/* Inputs       : ChannelId		                                        */
/* Outputs      : None				 			        */
/* Reentrancy   : Non-Reentrant				 			*/
/* Synchronous  : Synchronous							*/
/* Description  : Handler Function for SysTick Timer	 			*/
/********************************************************************************/

void SysTickHandler (void)
{
  Systick_Flag ++;
}

/********************************************************************************/
/* Function Name: void systickHandler (void)					*/
/* Inputs       : ChannelId		                                        */
/* Outputs      : None				 			        */
/* Reentrancy   : Non-Reentrant				 			*/
/* Synchronous  : Synchronous							*/
/* Description  : Handler Function for SysTick Timer	 			*/
/********************************************************************************/

uint8_t Get_SysTick_Flag (void)
{
  return Systick_Flag;
}

/********************************************************************************/
/* Function Name: void systickHandler (void)					*/
/* Inputs       : ChannelId		                                        */
/* Outputs      : None				 			        */
/* Reentrancy   : Non-Reentrant				 			*/
/* Synchronous  : Synchronous							*/
/* Description  : Handler Function for SysTick Timer	 			*/
/********************************************************************************/

void Set_SysTick_Flag (uint8 Flag)
{
  Systick_Flag = false;
}