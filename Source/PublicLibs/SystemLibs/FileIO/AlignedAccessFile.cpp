/* AlignedAccessFile.cpp
 * 
 * Author           : Alexander J. Yee
 * Date Created     : 03/19/2018
 * Last Modified    : 07/03/2019
 * 
 */

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//  Dependencies
#include "PublicLibs/Exceptions/InvalidParametersException.h"
#include "PublicLibs/BasicLibs/Alignment/AlignmentTools.h"
#include "AlignedAccessFile.h"
namespace ymp{
namespace FileIO{
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
AlignedAccessFile::AlignedAccessFile(ukL_t alignment_k, std::string path)
    : m_alignment_k(alignment_k)
    , m_path(std::move(path))
{}
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void AlignedAccessFile::check_alignment(const void* data, ufL_t offset, upL_t bytes){
    if (Alignment::ptr_past_aligned_k(m_alignment_k, data) != 0){
        throw InvalidParametersException("AlignedAccessFile::check_alignment()", "Buffer is misaligned.");
    }
    if (Alignment::int_past_aligned_k(m_alignment_k, offset) != 0){
        throw InvalidParametersException("AlignedAccessFile::check_alignment()", "Offset is misaligned.");
    }
    if (Alignment::int_past_aligned_k(m_alignment_k, bytes) != 0){
        throw InvalidParametersException("AlignedAccessFile::check_alignment()", "Length is misaligned.");
    }
}
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
}
}
