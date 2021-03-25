/* ArithmeticExceptionThrower.h
 * 
 * Author           : Alexander J. Yee
 * Date Created     : 05/05/2017
 * Last Modified    : 05/05/2017
 * 
 *      Lightweight header. Use this if you only need to throw and you don't
 *  want to pull in all the headers that "Exception.h" pulls in.
 * 
 */

#pragma once
#ifndef ymp_Exceptions_ArithmeticExceptionThrower_H
#define ymp_Exceptions_ArithmeticExceptionThrower_H
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//  Dependencies
#include "PublicLibs/CompilerSettings.h"
#include "PublicLibs/Types.h"
namespace ymp{
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
[[noreturn]] YM_NO_INLINE void throw_ExponentOverflowException(const char* function, siL_t value, siL_t limit);
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
YM_FORCE_INLINE void check_FloatExponentOverflow(const char* function, siL_t exp){
    const siL_t MAX = ((siL_t)1 << (INDEX_BITS - 3)) - 1;
    const siL_t MIN = 1 - ((siL_t)1 << (INDEX_BITS - 3));
    if (exp < MIN){
        throw_ExponentOverflowException(function, exp, MIN);
    }
    if (exp > MAX){
        throw_ExponentOverflowException(function, exp, MAX);
    }
}
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
}
#endif
