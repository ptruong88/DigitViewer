/* DigitCounts.cpp
 * 
 * Author           : Alexander J. Yee
 * Date Created     : 01/13/2018
 * Last Modified    : 01/13/2018
 * 
 */

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//  Dependencies
#include <string.h>
#include <vector>
#include "PublicLibs/Exceptions/InvalidParametersException.h"
#include "PublicLibs/SystemLibs/ProcessorCapability/ProcessorCapability.h"
#include "DigitCount.h"
////////////////////////////////////////////////////////////////////////////////
#if 0
#elif defined YMP_Arch_2017_x64_Skylake
#include "Kernels/DigitCount_x64_AVX512-BW.ipp"
#elif defined YMP_Arch_2013_x64_Haswell
#include "Kernels/DigitCount_x64_AVX2.ipp"
#elif defined YMP_Arch_2001_x86_SSE2
#include "Kernels/DigitCount_x86_SSE2.ipp"
#else
#include "Kernels/DigitCount_Default.ipp"
#endif
////////////////////////////////////////////////////////////////////////////////
namespace DigitViewer2{
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
DigitCounts::DigitCounts(char radix)
    : m_radix(radix)
{
    if (radix < 2 || radix > 16){
        throw InvalidParametersException("DigitCounts::DigitCounts()", "Radix is too large.");
    }
    memset(m_counts, 0, sizeof(m_counts));
}
bool DigitCounts::operator==(const DigitCounts& x) const{
    return memcmp(m_counts, x.m_counts, sizeof(m_counts)) == 0;
}
bool DigitCounts::operator!=(const DigitCounts& x) const{
    return memcmp(m_counts, x.m_counts, sizeof(m_counts)) != 0;
}
void DigitCounts::operator+=(const DigitCounts& x){
    for (upL_t c = 0; c < 16; c++){
        m_counts[c] += x.m_counts[c];
    }
}
std::string DigitCounts::to_string() const{
    std::string body = "{";
    for (int c = 0; c < m_radix - 1; c++){
        body += std::to_string(m_counts[c]);
        body += ',';
    }
    {
        body += std::to_string(m_counts[m_radix - 1]);
        body += '}';
    }
    return body;
}
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
}
