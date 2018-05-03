#include "motorController.h"
TIM_HandleTypeDef htim3;
void HAL_TIM_PWM_MspInit();
void initMotor(int8_t Dindex) {
	initGPIO(Dindex, GPIO_MODE_OUTPUT_PP, GPIO_PULLDOWN, GPIO_SPEED_HIGH, 0);
}
void moveDoor() {
	digitalWrite(motor_GPIO_Num, 1);
	delayMicro(100000000 / 8 );
	digitalWrite(motor_GPIO_Num, 0);
}
/* TIM3 init function */
void initTIM3(void)
{
  TIM_MasterConfigTypeDef sMasterConfig;
  TIM_OC_InitTypeDef sConfigOC;
  
  htim3.Instance = TIM3;
  htim3.Init.Prescaler = 102;
  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim3.Init.Period = (uint16_t) (8399);
  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  HAL_TIM_PWM_Init(&htim3);
  
//  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
//  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
//  HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig);
  
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 4099;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_1);
	HAL_TIM_PWM_Init(&htim3);
  
}
void HAL_TIM_PWM_MspInit(TIM_HandleTypeDef* htim_pwm) {
  if(htim_pwm->Instance==TIM3)
  {
    /* Peripheral clock enable */
    __TIM3_CLK_ENABLE();
		
		initGPIO(motor_GPIO_Num, GPIO_MODE_AF_PP, GPIO_PULLDOWN, GPIO_SPEED_HIGH, GPIO_AF2_TIM3);
  }
	
}
void startMotor() {
	HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_1); 
	HAL_TIMEx_PWMN_Start(&htim3,TIM_CHANNEL_1);
}
void stopMotor() {
	HAL_TIMEx_PWMN_Stop(&htim3,TIM_CHANNEL_1); 
}