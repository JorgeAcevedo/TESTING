/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: Maping_TypeDef.h $
 * $Revision: version 1
 * $Author: Jorge Acevedo $
 * $Date: 23/10/2017 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \file
    Library for defining the data type and maping registers-
    
    This file contain definition of the data types in the Hungarian
    notation and maping of the registers udes for the Window Lifter 
    Project.
    
     
*/
/*============================================================================*/
/* COPYRIGHT (C) CONTINENTAL AUTOMOTIVE 2014                                  */
/* AUTOMOTIVE GROUP, Interior Division, Body and Security                     */
/* ALL RIGHTS RESERVED                                                        */
/*                                                                            */
/* The reproduction, transmission, or use of this document or its content is  */
/* not permitted without express written authority. Offenders will be liable  */
/* for damages.                                                               */
/* All rights, including rights created by patent grant or registration of a  */
/* utility model or design, are reserved.                                     */
/*                                                                            */
/*============================================================================*/
/*============================================================================*/
/*                    REUSE HISTORY - taken over from                         */
/*============================================================================*/
/*  AUTOR             |        VERSION     | DESCRIPCION OF INTERVENTION     */
/*----------------------------------------------------------------------------*/
/*      JORGE          |        1           |TYPE DEFINITION AND MAPING OF    */
/*                     |                    |GPIO, CLOCK AND COUNTER REGISTER */
/*----------------------------------------------------------------------------*/                       |                    |                                 */
/*                     |                    |                                 */

/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: filename.h  $
  ============================================================================*/
#ifndef MAPING_TYPEDEF_H
#define MAPING_TYPEDEF_H

/* Includes */
/*============================================================================*/


/* Constants and types */
/*============================================================================*/
/* Data type definition  */
typedef unsigned char  T_UBYTE;
typedef unsigned short T_UWORD;
typedef unsigned long  T_ULONG;
typedef signed char    T_SBYTE;
typedef signed short   T_SWORD;
typedef signed long    T_SLONG;

/* GPIO (General Purpose Input Output) */
typedef struct {
	T_ULONG PDOR; //configures the logic leves that are driven on each general-purpose output pin (0=high, 1=low)
	T_ULONG PSOR; //configures wheter to set the field of the PDOR (0=set to logic 1; 1= does not change)
	T_ULONG PCOR; //configures wheter to clear the fields of PDOR (0=does not change; 1=corresponding bit in PDORn is cleared to logic 0
	T_ULONG PTOR; //Toggles (alterna) the logic levels that are driven on each GP output pin (0=Corresponding bit(Cb) in PDORn does not change; 1= Cb is set to the inverse)
	T_ULONG PDIR; //Captures the logic level that are driven into each GP input pin (0=logic 0 or not configured; 1= logic 1)
	T_ULONG PDDR; //configures individual por pins for input or output (0=input; 1=output)
	T_ULONG PIDR; //disables each GP pin from acting as an input (0=GP input; 1=not GP input)
}S_GPIO;

#define GPIO_PORTA_BASE_ADDRESS      0x400FF000
#define GPIO_PORTB_BASE_ADDRESS      0x400FF040
#define GPIO_PORTC_BASE_ADDRESS      0x400FF080
#define GPIO_PORTD_BASE_ADDRESS      0x400FF0C0
#define GPIO_PORTE_BASE_ADDRESS      0x400FF100

#define cps_PTA                     ((S_GPIO *)GPIO_PORTA_BASE_ADDRESS)
#define cps_PTB                     ((S_GPIO *)GPIO_PORTB_BASE_ADDRESS)
#define cps_PTC                     ((S_GPIO *)GPIO_PORTC_BASE_ADDRESS)
#define cps_PTD                     ((S_GPIO *)GPIO_PORTD_BASE_ADDRESS)
#define cps_PTE                     ((S_GPIO *)GPIO_PORTE_BASE_ADDRESS)

