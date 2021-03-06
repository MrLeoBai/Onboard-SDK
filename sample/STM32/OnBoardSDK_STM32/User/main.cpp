/**
  *******************************************************************************
	*                                                                             *               
	*          --------               --------                 --------           *                                            
	*         |        |   USART2    |        |    USART3     |        |          *                           
	*         |   PC   | <---------> | stm32  |  <----------> |  M100  |          *                                        
	*         |        | (USB-TTL)   |        |               |        |          *                          
	*         |        |             |        |               |        |          *                          
	*          --------               --------                 --------           *                                            
	*                                                                             *               
	*                                                                             *                                                                                                                                                                                   
	*******************************************************************************  
	*  @brief An exmaple program of DJI-onboard-SDK portable for stm32
	*  
	*  @version 1.1
	*
	*  @abstract
	*
	*  @attention
	*  Project configuration:
	*
	*  @version features:
	*  -* @version V1.1
	*  -* DJI-onboard-SDK portable for stm32
	*  -* @date Dec 20, 2016
	*  -* @author yourke.lu
	*
	* */
	
	 

#include "main.h"

/*-----------------------DJI_LIB VARIABLE-----------------------------*/
using namespace DJI::onboardSDK;
DJI::onboardSDK::HardDriver* driver = new STM32F4;
CoreAPI defaultAPI = CoreAPI(driver);
CoreAPI *coreApi = &defaultAPI; 
Flight flight = Flight(coreApi);
FlightData flightData ;
VirtualRC virtualrc = VirtualRC(coreApi); 
VirtualRCData myVRCdata={1024,1024,1024,1024,1024,1024,1024,1024,1024,1024,1024,1024,1024,1024,1024};

int main()
{ 
	BSPinit();
 	delay_nms(30);
	printf("Initializing...\r\n");
	
	delay_nms(1000);
	coreApi->getSDKVersion();
	delay_nms(20);
	printf("Done~!\r\n");
	
 	while(1)
	{
			if(Rx_Handle_Flag == 1)
				{
						Rx_Handle_Flag = 0;
						Rx_buff_Handler();
				}
		delay_nms(50);
	}
}

void delay_nms(u16 time)
{    
   u32 i=0;  
   while(time--)
   {
      i=30000;  
      while(i--) ;    
   }
}
 
