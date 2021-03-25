/* ParseException.cpp
 * 
 * Author           : Alexander J. Yee
 * Date Created     : 04/11/2017
 * Last Modified    : 04/11/2017
 * 
 */

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//  Dependencies
#include "PublicLibs/CompilerSettings.h"
#include "ParseException.h"
//#include "ParseThrower.h"
namespace ymp{
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
YMP_EXCEPTION_DEFINITIONS(ParseException)
YMP_EXCEPTION_DEFINITIONS(EndOfStreamException)
YMP_EXCEPTION_DEFINITIONS(KeyNotFoundException)
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
EndOfStreamException::EndOfStreamException()
    : ParseException("Unexpected end of stream.")
{}
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
}