//PORT interface
typedef struct{
  T_ULONG PORT_PCR[32];//Pin control register //Configure each pin from the different ports (pag 172)
  T_ULONG PORT_GPCLR;
  T_ULONG PORT_GPCHR;
  T_ULONG PORT_GICLR;
  T_ULONG PORT_GICHR;
  T_ULONG PORT_ISFR;
  T_ULONG PORT_DFER;
  T_ULONG PORT_DFCR;
  T_ULONG PORTDFWR;
}S_PORT;

#define PORTA_BASE_ADDRESS         0x40049000
#define PORTB_BASE_ADDRESS         0x4004A000
#define PORTC_BASE_ADDRESS         0x4004B000
#define PORTD_BASE_ADDRESS         0x4004C000
#define PORTE_BASE_ADDRESS         0x4004D000

#define cps_PORTA         ((S_PORT *)PORTA_BASE_ADDRESS)
#define cps_PORTB         ((S_PORT *)PORTB_BASE_ADDRESS)
#define cps_PORTC         ((S_PORT *)PORTC_BASE_ADDRESS)
#define cps_PORTD         ((S_PORT *)PORTD_BASE_ADDRESS)
#define cps_PORTE         ((S_PORT *)PORTE_BASE_ADDRESS)

//PCC (Peripherial Clock Controller) pag 573
typedef struct {
                        T_ULONG RESERVED0[32];
  T_ULONG PCC_FTFC;
  T_ULONG PCC_DMAMUX;
                        T_ULONG RESERVED1[2];
  T_ULONG PCC_FlexCAN0;
  T_ULONG PCC_FlexCAN1;
  T_ULONG PCC_FTM3;
  T_ULONG PCC_ADC1;
                        T_ULONG RESERVED2[3];
  T_ULONG PCC_FlexCAN2;
  T_ULONG PCC_LPSPI0;
  T_ULONG PCC_LPSPI1;
  T_ULONG PCC_LPSPI2;
                        T_ULONG RESERVED3[2];
  T_ULONG PCC_PDB1;
  T_ULONG PCC_CRC;
                        T_ULONG RESERVED4[3];
  T_ULONG PCC_PDB0;
  T_ULONG PCC_LPIT;
  T_ULONG PCC_FTM0;
  T_ULONG PCC_FTM1;
  T_ULONG PCC_FTM2;
  T_ULONG PCC_ADC0;
                        T_ULONG RESERVED5;
  T_ULONG PCC_RTC;
                        T_ULONG RESERVED6[2];
  T_ULONG PCC_LPTMR0;
                        T_ULONG RESERVED7[8];
  T_ULONG PCC_PORTA; //pagina 605
  T_ULONG PCC_PORTB; //pagina 607
  T_ULONG PCC_PORTC; //pagina 608
  T_ULONG PCC_PORTD; //pagina 610
  T_ULONG PCC_PORTE; //pagina 611
                        T_ULONG RESERVED8[9];
  T_ULONG PCC_SAI0;
  T_ULONG PCC_SAI1;
                        T_ULONG RESERVED9[4];
  T_ULONG PCC_FlexIO;
                        T_ULONG RESERVED10[6];
  T_ULONG PCC_EWM;
                        T_ULONG RESERVED11[4];
  T_ULONG PCC_LPI2C0;
  T_ULONG PCC_LPI2C1;
                        T_ULONG RESERVED12[2];
  T_ULONG PCC_LPUART0;
  T_ULONG PCC_LPUART1;
  T_ULONG PCC_LPUART2;
                        T_ULONG RESERVED13;
  T_ULONG PCC_FTM4;
  T_ULONG PCC_FTM5;
  T_ULONG PCC_FTM6;
  T_ULONG PCC_FTM7;
                        T_ULONG RESERVED14;
  T_ULONG PCC_CMP0;
                        T_ULONG RESERVED15[2];
  T_ULONG PCC_QSPI;
                        T_ULONG RESERVED16[2];
  T_ULONG PCC_ENET;
} S_PCC;

#define PCC_BASE_ADDRESS   0x40065000 //pagina 573
#define cps_PCC            ((S_PCC *)PCC_BASE_ADDRESS)

