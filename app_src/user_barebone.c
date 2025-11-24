/**
 ****************************************************************************************
 *
 * @file user_barebone.c
 *
 * @brief Barebone project source code.
 *
 * Copyright (c) 2015-2021 Renesas Electronics Corporation and/or its affiliates
 * The MIT License (MIT)
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
 * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE
 * OR OTHER DEALINGS IN THE SOFTWARE.
 ****************************************************************************************
 */

/**
 ****************************************************************************************
 * @addtogroup APP
 * @{
 ****************************************************************************************
 */

#include "rwip_config.h"             // SW configuration

/*
 * INCLUDE FILES
 ****************************************************************************************
 */

#include "app_api.h"
#include "user_barebone.h"
#include "user_periph_setup.h"

#include "SEGGER_SWD_printf.h"
/*
 * FUNCTION DEFINITIONS
 ****************************************************************************************
*/

/**
 ****************************************************************************************
 * @brief Control LED state.
 * @param[in] state LED state (true = on, false = off)
 * @return void
 ****************************************************************************************
 */
void control_LED(bool state)
{
    if(state == true)
        GPIO_SetActive(LED_PORT, LED_PIN);
    else
        GPIO_SetInactive(LED_PORT, LED_PIN);
}

/*
 * CALLBACK DEFINITIONS
 ****************************************************************************************
*/

/**
 ****************************************************************************************
 * @brief Application initialization callback.
 * @return void
 ****************************************************************************************
 */
void user_app_on_init(void)
{
    SWD_printf("user_app_on_init\n");
    default_app_on_init();
}

/**
 ****************************************************************************************
 * @brief Connection callback.
 * @param[in] connection_idx Connection index
 * @param[in] param Connection request indication parameters
 * @return void
 ****************************************************************************************
 */
void user_on_connection(uint8_t connection_idx, struct gapc_connection_req_ind const *param)
{   
    SWD_printf("user_on_connection\n");
    default_app_on_connection(connection_idx, param);
    control_LED(true);
}

/**
 ****************************************************************************************
 * @brief Disconnection callback.
 * @param[in] param Disconnect indication parameters
 * @return void
 ****************************************************************************************
 */
void user_on_disconnect(struct gapc_disconnect_ind const *param)
{
    SWD_printf("user_on_disconnect\n");
    default_app_on_disconnect(param);
    control_LED(false);
}

/// @} APP
