/* FileException.h
 * 
 * Author           : Alexander J. Yee
 * Date Created     : 09/17/2014
 * Last Modified    : 09/17/2014
 * 
 */

#pragma once
#ifndef _ymp_File_FileException_H
#define _ymp_File_FileException_H
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//  Dependencies
#include "../Exception.h"
namespace ymp{
namespace FileIO{
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
#define YMC_EXCEPTION_FILEIO    2
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
class FileException : public ym_exception{
    virtual void fire_this() const{
        throw *this;
    }

    std::wstring file;

public:
    FileException(const char* location,const wchar_t* file,const char* message){
        level = YMC_EXCEPTION_FILEIO;
        code = 1;
        this->location = location;
        this->message = message;
        this->file = file;
        this->wstr = this->file.c_str();
    }
    FileException(int code,const char* location,const wchar_t* file,const char* message){
        level = YMC_EXCEPTION_FILEIO;
        this->code = code;
        this->location = location;
        this->message = message;
        this->file = file;
        this->wstr = this->file.c_str();
    }
};
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
}
}
#endif