//LPIT Low Power Periodic Interrupt Timer
typedef struct {
   T_ULONG VERID;                             /**< Versin ID Register, ffset: 0x0 */
   T_ULONG PARAM;                             /**< Parameter Register, ffset: 0x4 */
   T_ULONG MCR;                               /**< Mdule Cntrl Register, ffset: 0x8 */
   T_ULONG MSR;                               /**< Mdule Status Register, ffset: 0xC */
   T_ULONG MIER;                              /**< Mdule Interrupt Enable Register, ffset: 0x10 */
   T_ULONG SETTEN;                            /**< Set Timer Enable Register, ffset: 0x14 */
   T_ULONG CLRTEN;                            /**< Clear Timer Enable Register, ffset: 0x18 */
   	   	   	   	   T_UBYTE RESERVED_0[4];
  struct {                                         /* ffset: 0x20, array step: 0x10 */
	   T_ULONG TVAL;                              /**< Timer Value Register, array ffset: 0x20, array step: 0x10 */
	   T_ULONG CVAL;                              /**< Current Timer Value, array ffset: 0x24, array step: 0x10 */
	   T_ULONG TCTRL;                             /**< Timer Cntrl Register, array ffset: 0x28, array step: 0x10 */
	   	   	   	   T_UBYTE RESERVED_0[4];
  } TMR[4];
} S_LPIT;

#define LPIT_BASE_ADDRESS			 0x40037000u
#define cps_LPIT 					 ((S_LPIT *)LPIT_BASE_ADDRESS)

//SCG System Clock Generator
typedef struct {
    T_ULONG VERID;                             /**< Version ID Register, offset: 0x0 */
    T_ULONG PARAM;                             /**< Parameter Register, offset: 0x4 */
       T_UBYTE RESERVED_0[8];
    T_ULONG CSR;                               /**< Clock Status Register, offset: 0x10 */
    T_ULONG RCCR;                              /**< Run Clock Control Register, offset: 0x14 */
    T_ULONG VCCR;                              /**< VLPR Clock Control Register, offset: 0x18 */
    T_ULONG HCCR;                              /**< HSRUN Clock Control Register, offset: 0x1C */
    T_ULONG CLKOUTCNFG;                        /**< SCG CLKOUT Configuration Register, offset: 0x20 */
       T_UBYTE RESERVED_1[220];
    T_ULONG SOSCCSR;                           /**< System OSC Control Status Register, offset: 0x100 */
    T_ULONG SOSCDIV;                           /**< System OSC Divide Register, offset: 0x104 */
    T_ULONG SOSCCFG;                           /**< System Oscillator Configuration Register, offset: 0x108 */
    T_UBYTE RESERVED_2[244];
    T_ULONG SIRCCSR;                           /**< Slow IRC Control Status Register, offset: 0x200 */
    T_ULONG SIRCDIV;                           /**< Slow IRC Divide Register, offset: 0x204 */
    T_ULONG SIRCCFG;                           /**< Slow IRC Configuration Register, offset: 0x208 */
       T_UBYTE RESERVED_3[244];
   T_ULONG FIRCCSR;                           /**< Fast IRC Control Status Register, offset: 0x300 */
   T_ULONG FIRCDIV;                           /**< Fast IRC Divide Register, offset: 0x304 */
   T_ULONG FIRCCFG;                           /**< Fast IRC Configuration Register, offset: 0x308 */
       T_UBYTE RESERVED_4[756];
   T_ULONG SPLLCSR;                           /**< System PLL Control Status Register, offset: 0x600 */
   T_ULONG SPLLDIV;                           /**< System PLL Divide Register, offset: 0x604 */
   T_ULONG SPLLCFG;                           /**< System PLL Configuration Register, offset: 0x608 */
} S_SCG;

#define SCG_BASE_ADDRESS 			0x40064000u
#define cps_SCG						((S_SCG *)SCG_BASE_ADDRESS)



/* Exported Variables */
/*============================================================================*/


/* Exported functions prototypes */
/*============================================================================*/

#endif  /* Notice: the file ends with a blank new line to avoid compiler warnings */

