/*
 * (C) Copyright 2003
 * Texas Instruments.
 * Kshitij Gupta <kshitij@ti.com>
 * Configuation settings for the TI OMAP H3 board.
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#ifndef __CONFIG_H
#define __CONFIG_H

//#define CFG_NAND_BOOT

/*
 * If we are developing, we might want to start armboot from ram
 * so we MUST NOT initialize critical regs like mem-timing ...
 */
//#define CONFIG_INIT_CRITICAL            /* undef for developing */

/*
 * High Level Configuration Options
 * (easy to change)
 */
#define CONFIG_ARM926EJS	1	/* This is an arm926ejs CPU core  */
#define CONFIG_OMAP	1			/* in a TI OMAP core    */
#define CONFIG_OMAP1710	1		/* which is in a 1710  */
#define CONFIG_H3_OMAP1710	1	/*  a H3 Board  */

/* input clock of PLL */
/* the OMAP1710 H3 has 12MHz input clock */
#define CONFIG_SYS_CLK_FREQ	12000000

#undef CONFIG_USE_IRQ	/* we don't need IRQ/FIQ stuff */

#define CONFIG_MISC_INIT_R

#define CONFIG_CMDLINE_TAG	1	/* enable passing of ATAGs  */
#define CONFIG_SETUP_MEMORY_TAGS	1

/*
 * Size of malloc() pool
 */
#define CFG_MALLOC_LEN	(CFG_ENV_SIZE + 128*1024)
#define CFG_GBL_DATA_SIZE	128	/* size in bytes reserved for initial data */

/*
 * Hardware drivers
 */
/*
*/
#define CONFIG_DRIVER_LAN91C96
#define CONFIG_LAN91C96_BASE 0x04000300
#define CONFIG_LAN91C96_EXT_PHY

/*
 * NS16550 Configuration
 */
#define CFG_NS16550
#define CFG_NS16550_SERIAL
#define CFG_NS16550_REG_SIZE	(-4)
#define CFG_NS16550_CLK		(48000000)	/* can be 12M/32Khz or 48Mhz */
#define CFG_NS16550_COM1	0xfffb0000	/* uart1, bluetooth uart on helen */

/*
 * select serial console configuration
 */
#define CONFIG_SERIAL1		1		/* we use SERIAL 1 on OMAP1710 H3 */

/* allow to overwrite serial and ethaddr */
#define CONFIG_ENV_OVERWRITE
#define CONFIG_CONS_INDEX	1
#define CONFIG_BAUDRATE	115200
#define CFG_BAUDRATE_TABLE	{ 9600, 19200, 38400, 57600, 115200 }

#define CONFIG_COMMANDS	(CONFIG_CMD_DFL | CFG_CMD_DHCP | CFG_CMD_NAND | CFG_CMD_JFFS2)
#define CONFIG_BOOTP_MASK	CONFIG_BOOTP_DEFAULT

/* this must be included AFTER the definition of CONFIG_COMMANDS (if any) */
#include <cmd_confdefs.h>
#include <configs/omap1510.h>


/*
 *  Board NAND Info.
 */
#ifdef CFG_NAND_BOOT
#define CFG_NAND_ADDR 0x0c000000  /* physical address to access nand at CS3*/
#else
#define CFG_NAND_ADDR 0x0a000000  /* physical address to access nand at CS2B*/
#endif

#define CONFIG_H3_NAND_16BIT

#define CFG_MAX_NAND_DEVICE 1	/* Max number of NAND devices */
#define SECTORSIZE          512

#define ADDR_COLUMN         1          
#define ADDR_PAGE           2             
#define ADDR_COLUMN_PAGE    3

#define NAND_ChipID_UNKNOWN 0x00
#define NAND_MAX_FLOORS     1
#define NAND_MAX_CHIPS      1

#define WRITE_NAND_COMMAND(d, adr) do{ *(volatile __u8 *)((unsigned long)adr + 2) = (__u8)(d); } while(0)
#define WRITE_NAND_ADDRESS(d, adr) do{ *(volatile __u8 *)((unsigned long)adr + 4) = (__u8)(d); } while(0)
#define WRITE_NAND(d, adr) do{ *(volatile __u16 *)((unsigned long)adr) = (__u16)(d); } while(0)
#define READ_NAND(adr) ((volatile __u16)(*(volatile __u16 *)(unsigned long)adr))

#define NAND_NO_RB          1
#define NAND_WAIT_READY(nand) udelay(35)

#define NAND_CTL_CLRALE(nandptr) udelay(1);  
#define NAND_CTL_SETALE(nandptr) udelay(1);  
#define NAND_CTL_CLRCLE(nandptr) udelay(1);       
#define NAND_CTL_SETCLE(nandptr) udelay(1);       
#define NAND_DISABLE_CE(nand)    udelay(1);  
#define NAND_ENABLE_CE(nand)     udelay(1);  

 
#define CONFIG_BOOTDELAY	3
#define CONFIG_BOOTARGS	"mem=32M console=ttyS0,115200n8 noinitrd \
				root=/dev/nfs rw nfsroot=157.87.82.48:\
				/home/a0875451/mwd/myfs/target ip=dhcp"
