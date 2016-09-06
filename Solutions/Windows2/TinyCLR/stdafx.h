////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) Microsoft Corporation.  All rights reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define _WIN32_WINNT 0x0501

#include <windows.h>

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <vcclr.h>

////////////////////////////////////////////////////////////////////////////////////////////////////

#include <wininet.h>
#include <process.h>
#include <tchar.h>
#include <process.h>
#include <vector>
#include <list>
#include <queue>

#include <cor.h>
#include <corhdr.h>
#include <corhlpr.h>

////////////////////////////////////////////////////////////////////////////////////////////////////


#include <TinyCLR_Application.h>
#include <TinyCLR_Win32.h>
#include <TinyCLR_ErrorCodes.h>
#include <TinyCLR_Interop.h>

#include "EmulatorNative.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

#define BOOL_TO_INT(f) ((f) ? 1 : 0)
#define INT_TO_BOOL(f) ((f) ? true : false)

