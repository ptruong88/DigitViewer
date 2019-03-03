/* Globals.h - DigitViewer Globals
 * 
 * Author           : Alexander J. Yee
 * Date Created     : 07/31/2013
 * Last Modified    : 08/03/2013
 * 
 */

#pragma once
#ifndef ydv_DigitViewer_Globals_H
#define ydv_DigitViewer_Globals_H
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//  Dependencies
#include "PublicLibs/Types.h"
namespace DigitViewer2{
    using namespace ymp;
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
const char VERSION[] = "y-cruncher Digit Viewer v2.5.312";
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
const upL_t MIN_COMPRESS_DIGITS = 1000000;
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//  File Tokens
const char YCF_CDF_FileVersion[]        =   "1.1.0";
const char YCF_CDF_TOKEN_FileVersion[]  =   "FileVersion:";
const char YCF_CDF_TOKEN_Base[]         =   "Base:";
const char YCF_CDF_TOKEN_FirstDigits[]  =   "FirstDigits:";
const char YCF_CDF_TOKEN_TotalDigits[]  =   "TotalDigits:";
const char YCF_CDF_TOKEN_BlockSize[]    =   "Blocksize:";
const char YCF_CDF_TOKEN_TotalBlocks[]  =   "TotalBlocks:";
const char YCF_CDF_TOKEN_BlockID[]      =   "BlockID:";
const char YCF_CDF_TOKEN_EndHeader[]    =   "EndHeader";
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//  Errors
#define YCR_DIO_ERROR_INVALID_PARAMETERS        (int)0x80000001

#define YCR_DIO_ERROR_INVALID_FILE              (int)0x80001000
#define YCR_DIO_ERROR_INVALID_NAME              (int)0x80001001
#define YCR_DIO_ERROR_INVALID_EXTENSION         (int)0x80001002
#define YCR_DIO_ERROR_INVALID_BASE              (int)0x80001003
#define YCR_DIO_ERROR_UNEXPECTED_END_OF_FILE    (int)0x80001004
#define YCR_DIO_ERROR_NO_DECIMAL_PLACE          (int)0x80001005
#define YCR_DIO_ERROR_INVALID_DIGIT             (int)0x80001006
#define YCR_DIO_ERROR_MAXIMUM_PATHS_EXCEEDED    (int)0x80001007

#define YCR_DIO_ERROR_INCONSISTENT              (int)0x80002000
#define YCR_DIO_ERROR_INCONSISTENT_ID           (int)0x80002001
#define YCR_DIO_ERROR_INCONSISTENT_BASE         (int)0x80002002
#define YCR_DIO_ERROR_INCONSISTENT_DIGITS       (int)0x80002003

#define YCR_DIO_ERROR_INTERNAL                  (int)0x80004000
#define YCR_DIO_ERROR_INVALID_FILE_STATE        (int)0x80004001
#define YCR_DIO_ERROR_FILE_NOT_FOUND            (int)0x80004002
#define YCR_DIO_ERROR_CREATE_FAIL               (int)0x80004003
#define YCR_DIO_ERROR_OPEN_FAIL                 (int)0x80004004
#define YCR_DIO_ERROR_READ_FAIL                 (int)0x80004005
#define YCR_DIO_ERROR_WRITE_FAIL                (int)0x80004006
#define YCR_DIO_ERROR_MISSING_FILES             (int)0x80004007
#define YCR_DIO_ERROR_OUT_OF_RANGE              (int)0x80004008

#define YCR_DIO_ERROR_NO_DIGITS_LEFT            (int)0x80008001
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
}
#endif
