/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : Cpu.H
**     Project   : Code_loopback
**     Processor : 56858
**     Component : 56858
**     Version   : Component 01.023, Driver 02.08, CPU db: 2.87.105
**     Datasheet : DSP56858/D Rev. 3.0, DSP5685XUM/D Rev. 2.0
**     Compiler  : Metrowerks DSP C Compiler
**     Date/Time : 2/23/2018, 1:19 PM
**     Abstract  :
**
**     Settings  :
**
**     Contents  :
**         EnableInt   - void Cpu_EnableInt(void);
**         DisableInt  - void Cpu_DisableInt(void);
**         SetWaitMode - void Cpu_SetWaitMode(void);
**         SetStopMode - void Cpu_SetStopMode(void);
**         SetDataMode - void Cpu_SetDataMode(byte Mode);
**
**     (c) Freescale Semiconductor
**     2004 All Rights Reserved
**
**     Copyright : 1997 - 2009 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

#ifndef __Cpu_H
#define __Cpu_H

/* MODULE Cpu. */

/* Active PE project configuration */
#define PEcfg_sdm 1

/* Active CPU bean */
#define PE_CPU_TYPE_56858

/* Active CPU variant */
#define PE_CPU_VARIANT_56858

/* Active CPU family */
#define PE_CPU_FAMILY_56800

/* Active CPU subfamily */
#define PE_CPU_SUBFAMILY_5685x

/*Include shared modules, which are used for whole project*/
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "assert.h"

#ifndef __BWUserType_TShadowRegs
#define __BWUserType_TShadowRegs
  typedef struct {                     /* Shadow register type. */
    word* R0;                          /* Shadow register R0. */
    word* R1;                          /* Shadow register R1. */
    int16_t N;                         /* Shadow register N. */
    int16_t M01;                       /* Shadow register M01. */
  } TShadowRegs;
#endif

/*lint -esym(765,SR_reg,SR_lock,_EntryPoint,_vect,_vectboot,Cpu_Interrupt) Disable MISRA rule (23) checking for symbols (SR_reg,SR_lock,_EntryPoint,_vect,_vectboot,Cpu_Interrupt). */
/* Global variables */
extern volatile word SR_lock;          /* Lock */
extern volatile word SR_reg;           /* Current value of the SR register */

#define   Cpu_SetStopMode()  asm(STOP) /* Set STOP mode */
/*
** ===================================================================
**     Method      :  Cpu_SetStopMode (component 56858)
**
**     Description :
**         Sets low power mode - Stop mode.
**         For more information about the stop mode see this CPU
**         documentation.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

#define   Cpu_SetWaitMode()  asm(WAIT) /* Set WAIT mode */
/*
** ===================================================================
**     Method      :  Cpu_SetWaitMode (component 56858)
**
**     Description :
**         Sets low power mode - Wait mode.
**         For more information about the wait mode see this CPU
**         documentation.
**         Release from wait mode: Reset or interrupt
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/



#define   Cpu_DisableInt()  __DI()     /* Disable interrupts */
/*
** ===================================================================
**     Method      :  Cpu_DisableInt (component 56858)
**
**     Description :
**         Disables all maskable interrupts
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

#define   Cpu_EnableInt()  __EI(0)     /* Enable interrupts */
/*
** ===================================================================
**     Method      :  Cpu_EnableInt (component 56858)
**
**     Description :
**         Enables all maskable interrupts
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void Cpu_SetDataMode(byte Mode);
/*
** ===================================================================
**     Method      :  Cpu_SetDataMode (component 56858)
**
**     Description :
**         Sets the Data memory map to use either internal &
**         external resources or external resources only.
**     Parameters  :
**         NAME            - DESCRIPTION
**         Mode            - Data memory access mode.
**                           Possible modes:
**                           INT_EXT_MODE - use internal & external
**                           resources
**                           EXT_MODE - use external resources only
**     Returns     : Nothing
** ===================================================================
*/

void PE_low_level_init(void);
/*
** ===================================================================
**     Method      :  PE_low_level_init (component 56858)
**
**     Description :
**         Initializes beans and provides common register initialization. 
**         The method is called automatically as a part of the 
**         application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void Cpu_Interrupt(void);
/*
** ===================================================================
**     Method      :  Cpu_Interrupt (component 56858)
**
**     Description :
**         The method services unhandled interrupt vectors.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/


void _EntryPoint(void);
/*
** ===================================================================
**     Method      :  _EntryPoint (component 56858)
**
**     Description :
**         Initializes the whole system like timing and so on. At the end 
**         of this function, the C startup is invoked to initialize stack,
**         memory areas and so on.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

/* END Cpu. */

#endif
/* __Cpu_H */

/*
** ###################################################################
**
**     This file was created by Processor Expert 3.00 [04.35]
**     for the Freescale 56800 series of microcontrollers.
**
** ###################################################################
*/
