/********************************************************************************/
/* Module Name  : OS.c							        */
/* Author       : Hossam						        */
/* Purpose      : Operating System Service				        */
/********************************************************************************/

#include "OS.h"

/*******************************************************************************
 *                              Global Variables                               *
 *******************************************************************************/

/* Common Variables */
   
uint32 Elapsed_Idle_Time   = RESET;
   
/* Master Variables */

volatile bool SW1;
volatile bool SW2;

uint8 State;

extern uint8 Timer_Flag;

uint32 Elapsed_Master_Time = RESET;

/* Slave Variables */

uint8 State_Counter = RESET;
  
uint32 Elapsed_Slave_Time = RESET;

uint8 *Received_Msg_Address;

uint8 Received_Msg;

/********************************************************************************/
/* Function Name: void Scheduler_Start (void)			                */
/* Inputs       : None		                                                */
/* Outputs      : None				 	                        */
/* Reentrancy   : Non-Reentrant				 			*/
/* Synchronous  : Synchronous							*/
/* Description  : Start the Scheduler	                                        */
/********************************************************************************/

void Scheduler_Start (void)
{
  #ifdef MASTER
  
  Master_Scheduler();
  
  #else
  
  Slave_Scheduler();
  
  #endif /* __MASTER/SLAVE__ */
}

/********************************************************************************/
/* Function Name: void Master_Scheduler (void)			                */
/* Inputs       : None		                                                */
/* Outputs      : None				 	                        */
/* Reentrancy   : Reentrant				 			*/
/* Synchronous  : Asynchronous							*/
/* Description  : Start the Master Scheduler	                                */
/********************************************************************************/

void Master_Scheduler (void)
{ 
  CallBack_LED_Mode(LED_Mode, WHITE);
  
  while (true)
  {
    while (Get_Timer_Flag())
    {
      SW1 = Read_Button(Button1);
      SW2 = Read_Button(Button2);
      
      if (SW1 == STD_LOW && SW2 == STD_HIGH && Elapsed_Idle_Time <= Five_Seconds)
      {
        Elapsed_Master_Time++;
        Elapsed_Idle_Time = RESET;
        
        State = CLOCKWISE;
        
        CallBack_LED_Mode(LED_Mode, VIOLET);
        
        while (Read_Button(Button1) == STD_LOW && Read_Button(Button2) == STD_HIGH);
      }
      
      else if (SW1 == STD_HIGH && SW2 == STD_LOW && Elapsed_Idle_Time <= Five_Seconds)
      {
        Elapsed_Master_Time++;
        Elapsed_Idle_Time = RESET;
        
        State = COUNTERCLOCKWISE;
        
        CallBack_LED_Mode(LED_Mode, YELLOW);
        
        while (Read_Button(Button1) == STD_HIGH && Read_Button(Button2) == STD_LOW);
      }
      
      else if (SW1 == STD_LOW && SW2 == STD_LOW && Elapsed_Idle_Time <= Five_Seconds)
      {
        Elapsed_Master_Time++;
        Elapsed_Idle_Time = RESET;
        
        State = BOTH_PRESSED;
        
        CallBack_LED_Mode(LED_Mode, RED);
        
        while (Read_Button(Button1) == STD_LOW || Read_Button(Button2) == STD_LOW);
      }
      
      else if (SW1 == STD_HIGH && SW2 == STD_HIGH && Elapsed_Idle_Time <= Five_Seconds)
      {
        Elapsed_Master_Time++;
        Elapsed_Idle_Time++;
      }
      
      else if (Elapsed_Idle_Time > Five_Seconds)
      {
        Elapsed_Master_Time = RESET;
        Elapsed_Idle_Time   = RESET;
        
        CallBack_Send_Command(Send_Command, IDLE);
        
        CallBack_LED_Mode(LED_Mode, WHITE);
      }
      else
      {
        /* do nothing */
      }
      
      if (Elapsed_Master_Time >= Half_Second)
      {
        Elapsed_Master_Time = RESET;
        
        CallBack_Send_Command(Send_Command, State);
        
        State = TEMP;
      }
      
      else
      {
        /* do nothing */
      }
      Set_Timer_Flag(Timer_Flag);
    }
  }
}

/********************************************************************************/
/* Function Name: void Slave_Scheduler (void)			                */
/* Inputs       : None		                                                */
/* Outputs      : None				 	                        */
/* Reentrancy   : Reentrant				 			*/
/* Synchronous  : Asynchronous							*/
/* Description  : Start the Slave Scheduler	                                */
/********************************************************************************/

void Slave_Scheduler (void)
{
  Received_Msg_Address = &Received_Msg;
  Received_Msg_Ptr(Received_Msg_Address);
  
  CallBack_LED_Mode(LED_Mode, WHITE);
  
  while (true)
  {
    while (Get_Timer_Flag())
    {
      if (Received_Msg == CLOCKWISE)
      {
        if (State_Counter < MAX)
        {
          State_Counter++;
        }
        else
        { 
          State_Counter = MIN;
        }
      }
      
      else if (Received_Msg == COUNTERCLOCKWISE)
      {
        if(State_Counter > MIN)
        {
          State_Counter--;
        }
        else
        {
          State_Counter = MAX;
        }
      }
      
      else if (Received_Msg == BOTH_PRESSED)
      { 
        State_Counter = MIN;
        
        CallBack_LED_Mode(LED_Mode, RED);
      }
      
      else if (Received_Msg == IDLE)
      { 
        State_Counter = RESET;
        
        CallBack_LED_Mode(LED_Mode, WHITE);
      }
      
      else    
      { 
        /* do nothing */
      }
      
      Received_Msg = TEMP;                  
      
      Set_Timer_Flag(Timer_Flag);
      
      Elapsed_Slave_Time++;
    }
    
    if (Elapsed_Slave_Time >= One_Second)
    {
      if (State_Counter == WHITE)
      {
        CallBack_LED_Mode(LED_Mode, WHITE);
      }
      
      else if (State_Counter == RED)
      {
        CallBack_LED_Mode(LED_Mode, RED);
      }
      
      else if (State_Counter == BLUE)
      {
        CallBack_LED_Mode(LED_Mode, BLUE);
      }
      
      else if (State_Counter == GREEN)
      {
        CallBack_LED_Mode(LED_Mode, GREEN);
      }
      Elapsed_Slave_Time = RESET;
    }
  }
}

/****************************************************************************************/   
/* Function Name: void CallBack_LED_Mode(void (*Led_Mode)(uint8), uint8 Led_State)	*/
/* Inputs       : void (*Led_Mode)(uint8) __+__ uint8 Led_State		                */
/* Outputs      : None				 	                                */
/* Reentrancy   : Reentrant				 			        */
/* Synchronous  : Synchronous							        */
/* Description  : Callback Led Mode Component	                                        */
/****************************************************************************************/

void CallBack_LED_Mode(void (*Led_Mode)(uint8), uint8 Led_State)
{
  Led_Mode(Led_State);
}


/****************************************************************************************/   
/* Function Name: void CallBack_Send_Command(void (*Send_Command)(uint8), uint8 State)	*/
/* Inputs       : void (*Send_Command)(uint8) __+__ uint8 State		                */
/* Outputs      : None				 	                                */
/* Reentrancy   : Reentrant				 			        */
/* Synchronous  : Synchronous							        */
/* Description  : Callback Send Command Component	                                */
/****************************************************************************************/

void CallBack_Send_Command(void (*Send_Command)(uint8), uint8 State)
{
  Send_Command(State);
}





