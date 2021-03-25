/* ResourceAcquisitionFailedException.h
 * 
 * Author           : Alexander J. Yee
 * Date Created     : 02/16/2019
 * Last Modified    : 02/16/2019
 * 
 */

#pragma once
#ifndef ymp_Exceptions_ResourceAcquisitionFailedException_H
#define ymp_Exceptions_ResourceAcquisitionFailedException_H
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//  Dependencies
#include "StringException.h"
namespace ymp{
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
class ResourceAcquisitionFailedException : public StringException{
    YMP_EXCEPTION_DECLARATIONS()

public:
    using StringException::StringException;

};
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
class MemoryAllocationFailedException : public ResourceAcquisitionFailedException{
    YMP_EXCEPTION_DECLARATIONS()

public:
    using ResourceAcquisitionFailedException::ResourceAcquisitionFailedException;

    MemoryAllocationFailedException(const char* function, uiL_t bytes);
    MemoryAllocationFailedException(const char* function, const char* type, uiL_t bytes);

    virtual void print() const override;

public:
    //  Serialization
    MemoryAllocationFailedException(SerializationPassKey key, const char*& stream);
    virtual void serialize(std::string& stream) const override;

private:
    std::string m_type;
    uiL_t m_bytes;
};
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
}
#endif
