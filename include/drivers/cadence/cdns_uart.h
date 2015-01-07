/*
 * Copyright (c) 2014, Xilinx Inc.
 * Written by Edgar E. Iglesias.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * Neither the name of ARM nor the names of its contributors may be used
 * to endorse or promote products derived from this software without specific
 * prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef __CADENCE_UART_H__
#define __CADENCE_UART_H__

/* This is very minimalistic and will only work in QEMU.  */

/* CADENCE Registers */
#define R_UART_CR	(0x00)
#define R_UART_CR_TX_EN	0x00000010 /* TX enabled */
#define R_UART_CR_RX_EN	0x00000004 /* RX enabled */
#define R_UART_CR_TXRST	0x00000002 /* TX logic reset */
#define R_UART_CR_RXRST	0x00000001 /* RX logic reset */

#define R_UART_MR	(0x04)
#define R_UART_MR_PARITY_NONE	0x00000020  /* No parity mode */

#define R_UART_IER	(0x08)
#define R_UART_IDR	(0x0C)
#define R_UART_IMR	(0x10)
#define R_UART_CISR	(0x14)
#define R_UART_BRG	(0x18)
#define R_UART_RTRIG	(0x20)
#define R_UART_SR	(0x2C)
#define UART_SR_INTR_RTRIG	0x00000001
#define UART_SR_INTR_REMPTY	0x00000002
#define UART_SR_INTR_TEMPTY	0x00000008
#define UART_SR_INTR_TFUL	0x00000010

#define R_UART_TX	(0x30)
#define R_UART_RX	(0x30)
#define R_UART_BRD	(0x34)

#ifndef __ASSEMBLY__
void cadence_serial_setbrg(uint32_t base, uint32_t clock, uint32_t baudrate);
#endif

#endif
