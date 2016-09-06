////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) Microsoft Corporation.  All rights reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "tinyhal.h" 
#include "dhcpcapi.h"

#ifndef _AT91_EMAC_ADAPTER_H_1
#define _AT91_EMAC_ADAPTER_H_1 1

extern int xn_bind_at91_mac(int minor_number);

// Data Structures
struct AT91_EMAC_DRIVER_CONFIG
{
    GPIO_PIN            PHY_PD_GPIO_Pin;			// phy power down control
};

struct AT91_EMAC_Driver
{
    int m_interfaceNumber;
    DHCP_session m_currentDhcpSession;

    //--//

    static int  Open   (   void          );
    static BOOL Close  (   void          );
    static BOOL Bind   (   void          );
};

//
// AT91_EMAC_ADAPTER
//////////////////////////////////////////////////////////////////////////////

#endif
