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

#include <memory>

namespace Factory {
    template<class T, class... Args> std::unique_ptr<T> make_unique(Args... args);
    template<class T, class... Args> std::shared_ptr<T> make_shared(Args... args);
}
