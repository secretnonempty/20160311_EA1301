#ifndef __A2MP_ADP_H
#define __A2MP_ADP_H

#include "bttypes.h"
#include "me_adp.h"
#include "sec_adp.h"
#include "eventmgr.h"

#if A2MP_PROTOCOL == XA_ENABLED
typedef U8 A2mpEvent;

#define BT_A2MP_CONTROLLER_TYPE_BREDR   0x00
#define BT_A2MP_CONTROLLER_TYPE_80211   0x01

#define BT_A2MP_CONTROLLER_STATE_IDLE        0x00
#define BT_A2MP_CONTROLLER_STATE_USED   0x01

#define BT_PAL_CONTROLLER_LIST_SIZE 6


typedef struct _BtA2MPCommandReject
{
	U16 reason;
	U8 *data;
	U16 dataSize;
}BtA2MPCommandReject;


typedef struct _BtA2MPDiscoveryReq
{
	U16 mtu;
	U8 *extendedFeatureMask;
	U16 extendedFeatureMaskSize;
}BtA2MPDiscoveryReq;


typedef struct _BtA2MPDiscoveryRsp
{
	U16 mtu;
	U8 *extendedFeatureMask;
	U16 extendedFeatureMaskSize;
	U8 *controllerList;
	U16 controllerListSize;
}BtA2MPDiscoveryRsp;

typedef struct _BtA2MPChangeNotify
{
	U8 *controllerList;
	U16 controllerListSize;
}BtA2MPChangeNotify;


typedef struct _BtA2MPGetInfoReq
{
	U8 controllerId;
}BtA2MPGetInfoReq;

typedef struct _BtA2MPGetInfoRsp 
{
	U8 controllerId;
	U8 status;
	U32 total_bandwidth;
	U32 max_guarantee_bandwidth;
	U32 min_latency;
	U32 max_pdu_size;
    U8 controller_type;
	U16 pal_capability;
	U16 max_amp_assoc_length;
	U32 max_flush_timeout;
	U32 best_effort_flush_timeout;
}BtA2MPGetInfoRsp;

typedef struct _BtA2MPGetAMPAssocReq
{
	U8 controllerId;
}BtA2MPGetAMPAssocReq;

typedef struct _BtA2MPGetAMPAssocRsp
{
	U8 controllerId;
	U8 status;
	U8 *ampAssoc;
	U16 ampAssocSize;
}BtA2MPGetAMPAssocRsp;

typedef struct _BtA2MPCreatePhysicalLinkReq
{
	U8 localControllerId;
	U8 remoteControllerId;
	U8 *ampAssoc;
	U16 ampAssocSize;
}BtA2MPCreatePhysicalLinkReq;

typedef struct _BtA2MPCreatePhysicalLinkRsp
{
	U8 localControllerId;
	U8 remoteControllerId;
	U8 status;
}BtA2MPCreatePhysicalLinkRsp;

typedef struct _BtA2MPDisconnectPhysicalLinkReq
{
	U8 localControllerId;
	U8 remoteControllerId;
}BtA2MPDisconnectPhysicalLinkReq;

typedef struct _BtA2MPDisconnectPhysicalLinkRsp
{
	U8 localControllerId;
	U8 remoteControllerId;
	U8 status;
}BtA2MPDisconnectPhysicalLinkRsp;



#endif /* A2MP_PROTOCOL == XA_ENABLED */
#endif /* __A2MP_ADP_H */
