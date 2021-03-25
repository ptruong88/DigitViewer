/* ToString.h - Conversions to Strings
 * 
 * Author           : Alexander J. Yee
 * Date Created     : 07/07/2013
 * Last Modified    : 08/24/2014
 * 
 */

#pragma once
#ifndef ymp_ToString_H
#define ymp_ToString_H
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//  Dependencies
#include <string>
#include "PublicLibs/CompilerSettings.h"
#include "PublicLibs/Types.h"
namespace ymp{
namespace StringTools{
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
enum NumberFormat{
    NORMAL = 0,
    COMMAS = 1,
    BYTES = 2,
    BYTES_EXPANDED = 3
};
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//  Integer
YM_NO_INLINE    std::string tostr       (uiL_t x, NumberFormat format = NORMAL);
YM_NO_INLINE    std::string tostr       (siL_t x, NumberFormat format = NORMAL);
static          std::string tostr       (u32_t x, NumberFormat format = NORMAL){ return tostr((uiL_t)x, format); }
static          std::string tostr       (s32_t x, NumberFormat format = NORMAL){ return tostr((siL_t)x, format); }
YM_NO_INLINE    std::string tostrln     (uiL_t x, NumberFormat format = NORMAL);
YM_NO_INLINE    std::string tostrln     (siL_t x, NumberFormat format = NORMAL);
static          std::string tostrln     (u32_t x, NumberFormat format = NORMAL){ return tostrln((uiL_t)x, format); }
static          std::string tostrln     (s32_t x, NumberFormat format = NORMAL){ return tostrln((siL_t)x, format); }
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//  Float
YM_NO_INLINE    std::string tostr_float     (double x, int precision = 0);
YM_NO_INLINE    std::string tostrln_float   (double x, int precision = 0);
YM_NO_INLINE    std::string tostr_fixed     (double x, int precision = 3);
YM_NO_INLINE    std::string tostrln_fixed   (double x, int precision = 3);
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
}
}
#endif
