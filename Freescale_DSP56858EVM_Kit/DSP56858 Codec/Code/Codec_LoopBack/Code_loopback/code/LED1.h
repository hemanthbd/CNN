/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : LED1.H
**     Project   : Code_loopback
**     Processor : 56858
**     Component : Led
**     Version   : Component 01.007, Driver 01.06, CPU db: 2.87.105
**     Compiler  : Metrowerks DSP C Compiler
**     Date/Time : 2/23/2018, 1:19 PM
**     Abstract  :
**          This bean provide methods for driving of LED device.
**          Methods On, Off, Set and Toggle (or only initialization code)
**          could be used to drive it. Output value, defined by Init.
**          value property, is used for initialization implicitly.
**          It is not necessary to use any method explicitly in start up.
**          Method Status return current status of the LED device.
**          LED drivers without output inverter are supported
**          via Inverted value property.
**     Settings  :
**          Output PIN                                     :GPIOD5_SC12
**          Initialize Value                               :Off
**          Inverted Value                                 :no
**     Contents  :
**         On     - void LED1_On(void);
**         Toggle - void LED1_Toggle(void);
**
**     Copyright : 1997 - 2009 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

#ifndef __LED1
#define __LED1

/* MODULE LED1. */

/*Include shared modules, which are used for whole project*/
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited beans */
#include "Inhr1.h"

#include "Cpu.h"


#define LED1_On() Inhr1_SetVal()
/*
** ===================================================================
**     Method      :  LED1_On (component Led)
**
**     Description :
**         Switch ON the LED device
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

#define LED1_Toggle() Inhr1_NegVal()
/*
** ===================================================================
**     Method      :  LED1_Toggle (component Led)
**
**     Description :
**         Toggle the LED device value
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

/* END LED1. */

#endif /* ifndef __LED1 */
/*
** ###################################################################
**
**     This file was created by Processor Expert 3.00 [04.35]
**     for the Freescale 56800 series of microcontrollers.
**
** ###################################################################
*/
