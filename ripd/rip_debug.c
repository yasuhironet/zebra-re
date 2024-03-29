// SPDX-License-Identifier: GPL-2.0-or-later
/* RIP debug routines
 * Copyright (C) 1999 Kunihiro Ishiguro <kunihiro@zebra.org>
 */

#include <zebra.h>
#include "command.h"
#include "ripd/rip_debug.h"

/* For debug statement. */
unsigned long rip_debug_event = 0;
unsigned long rip_debug_packet = 0;
unsigned long rip_debug_zebra = 0;

DEFUN_NOSH (show_debugging_rip,
            show_debugging_rip_cmd,
            "show debugging [rip]",
            SHOW_STR
            DEBUG_STR
            RIP_STR)
{
  vty_out (vty, "RIP debugging status:\n");

  if (IS_RIP_DEBUG_EVENT)
    vty_out (vty, "  RIP event debugging is on\n");

  if (IS_RIP_DEBUG_PACKET)
    {
      if (IS_RIP_DEBUG_SEND && IS_RIP_DEBUG_RECV)
        {
          vty_out (vty, "  RIP packet debugging is on\n");
        }
      else
        {
          if (IS_RIP_DEBUG_SEND)
            vty_out (vty, "  RIP packet send debugging is on\n");
          else
            vty_out (vty, "  RIP packet receive debugging is on\n");
        }
    }

  if (IS_RIP_DEBUG_ZEBRA)
    vty_out (vty, "  RIP zebra debugging is on\n");

  cmd_show_lib_debugs (vty);

  return CMD_SUCCESS;
}

DEFUN (debug_rip_events,
       debug_rip_events_cmd,
       "debug rip events",
       DEBUG_STR
       RIP_STR
       "RIP events\n")
{
  rip_debug_event = RIP_DEBUG_EVENT;
  return CMD_SUCCESS;
}

DEFUN (debug_rip_packet,
       debug_rip_packet_cmd,
       "debug rip packet",
       DEBUG_STR
       RIP_STR
       "RIP packet\n")
{
  rip_debug_packet = RIP_DEBUG_PACKET;
  rip_debug_packet |= RIP_DEBUG_SEND;
  rip_debug_packet |= RIP_DEBUG_RECV;
  return CMD_SUCCESS;
}

DEFUN (debug_rip_packet_direct,
       debug_rip_packet_direct_cmd,
       "debug rip packet <recv|send>",
       DEBUG_STR
       RIP_STR
       "RIP packet\n"
       "RIP receive packet\n"
       "RIP send packet\n")
{
  int idx_recv_send = 3;
  rip_debug_packet |= RIP_DEBUG_PACKET;
  if (strcmp ("send", argv[idx_recv_send]->text) == 0)
    rip_debug_packet |= RIP_DEBUG_SEND;
  if (strcmp ("recv", argv[idx_recv_send]->text) == 0)
    rip_debug_packet |= RIP_DEBUG_RECV;
  return CMD_SUCCESS;
}

DEFUN (debug_rip_zebra,
       debug_rip_zebra_cmd,
       "debug rip zebra",
       DEBUG_STR
       RIP_STR
       "RIP and ZEBRA communication\n")
{
  rip_debug_zebra = RIP_DEBUG_ZEBRA;
  return CMD_SUCCESS;
}

DEFUN (no_debug_rip_events,
       no_debug_rip_events_cmd,
       "no debug rip events",
       NO_STR
       DEBUG_STR
       RIP_STR
       "RIP events\n")
{
  rip_debug_event = 0;
  return CMD_SUCCESS;
}

DEFUN (no_debug_rip_packet,
       no_debug_rip_packet_cmd,
       "no debug rip packet",
       NO_STR
       DEBUG_STR
       RIP_STR
       "RIP packet\n")
{
  rip_debug_packet = 0;
  return CMD_SUCCESS;
}

DEFUN (no_debug_rip_packet_direct,
       no_debug_rip_packet_direct_cmd,
       "no debug rip packet <recv|send>",
       NO_STR
       DEBUG_STR
       RIP_STR
       "RIP packet\n"
       "RIP option set for receive packet\n"
       "RIP option set for send packet\n")
{
  int idx_recv_send = 4;
  if (strcmp ("send", argv[idx_recv_send]->text) == 0)
    {
      if (IS_RIP_DEBUG_RECV)
        rip_debug_packet &= ~RIP_DEBUG_SEND;
      else
        rip_debug_packet = 0;
    }
  else if (strcmp ("recv", argv[idx_recv_send]->text) == 0)
    {
      if (IS_RIP_DEBUG_SEND)
        rip_debug_packet &= ~RIP_DEBUG_RECV;
      else
        rip_debug_packet = 0;
    }
  return CMD_SUCCESS;
}

DEFUN (no_debug_rip_zebra,
       no_debug_rip_zebra_cmd,
       "no debug rip zebra",
       NO_STR
       DEBUG_STR
       RIP_STR
       "RIP and ZEBRA communication\n")
{
  rip_debug_zebra = 0;
  return CMD_SUCCESS;
}

static int config_write_debug (struct vty *vty);
/* Debug node. */
static struct cmd_node debug_node = {
  .name = "debug",
  .node = DEBUG_NODE,
  .prompt = "",
  .config_write = config_write_debug,
};

static int
config_write_debug (struct vty *vty)
{
  int write = 0;

  if (IS_RIP_DEBUG_EVENT)
    {
      vty_out (vty, "debug rip events\n");
      write++;
    }
  if (IS_RIP_DEBUG_PACKET)
    {
      if (IS_RIP_DEBUG_SEND && IS_RIP_DEBUG_RECV)
        {
          vty_out (vty, "debug rip packet\n");
          write++;
        }
      else
        {
          if (IS_RIP_DEBUG_SEND)
            vty_out (vty, "debug rip packet send\n");
          else
            vty_out (vty, "debug rip packet recv\n");
          write++;
        }
    }
  if (IS_RIP_DEBUG_ZEBRA)
    {
      vty_out (vty, "debug rip zebra\n");
      write++;
    }
  return write;
}

void
rip_debug_init (void)
{
  rip_debug_event = 0;
  rip_debug_packet = 0;
  rip_debug_zebra = 0;

  install_node (&debug_node);

  install_element (ENABLE_NODE, &show_debugging_rip_cmd);
  install_element (ENABLE_NODE, &debug_rip_events_cmd);
  install_element (ENABLE_NODE, &debug_rip_packet_cmd);
  install_element (ENABLE_NODE, &debug_rip_packet_direct_cmd);
  install_element (ENABLE_NODE, &debug_rip_zebra_cmd);
  install_element (ENABLE_NODE, &no_debug_rip_events_cmd);
  install_element (ENABLE_NODE, &no_debug_rip_packet_cmd);
  install_element (ENABLE_NODE, &no_debug_rip_packet_direct_cmd);
  install_element (ENABLE_NODE, &no_debug_rip_zebra_cmd);

  install_element (CONFIG_NODE, &debug_rip_events_cmd);
  install_element (CONFIG_NODE, &debug_rip_packet_cmd);
  install_element (CONFIG_NODE, &debug_rip_packet_direct_cmd);
  install_element (CONFIG_NODE, &debug_rip_zebra_cmd);
  install_element (CONFIG_NODE, &no_debug_rip_events_cmd);
  install_element (CONFIG_NODE, &no_debug_rip_packet_cmd);
  install_element (CONFIG_NODE, &no_debug_rip_packet_direct_cmd);
  install_element (CONFIG_NODE, &no_debug_rip_zebra_cmd);
}
