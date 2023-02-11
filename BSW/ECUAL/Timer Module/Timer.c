/********************************************************************************/
/* Module Name  : Timer.c							*/
/* Author       : Hossam						        */
/* Purpose      : Timer Module ECU Abstraction			                */
/********************************************************************************/

#include "Timer.h"

uint8 Timer_Flag = 0;

/********************************************************************************/
/* Function Name: void Timer_Init (void)				        */
/* Inputs       : None		                                                */
/* Outputs      : None				 			        */
/* Reentrancy   : ######				 			*/
/* Synchronous  : ######							*/
/* Description  : Initialize Timer Module	 				*/
/********************************************************************************/

void Timer_Init (void)
{
  #if (ENABLE_TIMERS == YES)
  
  #if (SYSTICK_TIMER == YES)
  
  SysTick_Init();
  
  #endif
  
  #if (GPT == YES)
  
  GPT_Init();
  
  #endif
  
  #endif
}

/********************************************************************************/
/* Function Name: uint8_t Get_Timer_Flag (void)				        */
/* Inputs       : None		                                                */
/* Outputs      : None				 			        */
/* Reentrancy   : ######				 			*/
/* Synchronous  : ######							*/
/* Description  : Initialize Timer Module	 				*/
/********************************************************************************/

uint8_t Get_Timer_Flag (void)
{
  return Get_SysTick_Flag ();
}

/********************************************************************************/
/* Function Name: uint8_t Get_Timer_Flag (void)				        */
/* Inputs       : None		                                                */
/* Outputs      : None				 			        */
/* Reentrancy   : ######				 			*/
/* Synchronous  : ######							*/
/* Description  : Initialize Timer Module	 				*/
/********************************************************************************/

void Set_Timer_Flag (uint8 Flag)
{
  Set_SysTick_Flag (Flag);
}