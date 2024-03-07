<p align="center">
<img src="https://github.com/yasuhironet/zebra-re/blob/main/zebralogo.jpeg" alt="Icon" width="20%"/>
</p>

Zebra
=========

Zebra is a free software that implements and manages various
IPv4 and IPv6 routing protocols.

This repository is a local fork for the purpose of
our personal developments.
It is forked from [FRR](https://www.frrouting.org/) at frr-9.0.2.tar.gz.

We are planning to make the following advancements:

* develop a custom routing protocol extention which we call LS-EVPN.
* simplify the code.
* maintain a more easier way to debug.
* change the fundamental design as the next challenges.

At this moment, we are not planning to solicit and receive
any contributions from others.

Current differences from FRR:

* The coding style is changed back to the GNU style.

Supported the protocols:

* BGP
* OSPFv2
* OSPFv3
* RIPv1
* RIPv2
* RIPng
* IS-IS
* PIM-SM/MSDP
* LDP
* BFD
* Babel
* PBR
* OpenFabric
* VRRP
* EIGRP (alpha)
* NHRP (alpha)


