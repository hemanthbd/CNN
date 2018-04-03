/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : Serial_com.C
**     Project   : Serial
**     Processor : 56858
**     Component : AsynchroSerial
**     Version   : Component 02.472, Driver 02.06, CPU db: 2.87.105
**     Compiler  : Metrowerks DSP C Compiler
**     Date/Time : 2/16/2018, 2:35 PM
**     Abstract  :
**         This bean "AsynchroSerial" implements an asynchronous serial
**         communication. The bean supports different settings of
**         parity, word width, stop-bit and communication speed,
**         user can select interrupt or polling handler.
**         Communication speed can be changed also in runtime.
**         The bean requires one on-chip asynchronous serial channel.
**     Settings  :
**         Serial channel              : SCI0
**
**         Protocol
**             Init baud rate          : 57600baud
**             Width                   : 8 bits
**             Stop bits               : 1
**             Parity                  : none
**             Breaks                  : Disabled
**             Input buffer size       : 0
**             Output buffer size      : 0
**
**         Registers
**             Input buffer            : SCI_0_DR  [2097124]
**             Output buffer           : SCI_0_DR  [2097124]
**             Control register        : SCI_0_CR  [2097121]
**             Mode register           : SCI_0_CR  [2097121]
**             Baud setting reg.       : SCI_0_BR  [2097120]
**
**
**
**         Used pins:
**         ----------------------------------------------------------
**           Function | On package           |    Name
**         ----------------------------------------------------------
**            Input   |     73               |  GPIOE0_RXD0
**            Output  |     74               |  GPIOE1_TXD0
**         ----------------------------------------------------------
**
**
**
**     Contents  :
**         RecvChar        - byte Serial_com_RecvChar(Serial_com_TComData *Chr);
**         SendChar        - byte Serial_com_SendChar(Serial_com_TComData Chr);
**         GetCharsInRxBuf - word Serial_com_GetCharsInRxBuf(void);
**         GetCharsInTxBuf - word Serial_com_GetCharsInTxBuf(void);
**
**     Copyright : 1997 - 2009 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

/* MODULE Serial_com. */

#include "Serial_com.h"


#define OVERRUN_ERR      1             /* Overrun error flag bit    */
#define FRAMING_ERR      2             /* Framing error flag bit    */
#define PARITY_ERR       4             /* Parity error flag bit     */
#define CHAR_IN_RX       8             /* Char is in RX buffer      */
#define FULL_TX          16            /* Full transmit buffer      */
#define RUNINT_FROM_TX   32            /* Interrupt is in progress  */
#define FULL_RX          64            /* Full receive buffer       */
#define NOISE_ERR        128           /* Noise erorr flag bit      */
#define IDLE_ERR         256           /* Idle character flag bit   */
#define BREAK_ERR        512           /* Break detect              */

static word SerFlag;                   /* Flags for serial communication */
                                       /* Bits: 0 - OverRun error */
                                       /*       1 - Framing error */
                                       /*       2 - Parity error */
                                       /*       3 - Char in RX buffer */
                                       /*       4 - Full TX buffer */
                                       /*       5 - Unused */
                                       /*       6 - Full RX buffer */
                                       /*       7 - Noise error */
                                       /*       8 - Idle character  */
                                       /*       9 - Break detected  */
                                       /*      10 - Unused */
                                       /*      11 - Unused */

/*
** ===================================================================
**     Method      :  HWEnDi (component AsynchroSerial)
**
**     Description :
**         Enables or disables the peripheral(s) associated with the bean.
**         The method is called automatically as a part of the Enable and 
**         Disable methods and several internal methods.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static void HWEnDi(void)
{
  setRegBits(SCI_0_CR, (SCI_0_CR_TE_MASK | SCI_0_CR_RE_MASK)); /* Enable device */
}

/*
** ===================================================================
**     Method      :  Serial_com_RecvChar (component AsynchroSerial)
**
**     Description :
**         If any data is received, this method returns one
**         character, otherwise it returns an error code (it does
**         not wait for data). This method is enabled only if the
**         receiver property is enabled.
**         [Note:] Because the preferred method to handle error and
**         break exception in the interrupt mode is to use events
**         <OnError> and <OnBreak> the return value ERR_RXEMPTY has
**         higher priority than other error codes. As a consequence
**         the information about an exception in interrupt mode is
**         returned only if there is a valid character ready to be
**         read.
**         Version specific information for Freescale 56800
**         derivatives ] 
**         DMA mode:
**         If DMA controller is available on the selected CPU and
**         the receiver is configured to use DMA controller then
**         this method only sets the selected DMA channel. Then the
**         status of the DMA transfer can be checked using
**         GetCharsInRxBuf method. See an example of a typical usage
**         for details about the communication using DMA.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * Chr             - Pointer to a received character
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_RXEMPTY - No data in receiver
**                           ERR_BREAK - Break character is detected
**                           (only when the <Interrupt service>
**                           property is disabled and the <Break
**                           signal> property is enabled)
**                           ERR_COMMON - common error occurred (the
**                           <GetError> method can be used for error
**                           specification)
**                           Version specific information for
**                           Freescale 56800 derivatives ] 
**                           DMA mode:
**                           If DMA controller is available on the
**                           selected CPU and the receiver is
**                           configured to use DMA controller then
**                           only ERR_OK, ERR_RXEMPTY, and ERR_SPEED
**                           error code can be returned from this
**                           method.
** ===================================================================
*/
byte Serial_com_RecvChar(Serial_com_TComData *Chr)
{
  register byte Result = ERR_OK;       /* Return error code */
  register word StatReg = getReg(SCI_0_SR); /* Read status register */

  setReg(SCI_0_SR, 0);                 /* Reset error request flags */
  if (StatReg & (SCI_0_SR_OR_MASK|SCI_0_SR_NF_MASK|SCI_0_SR_FE_MASK|SCI_0_SR_PF_MASK)) { /* Is any error set? */
    Result = ERR_COMMON;               /* If yes then set common error value */
  } else if (!(StatReg & SCI_0_SR_RDRF_MASK)) { /* Is the reciver empty and no error is set? */
    return ERR_RXEMPTY;                /* If yes then error */
  }
  *Chr = (Serial_com_TComData)getReg(SCI_0_DR); /* Read data from the receiver */
  return Result;                       /* Return error code */
}

