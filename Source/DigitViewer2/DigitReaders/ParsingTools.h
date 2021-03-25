/* ParsingTools.h
 * 
 * Author           : Alexander J. Yee
 * Date Created     : 01/30/2018
 * Last Modified    : 01/30/2018
 * 
 */

#pragma once
#ifndef ydv_DigitViewer_ParsingTools_H
#define ydv_DigitViewer_ParsingTools_H
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//  Dependencies
#include <string>
#include "PublicLibs/SystemLibs/FileIO/BasicFile.h"
#include "PublicLibs/SystemLibs/FileIO/BufferredStreamFile.h"
namespace DigitViewer2{
    using namespace ymp;
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
std::string grab_until_delim(FileIO::BufferedReader& file, char delim);
std::string grab_until_delim(FileIO::BasicFile& file, char delim);
const char* grab_until_delim(std::string& token, const char* str, char delim);
uiL_t parse_uL(const char* str);
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
}
#endif
