/* SizeOf.h
 * 
 * Author           : Alexander J. Yee
 * Date Created     : 05/06/2017
 * Last Modified    : 05/06/2017
 * 
 *      This is incredibly stupid.
 * 
 */

#pragma once
#ifndef ymp_TemplateTools_SizeOf_H
#define ymp_TemplateTools_SizeOf_H
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
#include "PublicLibs/Types.h"
namespace ymp{
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
template <typename T>
struct SizeOf{
    static const upL_t value = sizeof(T);
};
template <>
struct SizeOf<const void>{
    static const upL_t value = 1;
};
template <>
struct SizeOf<void>{
    static const upL_t value = 1;
};
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
}
#endif