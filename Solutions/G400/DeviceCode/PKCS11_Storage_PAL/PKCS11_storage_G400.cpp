////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) Microsoft Corporation.  All rights reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////#include <Tinyhal.h>
#include "PKCS11_storage_G400.h"

//--//
BOOL  SecureStorage_G400::CreateFile( LPCSTR fileName , LPCSTR groupName, UINT32  fileType, UINT8* data, UINT32  dataLength )
{
    return FALSE;
}
BOOL  SecureStorage_G400::ReadFile( LPCSTR fileName , LPCSTR groupName, UINT32& fileType, UINT8* data, UINT32& dataLength )
{
    return FALSE;
}
BOOL  SecureStorage_G400::GetFileEnum( LPCSTR groupName, UINT32 fileType , FileEnumCtx& enumCtx )
{
    return FALSE;
}
BOOL  SecureStorage_G400::GetNextFile( FileEnumCtx& enumCtx, CHAR*fileName,UINT32 fileNameLen )
{
    return FALSE;
}
BOOL  SecureStorage_G400::Delete( LPCSTR fileName , LPCSTR groupName )
{
    return FALSE;
}

