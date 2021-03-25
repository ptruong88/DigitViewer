/* WordToRaw.h
 * 
 * Author           : Alexander J. Yee
 * Date Created     : 02/12/2018
 * Last Modified    : 02/12/2018
 * 
 */

#pragma once
#ifndef ydv_DigitViewer_WordToRaw_H
#define ydv_DigitViewer_WordToRaw_H
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//  Dependencies
#include "PublicLibs/Types.h"
namespace DigitViewer2{
namespace WordToRaw{
    using namespace ymp;
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void word_to_hex(char* raw, const u32_t* T, upL_t words);
void word_to_dec(char* raw, const u32_t* T, upL_t words);
void word_to_hex(char* raw, const u64_t* T, upL_t words);
void word_to_dec(char* raw, const u64_t* T, upL_t words);
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
}
}
#endif