#define CONFIG_NETMASK	255.255.254.0	/* talk on MY local net */
#define CONFIG_IPADDR	156.117.97.156	/* static IP I currently own */
#define CONFIG_SERVERIP	156.117.97.139	/* current IP of my dev pc */
#define CONFIG_BOOTFILE	"uImage"	/* file to load */

#if (CONFIG_COMMANDS & CFG_CMD_KGDB)
#define CONFIG_KGDB_BAUDRATE	115200	/* speed to run kgdb serial port */
#define CONFIG_KGDB_SER_INDEX	1	/* which serial port to use */
#endif

/*
 * Miscellaneous configurable options
 */
#define CFG_LONGHELP	/* undef to save memory     */
#define CFG_PROMPT	"OMAP1710 H3 # "	/* Monitor Command Prompt   */
#define CFG_CBSIZE	256		/* Console I/O Buffer Size  */
/* Print Buffer Size */
#define CFG_PBSIZE	(CFG_CBSIZE+sizeof(CFG_PROMPT)+16)
#define CFG_MAXARGS	16		/* max number of command args   */
#define CFG_BARGSIZE	CFG_CBSIZE	/* Boot Argument Buffer Size    */

#define CFG_MEMTEST_START	0x10000000	/* memtest works on */
#define CFG_MEMTEST_END	0x12000000	/* 32 MB in DRAM    */

#undef	CFG_CLKS_IN_HZ		/* everything, incl board info, in Hz */

#define CFG_LOAD_ADDR	0x10000000	/* default load address */

/* The 1710 has 6 timers, they can be driven by the RefClk (12Mhz) or by
 * DPLL1. This time is further subdivided by a local divisor.
 */
#define CFG_TIMERBASE	0xFFFEC500	/* use timer 1 */
#define CFG_PVT	7	/* 2^(pvt+1), divide by 256 */
#define CFG_HZ	((CONFIG_SYS_CLK_FREQ)/(2 << CFG_PVT))

/*-----------------------------------------------------------------------
 * Stack sizes
 *
 * The stack sizes are set up in start.S using the settings below
 */
#define CONFIG_STACKSIZE	(128*1024)	/* regular stack */
#ifdef CONFIG_USE_IRQ
#define CONFIG_STACKSIZE_IRQ	(4*1024)	/* IRQ stack */
#define CONFIG_STACKSIZE_FIQ	(4*1024)	/* FIQ stack */
#endif

/*-----------------------------------------------------------------------
 * Physical Memory Map
 */
#define CONFIG_NR_DRAM_BANKS	1	/* we have 1 bank of DRAM */
#define PHYS_SDRAM_1	0x10000000	/* SDRAM Bank #1 */
#define PHYS_SDRAM_1_SIZE	0x02000000	/* 32 MB */

#ifdef CFG_NAND_BOOT
#define PHYS_FLASH_1	0x0a000000	/* Flash Bank #1 */
#else
#define PHYS_FLASH_1	0x00000000	/* Flash Bank #1 */
#endif

#define CFG_FLASH_BASE	PHYS_FLASH_1

/*-----------------------------------------------------------------------
 * FLASH and environment organization
 */
#define CFG_MAX_FLASH_BANKS	1	/* max number of memory banks */
#define PHYS_FLASH_SIZE	0x02000000	/* 32MB */
#define CFG_MAX_FLASH_SECT	(259)	/* max number of sectors on one chip */

/* timeout values are in ticks */
#define CFG_FLASH_ERASE_TOUT	(25*CFG_HZ)	/* Timeout for Flash Erase */
#define CFG_FLASH_WRITE_TOUT	(25*CFG_HZ)	/* Timeout for Flash Write */

#ifdef CFG_NAND_BOOT

#define CFG_ENV_IS_IN_NAND	1
#define CFG_ENV_SIZE	0x20000	/* Total Size of Environment Sector */
#define CFG_ENV_OFFSET	0x50000	/* environment starts here  */

#else
/* addr of environment */
#define CFG_ENV_ADDR	(CFG_FLASH_BASE + 0x020000)

#define CFG_ENV_IS_IN_FLASH	1
#define CFG_ENV_SIZE	0x20000	/* Total Size of Environment Sector */
#define CFG_ENV_OFFSET	0x20000	/* environment starts here  */

#endif     /* CFG_NAND_BOOT */

/* Flash banks JFFS2 should use */
#define CFG_MAX_MTD_BANKS	(CFG_MAX_FLASH_BANKS+CFG_MAX_NAND_DEVICE)
#define CFG_JFFS2_MEM_NAND
#define CFG_JFFS2_FIRST_BANK	1		/* use flash_info[1] */
#define CFG_JFFS2_NUM_BANKS     1

#endif							/* __CONFIG_H */
