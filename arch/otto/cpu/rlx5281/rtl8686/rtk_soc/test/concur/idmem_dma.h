
#define TO_UNCACHED_ADDR(addr) ((unsigned int)(addr) | (0x20000000))
#define TO_CACHED_ADDR(addr) ((unsigned int)(addr) & (0xDFFFFFFF))
#define REG(reg)                      (*((volatile unsigned int *)(reg)))


#ifdef CONFIG_RTL8198
//	#define IMEM_DMEM_DMA_BASE 0xB800B800
	#define IMEM_DMEM_DMA_BASE 0xB8006000
	#define IMEMDMEM_L2MEM_SLE(a) ((a) << 23)
	#define ACCEL_SLE(a) ((a) << 22)
	#define IMEMDMEM_SREST (1 << 21)
	#define IMEMDMEM_START (1 << 20)
	#define DIRECTION_SEL(a) ((a) << 19)
	#define TRAN_SIZE_INWORDS(a) (((a) >> 2 ) % 0x00040000)
#endif
#ifdef CONFIG_RTL8196
	#define IMEM_DMEM_DMA_BASE 0xB800B800
	#define IMEMDMEM_SREST (1 << 15)
	#define IMEMDMEM_START (1 << 14)
	#define DIRECTION_SEL(a) ((a) << 13)
	#define TRAN_SIZE_INWORDS(a) (((a) >> 2 ) & 0x00001fff)
#endif

#define IMEM_DMEM_SA_REG (IMEM_DMEM_DMA_BASE+0)
#define EXTM_SA_REG (IMEM_DMEM_DMA_BASE+4)
#define DMDMA_CTL_REG (IMEM_DMEM_DMA_BASE+8)


#define SEL_IMEM0 0
#define SEL_IMEM1 1
#define SEL_DMEM0 2
#define SEL_DMEM1 3
#define SEL_L2MEM 4

#define IMEM_DMEM_ADDR_OF(a) ((a) >> 2)
#define EXTM_SA_OF(a) ((a) & 0x1ffffffc)
#define DIR_IMEMDMEM_TO_SDRAM 0
#define DIR_SDRAM_TO_IMEMDMEM 1
#define STORE_FORWARD_MODE 0
#define ACCELERATION_MODE  1
#define MODE_MAXNUM ACCELERATION_MODE

#define IDMEM_KICKOFF(kick_value)       (*((volatile unsigned int *)(DMDMA_CTL_REG)) = (unsigned int)kick_value)

#define POLLING_IMEM_DMEM_DMA  while((REG(DMDMA_CTL_REG)&IMEMDMEM_START));
/*
sdram_addr: 
	External memory address. (virtual address)
mem_addr:   
	Mirrored IMEM/DMEM address. (virtual address)
mem_base:   
	Mirrored MEM/DMEM base address. (virtual address)
size:	    
	The number of words to be transfered.
direction:
	DIR_IMEMDMEM_TO_SDRAM, transfer data from IMEM/DMEM to SDRAM.
	DIR_SDRAM_TO_IMEMDMEM, transfer data from SDRAM to IMEM/DMEM.
target:
	SEL_IMEM0, Choose IMEM0 to be the target memory.
	SEL_IMEM1, Choose IMEM1 to be the target memory.
	SEL_DMEM0, Choose DMEM0 to be the target memory.
	SEL_DMEM1, Choose DMEM1 to be the target memory.
	SEL_L2MEM, Choose L2MEM to be the target memory.
*/
unsigned int setImemDmemDMA(unsigned int sdram_addr, unsigned int mem_addr, unsigned int mem_base,\
		 unsigned int byte_size, unsigned int direction, unsigned int target, unsigned int mode);
