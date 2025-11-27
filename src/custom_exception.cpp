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

#include "custom_exception.h"

const char* CustomException::what() const noexcept
{
    try {
        return this->info.c_str();
    } catch (...) {     // ensure nothing is thrown
        return (const char *)"";
    }
}