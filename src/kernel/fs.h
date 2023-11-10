#pragma once

/************************************
 * INCLUDES
 ************************************/
#include "common/common.h"
#include "common/types.h"
#include "page.h"

/************************************
 * MACROS AND DEFINES
 ************************************/

/************************************
 * TYPEDEFS
 ************************************/
struct virtq_desc {
    uint64_t addr;
    uint32_t len;
    uint16_t flags;
    uint16_t next;
} __attribute__((packed));

struct virtq_avail {
    uint16_t flags;
    uint16_t index;
    uint16_t ring[VIRTQ_ENTRY_NUM];
} __attribute__((packed));

struct virtq_used_elem {
    uint32_t id;
    uint32_t len;
} __attribute__((packed));

struct virtq_used {
    uint16_t flags;
    uint16_t index;
    struct virtq_used_elem ring[VIRTQ_ENTRY_NUM];
} __attribute__((packed));

struct virtio_virtq {
    struct virtq_desc descs[VIRTQ_ENTRY_NUM];
    struct virtq_avail avail;
    struct virtq_used used __attribute__((aligned(PAGE_SIZE)));
    int queue_index;
    volatile uint16_t *used_index;
    uint16_t last_used_index;
} __attribute__((packed));

struct virtio_blk_req {
    uint32_t type;
    uint32_t reserved;
    uint64_t sector;
    uint8_t data[512];
    uint8_t status;
} __attribute__((packed));

/************************************
 * EXPORTED VARIABLES
 ************************************/

/************************************
 * GLOBAL FUNCTION PROTOTYPES
 ***********************************/
extern struct virtio_virtq *blk_request_vq;
extern struct virtio_blk_req *blk_req;
extern paddr_t blk_req_paddr;
extern unsigned blk_capacity;

uint32_t virtio_reg_read32(unsigned offset);
uint64_t virtio_reg_read64(unsigned offset);
void virtio_reg_write32(unsigned offset, uint32_t value);
void virtio_reg_fetch_and_or32(unsigned offset, uint32_t value);
void virtio_blk_init(void);
void virtq_kick(struct virtio_virtq *vq, int desc_index);
bool virtq_is_busy(struct virtio_virtq *vq);
void read_write_disk(void *buf, unsigned sector, int is_write);