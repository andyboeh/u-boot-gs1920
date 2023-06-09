#ifndef PBLR_H
#define PBLR_H

#define _sizeof_nand_dma_buf(max_chunk_size) (sizeof(nand_dma_buf_t)+(max_chunk_size))

// the function to export to u-boot


#define parameters sram_parameters

#define parameter_soc_rwp   ((soc_t*)(&(parameters.soc)))
#define para_flash_info     (parameters.soc.flash_info)
#define para_ddr_info       (parameters.soc.dram_info)
#define para_pll_info       (parameters.soc.pll_info)
#define pblr_printf         (parameters._pblr_printf)
#define pblr_nor_spi_erase  (parameters._nor_spi_erase)
#define pblr_nor_spi_read   (parameters._nor_spi_read)
#define pblr_nor_spi_write  (parameters._nor_spi_write)
#define pblr_dc_flushall    (parameters._dcache_writeback_invalidate_all)

#if 0
#define flash_info_num_chunk_per_block	  \
	((para_flash_info.num_page_per_block)/(para_flash_info.page_per_chunk))
#endif

#define soc_configuration (*(const soc_configuration_t*)(SYSTEM_STARTUP_CADDR+SOC_CONF_OFFSET))
// the table is stored just right after the first cache line the lplr

inline static void
_set_flags(u32_t *arr, u32_t i) {
	unsigned idx=i/(8*sizeof(u32_t));
	i &= (8*sizeof(u32_t))-1;
	arr[idx] |= 1UL << i;
}
inline static int
_get_flags(u32_t *arr, u32_t i) {
	unsigned idx=i/(8*sizeof(u32_t));
	i &= (8*sizeof(u32_t))-1;
	return (arr[idx] & (1UL << i)) != 0;
}

inline static void
pblr_bset(void *buf,u8_t value, u32_t nbyte) {
	u8_t *b=(u8_t *)buf;
	u8_t *e=b+nbyte;
    while (b!=e) *(b++)=value;
}

inline static void
pblr_bzero(void *buf, u32_t nbyte) {
    //u8_t *b=(u8_t *)buf;
    //u8_t *e=b+nbyte;
    //while (b!=e) *(b++)=0;
    pblr_bset(buf,0,nbyte);
    
}

inline static void
pbldr_wzero(void *buf, u32_t nword) {
	u32_t *b=(u32_t *)buf;
	u32_t *e=b+nword;
	while (b!=e) *(b++)=0;
}
inline static void
pbldr_wzero_range(u32_t *buf, u32_t *buf_end) {
	while (buf!=buf_end) *(buf++)=0;
}

inline static void
_pblr_memcpy(void *dst, const void *src, u32_t nbyte) {
	u8_t *d=(u8_t*)dst;
	const u8_t *s=(const u8_t *)src;
	const u8_t *e=s+nbyte;
	while (s!=e) *(d++)=*(s++);
}
inline static void
pblr_wmemcpy(void *dst, const void *src, u32_t nword) {
	u32_t *d=(u32_t*)dst;
	const u32_t *s=(const u32_t *)src;
	const u32_t *e=s+nword;
	while (s!=e) *(d++)=*(s++);
}
inline static int
pblr_memcmp(const void *a, const void *b, u32_t nbyte) {
	const u8_t *x=a;
	const u8_t *y=b;
	const u8_t *z=x+nbyte;
	while (x!=z)
		if (*(x++)!=*(y++))
			return -1;
	return 0;
}
inline static int
pblr_wmemcmp(const void *a, const void *b, u32_t nword) {
	const u32_t *x=a;
	const u32_t *y=b;
	const u32_t *z=x+nword;
	while (x!=z)
		if (*(x++)!=*(y++))
			return -1;
	return 0;
}

// return 0: successful
inline static int
check_if_all_one(u32_t *flags_arr, u32_t n) {
	int c;
	for (c=n;c>=0;c--)
		if (_get_flags(flags_arr, c)==0) return -1;
	return 0;
}
inline static u8_t*
plr_addr_by_chunck_id(u32_t cid, u32_t chunk_size) {
	return (u8_t*)SYSTEM_STARTUP_CADDR+LPLR_DMA_SIZE+cid*chunk_size;
}
inline static u8_t*
blr_addr_by_chunck_id(u32_t cid, u32_t chunk_size) {
	return (u8_t*)DRAM_CADDR+cid*chunk_size;
}

#if 0
inline static void
pbldr_dma_cache_inv_range(void *addr, u32_t nbyte) {
	parameters._dcache_flush_inv_range(addr,addr+nbyte-1);

}
#endif


#endif //PBLR_H
