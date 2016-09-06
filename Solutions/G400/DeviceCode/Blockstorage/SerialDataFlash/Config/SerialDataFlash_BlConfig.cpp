////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
// 
// This file is part of the Microsoft .NET Micro Framerwork Porting Kit Code Samples and is unsupported. 
// Copyright (C) Microsoft Corporation. All rights reserved. Use of this sample source code is subject to 
// the terms of the Microsoft license agreement under which you licensed this sample source code. 
// 
// THIS SAMPLE CODE AND INFORMATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESSED OR IMPLIED, 
// INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
// 
//
// Portions Copyright (c) GHI Electronics, LLC.
// 
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <tinyhal.h>
#include "..\SerialDataFlash.h"

#define FLASH_MANUFACTURER_CODE                 0x1F
#define FLASH_DEVICE_CODE                       0x27

// Each page is 512/528 bytes. Each block is 8 pages. Each sector is 128 pages or 16 blocks. Each chip has 64 sectors or 1024 blocks.
// However, NETMF uses the word sector for page. Therefore, each sector is 512/528 bytes and each block is 8 sectors.

#define FLASH_BASE_ADDRESS                      0x00000000
#define FLASH_BLOCK_COUNT                       512
#define FLASH_SECTOR_PER_BLOCK                  16
#define FLASH_SECTOR_SIZE                       528
#define FLASH_BLOCK_SIZE                        (FLASH_SECTOR_PER_BLOCK * FLASH_SECTOR_SIZE)
#define FLASH_BLOCK_ERASE_TYPICAL_TIME_USEC     15000 // <-Set for the time for a page/sector erase. || This is for block erase-> 45000
#define FLASH_SECTOR_WRITE_TYPICAL_TIME_USEC    3000 // This is with erase included -> 17000
#define FLASH_BLOCK_ERASE_MAX_TIME_USEC         35000 // <-Set for the time for a page/sector erase. || This is for block erase-> 100000
#define FLASH_SECTOR_WRITE_MAX_TIME_USEC        6000 // This is with erase included -> 40000

#define FLASH_SIZE                              0x400000 // 4 MB
#define SerialDataFlash_SIZE_IN_BYTES           (FLASH_BLOCK_SIZE * FLASH_BLOCK_COUNT)
#define SerialDataFlash_WP_GPIO_PIN             GPIO_PIN_NONE
#define SerialDataFlash_WP_ACTIVE               FALSE


// BlockDeviceInformation

#define BLOCK_DEVICE_INFO_REMOVEABLE            FALSE
#define BLOCK_DEVICE_INFO_SUPPORTXIP            FALSE
#define BLOCK_DEVICE_INFO_WRITEPROTECTED        FALSE
#define BLOCK_DEVICE_INFO_SUPPORTSCOPYBACK      FALSE
#define SerialDataFlash_NUMREGIONS              1


#ifdef MEMORY_USAGE_SPECIAL
#undef MEMORY_USAGE_SPECIAL
#endif

#ifdef MEMORY_USAGE_SPECIAL2
#undef MEMORY_USAGE_SPECIAL2
#endif

#ifdef MEMORY_USAGE_SPECIAL3
#undef MEMORY_USAGE_SPECIAL3
#endif

#if defined(MEMORY_USAGE_GCC_SPECIAL_CODE)
#undef MEMORY_USAGE_GCC_SPECIAL_CODE
#endif

#ifdef __GNUC__
#define MEMORY_USAGE_GCC_SPECIAL_BOOTSTRAP  BlockStatus::USAGE_BOOTSTRAP
#define MEMORY_USAGE_GCC_SPECIAL_CONFIG     BlockStatus::USAGE_CONFIG
#else
#define MEMORY_USAGE_GCC_SPECIAL_BOOTSTRAP  BlockStatus::USAGE_CONFIG
#define MEMORY_USAGE_GCC_SPECIAL_CONFIG     BlockStatus::USAGE_CODE
#endif



const BlockRange g_SerialDataFlash_BlockStatus[] =
{
    { BlockRange::BLOCKTYPE_BOOTSTRAP,     0,    3 }, // For GHI Loader
    { BlockRange::BLOCKTYPE_BOOTSTRAP,     4,   15 }, // For TinyBooter
    { BlockRange::BLOCKTYPE_RESERVED,     16,  311 }, // For TinyCLR
    { BlockRange::BLOCKTYPE_CODE,        312,  319 },
    { BlockRange::BLOCKTYPE_DEPLOYMENT,  320,  494 }, // Aproximately 1.25 MB User Deployment
    { BlockRange::BLOCKTYPE_STORAGE_A,   495,  502 }, // 64 KB Extended Weak Reference
    { BlockRange::BLOCKTYPE_STORAGE_B,   503,  510 }, // 64 KB Extended Weak Reference
    { BlockRange::BLOCKTYPE_CONFIG,      511,  511 }  // 1 Block = 8 KB (16 * 528)
};

const BlockRegionInfo g_SerialDataFlash_BlkRegion[SerialDataFlash_NUMREGIONS] = 
{
    FLASH_BASE_ADDRESS,             // ByteAddress  Start;              // Starting Sector address
    FLASH_BLOCK_COUNT,              // UINT32       NumBlocks;          // total number of blocks in this region
    FLASH_BLOCK_SIZE,               // UINT32       BytesPerBlock;      // Total number of bytes per block (MUST be SectorsPerBlock * DataBytesPerSector)

    ARRAYSIZE_CONST_EXPR(g_SerialDataFlash_BlockStatus),  // NumBlockRanges
    g_SerialDataFlash_BlockStatus, // BlockRanges
};


#undef MEMORY_USAGE_GCC_SPECIAL_CODE


BlockDeviceInfo g_SerialDataFlash_DeviceInfo =
{
    {
        BLOCK_DEVICE_INFO_REMOVEABLE,
        BLOCK_DEVICE_INFO_SUPPORTXIP,
        BLOCK_DEVICE_INFO_WRITEPROTECTED,
        BLOCK_DEVICE_INFO_SUPPORTSCOPYBACK,
    },

    FLASH_SECTOR_WRITE_MAX_TIME_USEC,       // UINT32 Duration_Max_WordWrite_uSec;
    FLASH_BLOCK_ERASE_MAX_TIME_USEC,        // UINT32 Duration_Max_SectorErase_uSec;
    FLASH_SECTOR_SIZE,
    FLASH_SIZE,
    ARRAYSIZE_CONST_EXPR(g_SerialDataFlash_BlkRegion),  // UINT32 NumRegions;
    g_SerialDataFlash_BlkRegion,            // const BlockRegionInfo* pRegions;
};


struct BLOCK_CONFIG g_SerialDataFlash_BS_Config =
{
    {
        SerialDataFlash_WP_GPIO_PIN,        // GPIO_PIN Pin;
        SerialDataFlash_WP_ACTIVE,          // BOOL     ActiveState;
    },

    &g_SerialDataFlash_DeviceInfo,          // BlockDeviceinfo
};


extern struct IBlockStorageDevice g_SerialDataFlash_BS_DeviceTable;

struct BlockStorageDevice g_SerialDataFlash_BS;

struct SerialDataFlash_BS_Driver g_SerialDataFlash_BS_Driver;

