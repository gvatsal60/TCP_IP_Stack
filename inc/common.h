#ifndef _COMMON_H_
#define _COMMON_H_

#define IS_BIT_SET(n, pos) ((n & (1 << (pos))) != 0)
#define TOGGLE_BIT(n, pos) (n = n ^ (1 << (pos)))
#define COMPLEMENT(num) (num = num ^ 0xFFFFFFFF)
#define UNSET_BIT(n, pos) (n = n & ((1 << pos) ^ 0xFFFFFFFF))
#define SET_BIT(n, pos) (n = n | 1 << pos)

/* Specified in ethernet_hdr->type */
const auto ARP_BROAD_REQ = 1;
const auto ARP_REPLY = 2;
const auto ARP_MSG = 806;
const auto BROADCAST_MAC = 0xFFFFFFFFFFFF;
const auto ETH_IP = 0x0800;
const auto ICMP_PRO = 1;
const auto ICMP_ECHO_REQ = 8;
const auto ICMP_ECHO_REP = 0;
const auto MTCP = 20;
const auto USERAPP1 = 21;
const auto VLAN_8021Q_PROTO = 0x8100;
const auto IP_IN_IP = 4;

#endif