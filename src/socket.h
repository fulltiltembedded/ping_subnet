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

#include "subnet.h"
#include "ip_address.h"

class Socket {
    OutputStream& output_stream;
    OutputStream& error_stream;
    int hsocket;
    int apply_subnet_bpf_filter(const Subnet &target_subnet) const;
    void close_socket() const;
    void show_errno() const;
public:
    Socket(OutputStream& output_stream, OutputStream& error_stream);
    ~Socket();
    int send_packet(const void *packet, size_t size, const IPAddress &dest) const;
    ssize_t receive_packet(std::vector<char> &buffer) const;
    int configure(const Subnet &target_subnet) const;
};
