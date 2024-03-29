// SPDX-License-Identifier: GPL-2.0-or-later
/*
 * Private header file for the zebra FPM module.
 *
 * Copyright (C) 2012 by Open Source Routing.
 * Copyright (C) 2012 by Internet Systems Consortium, Inc. ("ISC")
 */

#ifndef _ZEBRA_FPM_PRIVATE_H
#define _ZEBRA_FPM_PRIVATE_H

#include "zebra/debug.h"

#ifdef __cplusplus
extern "C"
{
#endif

#if defined __STDC_VERSION__ && __STDC_VERSION__ >= 199901L

#define zfpm_debug(...)                                                       \
  do                                                                          \
    {                                                                         \
      if (IS_ZEBRA_DEBUG_FPM)                                                 \
        zlog_debug ("FPM: " __VA_ARGS__);                                     \
    }                                                                         \
  while (0)

#elif defined __GNUC__

#define zfpm_debug(_args...)                                                  \
  do                                                                          \
    {                                                                         \
      if (IS_ZEBRA_DEBUG_FPM)                                                 \
        zlog_debug ("FPM: " _args);                                           \
    }                                                                         \
  while (0)

#else
static inline void
zfpm_debug (const char *format, ...)
{
  return;
}
#endif

  /* This structure contains the MAC addresses enqueued for FPM processing. */
  struct fpm_mac_info_t
  {
    struct ethaddr macaddr;
    uint32_t zebra_flags; /* Could be used to build FPM messages */
    vni_t vni;
    ifindex_t vxlan_if;
    ifindex_t svi_if;         /* L2 or L3 Bridge interface */
    struct in_addr r_vtep_ip; /* Remote VTEP IP */

    /* Linkage to put MAC on the FPM processing queue. */
    TAILQ_ENTRY (fpm_mac_info_t) fpm_mac_q_entries;

    uint8_t fpm_flags;

#define ZEBRA_MAC_UPDATE_FPM                                                  \
  0x1 /* This flag indicates if we want to upadte                             \
       * data plane for this MAC. If a MAC is added                           \
       * and then deleted immediately, we do not want                         \
       * to update data plane for such operation.                             \
       * Unset the ZEBRA_MAC_UPDATE_FPM flag in this                          \
       * case. FPM thread while processing the queue                          \
       * node will check this flag and dequeue the                            \
       * node silently without sending any update to                          \
       * the data plane.                                                      \
       */
#define ZEBRA_MAC_DELETE_FPM                                                  \
  0x2 /* This flag is set if it is a delete operation                         \
       * for the MAC.                                                         \
       */
  };

  /*
   * Externs
   */
  extern int zfpm_netlink_encode_route (int cmd, rib_dest_t *dest,
                                        struct route_entry *re, char *in_buf,
                                        size_t in_buf_len);

  extern int zfpm_protobuf_encode_route (rib_dest_t *dest,
                                         struct route_entry *re,
                                         uint8_t *in_buf, size_t in_buf_len);

  extern int zfpm_netlink_encode_mac (struct fpm_mac_info_t *mac, char *in_buf,
                                      size_t in_buf_len);

  extern struct route_entry *zfpm_route_for_update (rib_dest_t *dest);

  extern union g_addr ipv4ll_gateway;

#ifdef __cplusplus
}
#endif

#endif /* _ZEBRA_FPM_PRIVATE_H */
