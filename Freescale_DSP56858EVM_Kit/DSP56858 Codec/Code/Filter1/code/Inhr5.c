/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : Inhr5.C
**     Project   : Filter1
**     Processor : 56858
**     Component : BitIO
**     Version   : Component 02.075, Driver 01.18, CPU db: 2.87.105
**     Compiler  : Metrowerks DSP C Compiler
**     Date/Time : 2/27/2018, 12:22 PM
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
**                       134           |  GPIOC3_SC00
**             ----------------------------------------------------
**
**         Port name                   : GPIOC
**
**         Bit number (in port)        : 3
**         Bit mask of the port        : 8
**
**         Initial direction           : Output (direction cannot be changed)
**         Initial output value        : 0
**         Initial pull option         : off
**
**         Port data register          : GPIO_C_DR [2096746]
**         Port control register       : GPIO_C_DDR [2096745]
**         Port function register      : GPIO_C_PER [2096744]
**
**         Optimization for            : speed
**     Contents  :
**         GetVal - bool Inhr5_GetVal(void);
**         PutVal - void Inhr5_PutVal(bool Val);
**         ClrVal - void Inhr5_ClrVal(void);
**         SetVal - void Inhr5_SetVal(void);
**
**     Copyright : 1997 - 2009 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

/* MODULE Inhr5. */

#include "Inhr5.h"
/*Include shared modules, which are used for whole project*/
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

#include "Cpu.h"


/*
** ===================================================================
**     Method      :  Inhr5_GetVal (component BitIO)
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
/*
bool Inhr5_GetVal(void)

**  This method is implemented as a macro. See Inhr5.h file.  **

*/

/*
** ===================================================================
**     Method      :  Inhr5_PutVal (component BitIO)
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
void Inhr5_PutVal(bool Val)
{
  if (Val) {                           /* Is it one to be written? */
    setRegBits(GPIO_C_DR,Inhr5_PIN_MASK); /* Set bit on port */
  }
  else {                               /* Is it zero to be written? */
    clrRegBits(GPIO_C_DR,Inhr5_PIN_MASK); /* Clear bit on port */
  }
}

/*
** ===================================================================
**     Method      :  Inhr5_SetVal (component BitIO)
**
**     Description :
**         This method sets (sets to one) the output value.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void Inhr5_SetVal(void)

**  This method is implemented as a macro. See Inhr5.h file.  **
*/

/*
** ===================================================================
**     Method      :  Inhr5_ClrVal (component BitIO)
**
**     Description :
**         This method clears (sets to zero) the output value.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void Inhr5_ClrVal(void)

**  This method is implemented as a macro. See Inhr5.h file.  **
*/

/* END Inhr5. */

/*
** ###################################################################
**
**     This file was created by Processor Expert 3.00 [04.35]
**     for the Freescale 56800 series of microcontrollers.
**
** ###################################################################
*/
