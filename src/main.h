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

#include <string>

struct Main {
    static bool argc_is_incorrect(int argc);
    static bool help_message_requested(int argc, char *argv[]);
    static void show_help();

    // Constants.
    static const int min_argc = 2;
};