/*
** ===================================================================
**     Method      :  Serial_com_SendChar (component AsynchroSerial)
**
**     Description :
**         Sends one character to the channel. If the bean is
**         temporarily disabled (Disable method) SendChar method
**         only stores data into an output buffer. In case of a zero
**         output buffer size, only one character can be stored.
**         Enabling the bean (Enable method) starts the transmission
**         of the stored data. This method is available only if the
**         transmitter property is enabled.
**         Version specific information for Freescale 56800
**         derivatives ] 
**         DMA mode:
**         If DMA controller is available on the selected CPU and
**         the transmitter is configured to use DMA controller then
**         this method only sets selected DMA channel. Then the
**         status of the DMA transfer can be checked using
**         GetCharsInTxBuf method. See an example of a typical usage
**         for details about communication using DMA.
**     Parameters  :
**         NAME            - DESCRIPTION
**         Chr             - Character to send
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_TXFULL - Transmitter is full
** ===================================================================
*/
byte Serial_com_SendChar(Serial_com_TComData Chr)
{
  if (!getRegBit(SCI_0_SR, TDRE)) {    /* Is the transmitter empty? */
    return ERR_TXFULL;                 /* If yes then error */
  }
  setReg(SCI_0_DR, Chr);               /* Store char to transmitter register */
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  Serial_com_GetCharsInRxBuf (component AsynchroSerial)
**
**     Description :
**         Returns the number of characters in the input buffer.
**         This method is available only if the receiver property is
**         enabled.
**         Version specific information for Freescale 56800
**         derivatives ] 
**         DMA mode:
**         If DMA controller is available on the selected CPU and
**         the receiver is configured to use DMA controller then
**         this method returns the number of characters in the
**         receive buffer.
**     Parameters  : None
**     Returns     :
**         ---             - The number of characters in the input
**                           buffer.
** ===================================================================
*/
word Serial_com_GetCharsInRxBuf(void)
{
  return (word)((getRegBit(SCI_0_SR, RDRF) != 0)? 1 : 0); /* Return number of chars in receive buffer */
}

/*
** ===================================================================
**     Method      :  Serial_com_GetCharsInTxBuf (component AsynchroSerial)
**
**     Description :
**         Returns the number of characters in the output buffer.
**         This method is available only if the transmitter property
**         is enabled.
**         Version specific information for Freescale 56800
**         derivatives ] 
**         DMA mode:
**         If DMA controller is available on the selected CPU and
**         the transmitter is configured to use DMA controller then
**         this method returns the number of characters in the
**         transmit buffer.
**     Parameters  : None
**     Returns     :
**         ---             - The number of characters in the output
**                           buffer.
** ===================================================================
*/
word Serial_com_GetCharsInTxBuf(void)
{
  return (word)((getRegBit(SCI_0_SR, TDRE) == 0)? 1 : 0); /* Return number of chars in the transmitter buffer */
}

/*
** ===================================================================
**     Method      :  Serial_com_Init (component AsynchroSerial)
**
**     Description :
**         Initializes the associated peripheral(s) and the bean internal 
**         variables. The method is called automatically as a part of the 
**         application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void Serial_com_Init(void)
{
  SerFlag = 0;                         /* Reset flags */
  /* SCI_0_CR: LOOP=0,SWAI=0,RSRC=0,M=0,WAKE=0,POL=0,PE=0,PT=0,TEIE=0,TIIE=0,RFIE=0,REIE=0,TE=0,RE=0,RWU=0,SBK=0 */
  setReg(SCI_0_CR, 0);                 /* Set the SCI configuration */
  /* SCI_0_BR: ??=0,??=0,??=0,SBR=65 */
  setReg(SCI_0_BR, 65);                /* Set prescaler bits */
  HWEnDi();                            /* Enable/disable device according to status flags */
}


/* END Serial_com. */


/*
** ###################################################################
**
**     This file was created by Processor Expert 3.00 [04.35]
**     for the Freescale 56800 series of microcontrollers.
**
** ###################################################################
*/
