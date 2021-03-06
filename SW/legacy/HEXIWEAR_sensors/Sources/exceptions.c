/**
 * handlers
 * Project HEXIWEAR, 2015
 */

#include <stdint.h>
#include "FreeRTOS.h"
#include "task.h"

#include "error.h"

static void getRegistersFromStack (
                                    uint32_t* pulFaultStackAddress
                                  )
{
  /* These are volatile to try and prevent the compiler/linker optimising them
  away as the variables never actually get used.  If the debugger won't show the
  values of the variables, make them global my moving their declaration outside
  of this function. */
  volatile uint32_t r0;
  volatile uint32_t r1;
  volatile uint32_t r2;
  volatile uint32_t r3;
  volatile uint32_t r12;
  volatile uint32_t lr;  // link register
  volatile uint32_t pc;  // program counter
  volatile uint32_t psr; // program status register

  r0 = pulFaultStackAddress[ 0 ];
  r1 = pulFaultStackAddress[ 1 ];
  r2 = pulFaultStackAddress[ 2 ];
  r3 = pulFaultStackAddress[ 3 ];

  r12 = pulFaultStackAddress[ 4 ];
  lr  = pulFaultStackAddress[ 5 ];
  pc  = pulFaultStackAddress[ 6 ];
  psr = pulFaultStackAddress[ 7 ];

  // when the following line is hit, the variables contain the register values
  __asm("nop");
}

void NMI_Handler()
{
  __asm("nop");
}

void HardFault_Handler()
{
  __asm("nop");
}

void MemManage_Handler()
{
  __asm("nop");
}

void BusFault_Handler()
{
  __asm volatile
  (
    " tst lr, #4                                                \n"
    " ite eq                                                    \n"
    " mrseq r0, msp                                             \n"
    " mrsne r0, psp                                             \n"
    " ldr r1, [r0, #24]                                         \n"
    " ldr r2, handler2_address_const                            \n"
    " bx r2                                                     \n"
    " handler2_address_const: .word getRegistersFromStack       \n"
  );
}

void UsageFault_Handler()
{
  __asm("nop");
}

void DefaultISR()
{
  __asm("nop");
}

void vApplicationStackOverflowHook(
                                    TaskHandle_t xTask,
                                    signed char* pcTaskName
                                  )
{
  catch(1);
}

void vApplicationMallocFailedHook()
{
  catch(1);
}
