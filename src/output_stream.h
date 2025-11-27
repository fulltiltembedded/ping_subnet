 /*
 * This file is part of ping_subnet utility.
 * 
 * © 2025 WTFPL – Do What the Fuck You Want to Public License.
 * Learn more: https://www.wtfpl.net
 * 
 * Developed by Full Tilt Embedded:
 *      https://github.com/fulltiltembedded
 *      https://fulltiltembedded.com
 */

#pragma once

#include <iostream>
#include <string>
#include "ip_address.h"

// Interface class for redirecting text output into different stream (GUI/console in our case).
class OutputStream {
    std::ostream &stream;
    template<class T> OutputStream& write_to_stream(T arg);
public:
    OutputStream(std::ostream &stream) : stream(stream) {};
    OutputStream& operator<<(std::string arg);
    OutputStream& operator<<(std::ostream& (*arg)(std::ostream&));  // handle std::endl
};