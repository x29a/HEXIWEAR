/* ###################################################################
 *      This component module is generated by Processor Expert. Do not modify it.
 *      Filename    : CLK_manager.c
 *      Project     : HEXIWEAR_MK64
 *      Processor   : MK64FN1M0VDC12
 *      Component   : fsl_clock_manager
 *      Version     : Component 1.2.0, Driver 01.00, CPU db: 3.00.000
 *      Repository  : KSDK 1.2.0
 *      Compiler    : GNU C Compiler
 *      Date/Time   : 2016-03-04, 12:30, # CodeGen: 0
 *
 *      Copyright : 1997 - 2015 NXP Semiconductor, Inc.
 *      All Rights Reserved.
 *
 *      Redistribution and use in source and binary forms, with or without modification,
 *      are permitted provided that the following conditions are met:
 *
 *      o Redistributions of source code must retain the above copyright notice, this list
 *        of conditions and the following disclaimer.
 *
 *      o Redistributions in binary form must reproduce the above copyright notice, this
 *        list of conditions and the following disclaimer in the documentation and/or
 *        other materials provided with the distribution.
 *
 *      o Neither the name of NXP Semiconductor, Inc. nor the names of its
 *        contributors may be used to endorse or promote products derived from this
 *        software without specific prior written permission.
 *
 *      THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 *      ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 *      WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 *      DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 *      ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 *      (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *      LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 *      ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *      (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 *      SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *      http: www.nxp.com
 *      mail: support@nxp.com
 *  ###################################################################*/
/*!
 *  @file CLK_manager.c
 *  @version 01.00
 */
/*!
 *   @addtogroup CLK_manager_module CLK_manager module documentation
 *   @{
 */

 /** CLK_manager. */

#include "CLK_manager.h"

/*! @brief OSC Initialization Configuration Structure */
osc_user_config_t CLK_manager_osc0_Config = {
    .freq = 12000000U,
    .enableCapacitor2p = false,
    .enableCapacitor4p = false,
    .enableCapacitor8p = false,
    .enableCapacitor16p = false,
    .hgo = kOscGainLow,
    .range = kOscRangeVeryHigh,
    .erefs = kOscSrcOsc,

    /*! @brief Configuration for OSCERCLK */
    .oscerConfig =
    {
        .enable = true,
        .enableInStop = false,
    },
};

/* *************************************************************************
 * Configuration structure for Clock Configuration 0
 * ************************************************************************* */
/*! @brief User Configuration structure SpeedMode0 */
clock_manager_user_config_t CLK_manager_InitConfig0 = {
    /*! @brief Configuration of MCG */
    .mcgConfig =
    {
        .mcg_mode = kMcgModePEE, /*!< PEE mode */
        /* ------------------ MCGIRCCLK settings ---------------------- */
        .irclkEnable = true, /*!< MCGIRCLK enable */
        .irclkEnableInStop = false, /*!< MCGIRCLK enable in stop mode */
        .ircs = kMcgIrcSlow, /*!< Slow internal reference clock selected */
        .fcrdiv = 0U,

        /* -------------------- MCG FLL settings ---------------------- */
        .frdiv = 0, /*!< MCG_C1[FRDIV] */
        .drs = kMcgDcoRangeSelLow, /*!< MCG_C4[DRST_DRS] */
        .dmx32 = kMcgDmx32Default, /*!< MCG_C4[DMX32] */
        .oscsel = kMcgOscselOsc, /*!< Selects System Oscillator (OSCCLK) */

        /* -------------------- MCG PLL settings ---------------------- */
        .pll0EnableInFllMode = true, /*!< PLL0 enable in FLL mode */
        .pll0EnableInStop = false, /*!< PLL0 enable in stop mode */
        .prdiv0 = 2U, /*!< PRDIV0 */
        .vdiv0 = 6U, /*!< VDIV0 */
    },

    /*! @brief Configuration of OSCERCLK */
    .oscerConfig =
    {
        .enable = true, /*!< OSCERCLK enable or not */
        .enableInStop = false, /*!< OSCERCLK enable or not in stop mode */
    },

    /*! @brief Configuration of SIM module */
    .simConfig =
    {
        .pllFllSel = kClockPllFllSelPll, /*!< Pll0 clock  */
        .er32kSrc = kClockEr32kSrcRtc, /*!< ERCLK32K source selection */
        .outdiv1 = 0U, /*!< OUTDIV1 setting */
        .outdiv2 = 1U, /*!< OUTDIV2 setting */
        .outdiv3 = 4U, /*!< OUTDIV3 setting */
        .outdiv4 = 4U, /*!< OUTDIV4 setting */
    }
};

/*! @brief Array of pointers to User configuration structures */
clock_manager_user_config_t const * g_clockManConfigsArr[] =
{
    &CLK_manager_InitConfig0
};
/*! @brief Array of pointers to User defined Callbacks configuration structures */
clock_manager_callback_user_config_t * g_clockManCallbacksArr[] = {NULL};

 /** END CLK_manager. */

/*!
 *  @}
 */
/*
 *  ###################################################################
 *
 *      This file was created by Processor Expert 10.5 [05.21]
 *      for the NXP Kinetis series of microcontrollers.
 *
 *  ###################################################################
 */