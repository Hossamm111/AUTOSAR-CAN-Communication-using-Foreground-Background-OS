/********************************************************************************/
/* Module Name  : LED_Mode.c							*/
/* Author       : Hossam						        */
/* Purpose      : Choose LED Mode				                */
/********************************************************************************/

#include "../../Application SWC/APP.h"

/********************************************************************************/
/* Function Name: void LED_Mode (uint8 Led_State)			        */
/* Inputs       : Led_State		                                        */
/* Outputs      : None				 	                        */
/* Reentrancy   : Non-Reentrant				 			*/
/* Synchronous  : Synchronous							*/
/* Description  : Choose LED Mode	                                        */
/********************************************************************************/

void LED_Mode (uint8 Led_State)
{
  switch (Led_State)
  {
    case 0:
      LED_On(RED_LED);
      LED_On(BLUE_LED);
      LED_On(GREEN_LED);
      break;
      
    case 1:
      LED_On(RED_LED);
      LED_Off(BLUE_LED);
      LED_Off(GREEN_LED);
      break;
    
    case 2:
      LED_Off(RED_LED);
      LED_On(BLUE_LED);
      LED_Off(GREEN_LED);
      break;
      
    case 3:
      LED_Off(RED_LED);
      LED_Off(BLUE_LED);
      LED_On(GREEN_LED);
      break;
      
    case 4:
      LED_On(RED_LED);
      LED_On(BLUE_LED);
      LED_Off(GREEN_LED);
      break;
      
    case 5:
      LED_On(RED_LED);
      LED_Off(BLUE_LED);
      LED_On(GREEN_LED);
      break;
    
    case 6:
      LED_On(RED_LED);
      LED_On(BLUE_LED);
      LED_On(GREEN_LED);
      break;
      
    case 7:
      LED_Off(RED_LED);
      LED_On(BLUE_LED);
      LED_On(GREEN_LED);
      break;
  }
}
