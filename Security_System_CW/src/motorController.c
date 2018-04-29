#include "motorController.h"
TIM_HandleTypeDef htim3;
void HAL_TIM_PWM_MspInit();
void initMotor(int8_t Dindex) {
	initGPIO(Dindex, GPIO_MODE_OUTPUT_PP, GPIO_PULLDOWN, GPIO_SPEED_HIGH, 0);
	
}
/* TIM3 init function */
void initTIM3(void)
{
  TIM_MasterConfigTypeDef sMasterConfig;
  TIM_OC_InitTypeDef sConfigOC;
  
  htim3.Instance = TIM1;
  htim3.Init.Prescaler = (uint16_t) ((SystemCoreClock / 2) / 1000000) - 1;
  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim3.Init.Period = (uint16_t) (1000000 / 50);
  htim3.Init.ClockDivision = 0; //was TIM_CLOCKDIVISION_DIV1
  HAL_TIM_PWM_Init(&htim3);
  
//  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
//  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
//  HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig);
  
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 22;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_1);
	HAL_TIM_PWM_Init(&htim3);
  
}
void HAL_TIM_PWM_MspInit(TIM_HandleTypeDef* htim_pwm) {
  if(htim_pwm->Instance==TIM1)
  {
    /* Peripheral clock enable */
    __TIM1_CLK_ENABLE();
		
		initGPIO(servo_Num, GPIO_MODE_AF_PP, GPIO_PULLDOWN, GPIO_SPEED_HIGH, GPIO_AF1_TIM1);
  }
	
}
void startMotor() {
	HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_1); 
	HAL_TIMEx_PWMN_Start(&htim3,TIM_CHANNEL_1);
}
void stopMotor() {
	HAL_TIMEx_PWMN_Stop(&htim3,TIM_CHANNEL_1); 
}