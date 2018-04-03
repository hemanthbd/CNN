/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : Bit1.H
**     Project   : LEDControl
**     Processor : 56858
**     Component : BitIO
**     Version   : Component 02.075, Driver 01.18, CPU db: 2.87.105
**     Compiler  : Metrowerks DSP C Compiler
**     Date/Time : 2/16/2018, 1:49 PM
**     Abstract  :
**         This bean "BitIO" implements an one-bit input/output.
**         It uses one bit/pin of a port.
**         Methods of this bean are mostly implemented as a macros
**         (if supported by target language and compiler).
**     Settings  :
**         Used pin                    :
**             ----------------------------------------------------
**                Number (on package)  |    Name
**             ----------------------------------------------------
**                       1             |  GPIOF0_MISO
**             ----------------------------------------------------
**
**         Port name                   : GPIOF
**
**         Bit number (in port)        : 0
**         Bit mask of the port        : 1
**
**         Initial direction           : Output (direction can be changed)
**         Safe mode                   : yes
**         Initial output value        : 0
**         Initial pull option         : off
**
**         Port data register          : GPIO_F_DR [2096758]
**         Port control register       : GPIO_F_DDR [2096757]
**         Port function register      : GPIO_F_PER [2096756]
**
**         Optimization for            : speed
**     Contents  :
**         SetDir - void Bit1_SetDir(bool Dir);
**         GetVal - bool Bit1_GetVal(void);
**         PutVal - void Bit1_PutVal(bool Val);
**         ClrVal - void Bit1_ClrVal(void);
**         SetVal - void Bit1_SetVal(void);
**
**     Copyright : 1997 - 2009 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

#ifndef __Bit1_H
#define __Bit1_H

/* MODULE Bit1. */

/*Include shared modules, which are used for whole project*/
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

#include "Cpu.h"


#define Bit1_PIN_MASK           ((byte)1) /* Pin mask */


/*
** ===================================================================
**     Method      :  Bit1_GetVal (component BitIO)
**
**     Description :
**         This method returns an input value.
**           a) direction = Input  : reads the input value from the
**                                   pin and returns it
**           b) direction = Output : returns the last written value
**     Parameters  : None
**     Returns     :
**         ---             - Input value. Possible values:
**                           FALSE - logical "0" (Low level)
**                           TRUE - logical "1" (High level)

** ===================================================================
*/
#define Bit1_GetVal() ((bool)(getRegBits(GPIO_F_DR,Bit1_PIN_MASK)))

/*
** ===================================================================
**     Method      :  Bit1_PutVal (component BitIO)
**
**     Description :
**         This method writes the new output value.
**           a) direction = Input  : sets the new output value;
**                                   this operation will be shown on
**                                   output after the direction has
**                                   been switched to output
**                                   (SetDir(TRUE);)
**           b) direction = Output : directly writes the value to the
**                                   appropriate pin
**     Parameters  :
**         NAME       - DESCRIPTION
**         Val             - Output value. Possible values:
**                           FALSE - logical "0" (Low level)
**                           TRUE - logical "1" (High level)
**     Returns     : Nothing
** ===================================================================
*/
void Bit1_PutVal(bool Val);

/*
** ===================================================================
**     Method      :  Bit1_SetDir (component BitIO)
**
**     Description :
**         This method sets direction of the bean.
**     Parameters  :
**         NAME       - DESCRIPTION
**         Dir        - Direction to set (FALSE or TRUE)
**                      FALSE = Input, TRUE = Output
**     Returns     : Nothing
** ===================================================================
*/
void Bit1_SetDir(bool Dir);

/*
** ===================================================================
**     Method      :  Bit1_ClrVal (component BitIO)
**
**     Description :
**         This method clears (sets to zero) the output value.
**           a) direction = Input  : sets the output value to "0";
**                                   this operation will be shown on
**                                   output after the direction has
**                                   been switched to output
**                                   (SetDir(TRUE);)
**           b) direction = Output : directly writes "0" to the
**                                   appropriate pin
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
#define Bit1_ClrVal() ((Shadow_GPIO_F_DR &= ~Bit1_PIN_MASK), (clrRegBits(GPIO_F_DR,Bit1_PIN_MASK)))

/*
** ===================================================================
**     Method      :  Bit1_SetVal (component BitIO)
**
**     Description :
**         This method sets (sets to one) the output value.
**           a) direction = Input  : sets the output value to "1";
**                                   this operation will be shown on
**                                   output after the direction has
**                                   been switched to output
**                                   (SetDir(TRUE);)
**           b) direction = Output : directly writes "1" to the
**                                   appropriate pin
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
#define Bit1_SetVal() ((Shadow_GPIO_F_DR |= Bit1_PIN_MASK), (setRegBits(GPIO_F_DR,Bit1_PIN_MASK)))


/* END Bit1. */

#endif /* __Bit1_H*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 3.00 [04.35]
**     for the Freescale 56800 series of microcontrollers.
**
** ###################################################################
*/
