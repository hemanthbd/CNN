/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : GreenLed.H
**     Project   : LEDControl
**     Processor : 56858
**     Component : BitIO
**     Version   : Component 02.075, Driver 01.18, CPU db: 2.87.105
**     Compiler  : Metrowerks DSP C Compiler
**     Date/Time : 2/16/2018, 12:17 PM
**     Abstract  :
**         This bean "BitIO" implements an one-bit input/output.
**         It uses one bit/pin of a port.
**         Note: This bean is set to work in Output direction only.
**         Methods of this bean are mostly implemented as a macros
**         (if supported by target language and compiler).
**     Settings  :
**         Used pin                    :
**             ----------------------------------------------------
**                Number (on package)  |    Name
**             ----------------------------------------------------
**                       101           |  GPIOD2_SCK1
**             ----------------------------------------------------
**
**         Port name                   : GPIOD
**
**         Bit number (in port)        : 2
**         Bit mask of the port        : 4
**
**         Initial direction           : Output (direction cannot be changed)
**         Initial output value        : 0
**         Initial pull option         : off
**
**         Port data register          : GPIO_D_DR [2096750]
**         Port control register       : GPIO_D_DDR [2096749]
**         Port function register      : GPIO_D_PER [2096748]
**
**         Optimization for            : speed
**     Contents  :
**         GetVal - bool GreenLed_GetVal(void);
**         PutVal - void GreenLed_PutVal(bool Val);
**         ClrVal - void GreenLed_ClrVal(void);
**         SetVal - void GreenLed_SetVal(void);
**         NegVal - void GreenLed_NegVal(void);
**
**     Copyright : 1997 - 2009 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

#ifndef __GreenLed_H
#define __GreenLed_H

/* MODULE GreenLed. */

/*Include shared modules, which are used for whole project*/
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

#include "Cpu.h"


#define GreenLed_PIN_MASK       ((byte)4) /* Pin mask */


/*
** ===================================================================
**     Method      :  GreenLed_GetVal (component BitIO)
**
**     Description :
**         This method returns an input value.
**           a) direction = Input  : reads the input value from the
**                                   pin and returns it
**           b) direction = Output : returns the last written value
**         Note: This bean is set to work in Output direction only.
**     Parameters  : None
**     Returns     :
**         ---             - Input value. Possible values:
**                           FALSE - logical "0" (Low level)
**                           TRUE - logical "1" (High level)

** ===================================================================
*/
#define GreenLed_GetVal() ((bool)(getRegBits(GPIO_D_DR,GreenLed_PIN_MASK)))

/*
** ===================================================================
**     Method      :  GreenLed_PutVal (component BitIO)
**
**     Description :
**         This method writes the new output value.
**     Parameters  :
**         NAME       - DESCRIPTION
**         Val             - Output value. Possible values:
**                           FALSE - logical "0" (Low level)
**                           TRUE - logical "1" (High level)
**     Returns     : Nothing
** ===================================================================
*/
void GreenLed_PutVal(bool Val);

/*
** ===================================================================
**     Method      :  GreenLed_ClrVal (component BitIO)
**
**     Description :
**         This method clears (sets to zero) the output value.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
#define GreenLed_ClrVal() (clrRegBits(GPIO_D_DR,GreenLed_PIN_MASK))

/*
** ===================================================================
**     Method      :  GreenLed_SetVal (component BitIO)
**
**     Description :
**         This method sets (sets to one) the output value.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
#define GreenLed_SetVal() (setRegBits(GPIO_D_DR,GreenLed_PIN_MASK))

/*
** ===================================================================
**     Method      :  GreenLed_NegVal (component BitIO)
**
**     Description :
**         This method negates (inverts) the output value.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
#define GreenLed_NegVal() (changeRegBits(GPIO_D_DR,GreenLed_PIN_MASK))


/* END GreenLed. */

#endif /* __GreenLed_H*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 3.00 [04.35]
**     for the Freescale 56800 series of microcontrollers.
**
** ###################################################################
*/
