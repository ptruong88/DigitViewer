/* RawFile_Windows.h
 * 
 * Author           : Alexander J. Yee
 * Date Created     : 07/20/2011
 * Last Modified    : 03/24/2018
 * 
 */

#pragma once
#ifndef ymp_FileIO_RawFile_Windows_H
#define ymp_FileIO_RawFile_Windows_H
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//  Dependencies
#include <string>
#include "PublicLibs/Types.h"
namespace ymp{
namespace FileIO{
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
enum Mode{
    CREATE,
    OPEN_READONLY,
    OPEN_READWRITE,
};
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
class RawFile{
    static const upL_t MAX_IO_BYTES = (upL_t)1 << 30;
    static const upL_t CHECK_MEM_THRESHOLD = (upL_t)64 << 20;
    static const upL_t ALIGNMENT = 4096;
    static const bool RAW_IO = true;

public:
    ~RawFile();

    RawFile(RawFile&& x);
    void operator=(RawFile&& x);

    RawFile(const RawFile& x) = delete;
    void operator=(const RawFile& x) = delete;

public:
    RawFile();
    RawFile(std::string path, Mode mode, bool persistent = true);       //  Create or open file.
    RawFile(ufL_t bytes, std::string path, bool persistent = false);    //  Create a file with a specific size.

    operator bool() const;
    const std::string& path() const{ return m_path; }

    void close(bool keep_file);
    void close_and_set_size(ufL_t bytes);
    void rename(std::string path, bool readonly); 

public:
    //  All parameters must be aligned to "ALIGNMENT".
    //  If "throw_on_partial" is true, it will throw an exception if it is
    //  unable to read/write the full requested bytes. For reads, this may imply
    //  reaching the end of the file. For stores, this almost always implies a
    //  more serious error such as disk-is-full or a hardware failure.
    upL_t load (      void* data, ufL_t offset, upL_t bytes, bool throw_on_partial);
    upL_t store(const void* data, ufL_t offset, upL_t bytes, bool throw_on_partial = true);

private:
    void set_size(ufL_t bytes);
    void check_alignment(const void* data, ufL_t offset, upL_t bytes);
    static upL_t pick_buffer_size(upL_t bytes);

private:
    void* m_filehandle;
    std::string m_path;
    std::wstring m_wpath;
    bool m_persistent;
};
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
}
}
#endif
