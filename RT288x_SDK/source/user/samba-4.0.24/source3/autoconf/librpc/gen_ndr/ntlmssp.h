/* header auto-generated by pidl */

#ifndef _PIDL_HEADER_ntlmssp
#define _PIDL_HEADER_ntlmssp

#include <stdint.h>

#include "libcli/util/ntstatus.h"

#ifndef _HEADER_ntlmssp
#define _HEADER_ntlmssp

#define NTLMSSP_NEGOTIATE_NTLM2	( NTLMSSP_NEGOTIATE_EXTENDED_SESSIONSECURITY )
#define NTLMSSP_SIGN_VERSION	( 0x01 )
#define NTLMSSP_SIG_SIZE	( 16 )
enum ntlmssp_MessageType
#ifndef USE_UINT_ENUMS
 {
	NtLmNegotiate=(int)(0x00000001),
	NtLmChallenge=(int)(0x00000002),
	NtLmAuthenticate=(int)(0x00000003)
}
#else
 { __donnot_use_enum_ntlmssp_MessageType=0x7FFFFFFF}
#define NtLmNegotiate ( 0x00000001 )
#define NtLmChallenge ( 0x00000002 )
#define NtLmAuthenticate ( 0x00000003 )
#endif
;

/* bitmap NEGOTIATE */
#define NTLMSSP_NEGOTIATE_UNICODE ( 0x00000001 )
#define NTLMSSP_NEGOTIATE_OEM ( 0x00000002 )
#define NTLMSSP_REQUEST_TARGET ( 0x00000004 )
#define NTLMSSP_NEGOTIATE_SIGN ( 0x00000010 )
#define NTLMSSP_NEGOTIATE_SEAL ( 0x00000020 )
#define NTLMSSP_NEGOTIATE_DATAGRAM ( 0x00000040 )
#define NTLMSSP_NEGOTIATE_LM_KEY ( 0x00000080 )
#define NTLMSSP_NEGOTIATE_NETWARE ( 0x00000100 )
#define NTLMSSP_NEGOTIATE_NTLM ( 0x00000200 )
#define NTLMSSP_NEGOTIATE_NT_ONLY ( 0x00000400 )
#define NTLMSSP_ANONYMOUS ( 0x00000800 )
#define NTLMSSP_NEGOTIATE_OEM_DOMAIN_SUPPLIED ( 0x00001000 )
#define NTLMSSP_NEGOTIATE_OEM_WORKSTATION_SUPPLIED ( 0x00002000 )
#define NTLMSSP_NEGOTIATE_THIS_IS_LOCAL_CALL ( 0x00004000 )
#define NTLMSSP_NEGOTIATE_ALWAYS_SIGN ( 0x00008000 )
#define NTLMSSP_TARGET_TYPE_DOMAIN ( 0x00010000 )
#define NTLMSSP_TARGET_TYPE_SERVER ( 0x00020000 )
#define NTLMSSP_TARGET_TYPE_SHARE ( 0x00040000 )
#define NTLMSSP_NEGOTIATE_EXTENDED_SESSIONSECURITY ( 0x00080000 )
#define NTLMSSP_NEGOTIATE_IDENTIFY ( 0x00100000 )
#define NTLMSSP_REQUEST_NON_NT_SESSION_KEY ( 0x00400000 )
#define NTLMSSP_NEGOTIATE_TARGET_INFO ( 0x00800000 )
#define NTLMSSP_NEGOTIATE_VERSION ( 0x02000000 )
#define NTLMSSP_NEGOTIATE_128 ( 0x20000000 )
#define NTLMSSP_NEGOTIATE_KEY_EXCH ( 0x40000000 )
#define NTLMSSP_NEGOTIATE_56 ( 0x80000000 )

enum ntlmssp_WindowsMajorVersion
#ifndef USE_UINT_ENUMS
 {
	NTLMSSP_WINDOWS_MAJOR_VERSION_5=(int)(0x05),
	NTLMSSP_WINDOWS_MAJOR_VERSION_6=(int)(0x06)
}
#else
 { __donnot_use_enum_ntlmssp_WindowsMajorVersion=0x7FFFFFFF}
#define NTLMSSP_WINDOWS_MAJOR_VERSION_5 ( 0x05 )
#define NTLMSSP_WINDOWS_MAJOR_VERSION_6 ( 0x06 )
#endif
;

enum ntlmssp_WindowsMinorVersion
#ifndef USE_UINT_ENUMS
 {
	NTLMSSP_WINDOWS_MINOR_VERSION_0=(int)(0x00),
	NTLMSSP_WINDOWS_MINOR_VERSION_1=(int)(0x01),
	NTLMSSP_WINDOWS_MINOR_VERSION_2=(int)(0x02)
}
#else
 { __donnot_use_enum_ntlmssp_WindowsMinorVersion=0x7FFFFFFF}
#define NTLMSSP_WINDOWS_MINOR_VERSION_0 ( 0x00 )
#define NTLMSSP_WINDOWS_MINOR_VERSION_1 ( 0x01 )
#define NTLMSSP_WINDOWS_MINOR_VERSION_2 ( 0x02 )
#endif
;

enum ntlmssp_NTLMRevisionCurrent
#ifndef USE_UINT_ENUMS
 {
	NTLMSSP_REVISION_W2K3_RC1=(int)(0x0A),
	NTLMSSP_REVISION_W2K3=(int)(0x0F)
}
#else
 { __donnot_use_enum_ntlmssp_NTLMRevisionCurrent=0x7FFFFFFF}
#define NTLMSSP_REVISION_W2K3_RC1 ( 0x0A )
#define NTLMSSP_REVISION_W2K3 ( 0x0F )
#endif
;

struct ntlmssp_VERSION {
	enum ntlmssp_WindowsMajorVersion ProductMajorVersion;
	enum ntlmssp_WindowsMinorVersion ProductMinorVersion;
	uint16_t ProductBuild;
	uint8_t Reserved[3];
	enum ntlmssp_NTLMRevisionCurrent NTLMRevisionCurrent;
}/* [public] */;

union ntlmssp_Version {
	struct ntlmssp_VERSION version;/* [case(NTLMSSP_NEGOTIATE_VERSION)] */
}/* [noprint,nodiscriminant] */;

struct NEGOTIATE_MESSAGE {
	const char *Signature;/* [charset(DOS),value("NTLMSSP")] */
	enum ntlmssp_MessageType MessageType;/* [value(NtLmNegotiate)] */
	uint32_t NegotiateFlags;
	uint16_t DomainNameLen;/* [value(DomainName?strlen(DomainName):0)] */
	uint16_t DomainNameMaxLen;/* [value(DomainNameLen)] */
	const char * DomainName;/* [subcontext(0),relative,subcontext_size(DomainNameLen),flag(ndr_ntlmssp_negotiated_string_flags(NTLMSSP_NEGOTIATE_OEM))] */
	uint16_t WorkstationLen;/* [value(Workstation?strlen(Workstation):0)] */
	uint16_t WorkstationMaxLen;/* [value(WorkstationLen)] */
	const char * Workstation;/* [subcontext(0),flag(ndr_ntlmssp_negotiated_string_flags(NTLMSSP_NEGOTIATE_OEM)),subcontext_size(WorkstationLen),relative] */
	union ntlmssp_Version Version;/* [switch_is(NegotiateFlags&NTLMSSP_NEGOTIATE_VERSION)] */
}/* [public] */;

enum ntlmssp_AvId
#ifndef USE_UINT_ENUMS
 {
	MsvAvEOL=(int)(0),
	MsvAvNbComputerName=(int)(1),
	MsvAvNbDomainName=(int)(2),
	MsvAvDnsComputerName=(int)(3),
	MsvAvDnsDomainName=(int)(4),
	MsvAvDnsTreeName=(int)(5),
	MsvAvFlags=(int)(6),
	MsvAvTimestamp=(int)(7),
	MsAvRestrictions=(int)(8),
	MsvAvTargetName=(int)(9),
	MsvChannelBindings=(int)(10)
}
#else
 { __donnot_use_enum_ntlmssp_AvId=0x7FFFFFFF}
#define MsvAvEOL ( 0 )
#define MsvAvNbComputerName ( 1 )
#define MsvAvNbDomainName ( 2 )
#define MsvAvDnsComputerName ( 3 )
#define MsvAvDnsDomainName ( 4 )
#define MsvAvDnsTreeName ( 5 )
#define MsvAvFlags ( 6 )
#define MsvAvTimestamp ( 7 )
#define MsAvRestrictions ( 8 )
#define MsvAvTargetName ( 9 )
#define MsvChannelBindings ( 10 )
#endif
;

struct Restriction_Encoding {
	uint32_t Size;
	uint32_t Z4;/* [value(0)] */
	uint32_t IntegrityLevel;
	uint32_t SubjectIntegrityLevel;
	uint8_t MachineId[32];
};

/* bitmap ntlmssp_AvFlags */
#define NTLMSSP_AVFLAG_CONSTRAINTED_ACCOUNT ( 0x00000001 )
#define NTLMSSP_AVFLAG_MIC_IN_AUTHENTICATE_MESSAGE ( 0x00000002 )

union ntlmssp_AvValue {
	const char * AvNbComputerName;/* [flag(ndr_ntlmssp_negotiated_string_flags(NTLMSSP_NEGOTIATE_UNICODE)),case(MsvAvNbComputerName)] */
	const char * AvNbDomainName;/* [flag(ndr_ntlmssp_negotiated_string_flags(NTLMSSP_NEGOTIATE_UNICODE)),case(MsvAvNbDomainName)] */
	const char * AvDnsComputerName;/* [flag(ndr_ntlmssp_negotiated_string_flags(NTLMSSP_NEGOTIATE_UNICODE)),case(MsvAvDnsComputerName)] */
	const char * AvDnsDomainName;/* [flag(ndr_ntlmssp_negotiated_string_flags(NTLMSSP_NEGOTIATE_UNICODE)),case(MsvAvDnsDomainName)] */
	const char * AvDnsTreeName;/* [flag(ndr_ntlmssp_negotiated_string_flags(NTLMSSP_NEGOTIATE_UNICODE)),case(MsvAvDnsTreeName)] */
	uint32_t AvFlags;/* [case(MsvAvFlags)] */
	NTTIME AvTimestamp;/* [case(MsvAvTimestamp)] */
	struct Restriction_Encoding AvRestrictions;/* [case(MsAvRestrictions)] */
	const char * AvTargetName;/* [case(MsvAvTargetName),flag(ndr_ntlmssp_negotiated_string_flags(NTLMSSP_NEGOTIATE_UNICODE))] */
	uint8_t ChannelBindings[16];/* [case(MsvChannelBindings)] */
	DATA_BLOB blob;/* [flag(LIBNDR_FLAG_REMAINING),default] */
}/* [flag(LIBNDR_FLAG_NOALIGN),gensize,nodiscriminant] */;

struct AV_PAIR {
	enum ntlmssp_AvId AvId;
	uint16_t AvLen;/* [value(ndr_size_ntlmssp_AvValue(&r->Value,r->AvId,0))] */
	union ntlmssp_AvValue Value;/* [switch_is(AvId),subcontext(0),subcontext_size(AvLen)] */
}/* [public,flag(LIBNDR_FLAG_NOALIGN)] */;

struct AV_PAIR_LIST {
	uint32_t count;
	struct AV_PAIR *pair;
}/* [nopull,gensize,nopush,flag(LIBNDR_FLAG_NOALIGN)] */;

struct CHALLENGE_MESSAGE {
	const char *Signature;/* [charset(DOS),value("NTLMSSP")] */
	enum ntlmssp_MessageType MessageType;/* [value(NtLmChallenge)] */
	uint16_t TargetNameLen;/* [value(ndr_ntlmssp_string_length(NegotiateFlags,TargetName))] */
	uint16_t TargetNameMaxLen;/* [value(TargetNameLen)] */
	const char * TargetName;/* [subcontext(0),relative,flag(ndr_ntlmssp_negotiated_string_flags(r->NegotiateFlags)),subcontext_size(TargetNameLen)] */
	uint32_t NegotiateFlags;
	uint8_t ServerChallenge[8];
	uint8_t Reserved[8];
	uint16_t TargetInfoLen;/* [value(ndr_size_AV_PAIR_LIST(TargetInfo,ndr->flags))] */
	uint16_t TargetNameInfoMaxLen;/* [value(TargetInfoLen)] */
	struct AV_PAIR_LIST *TargetInfo;/* [subcontext_size(TargetInfoLen),relative,subcontext(0)] */
	union ntlmssp_Version Version;/* [switch_is(NegotiateFlags&NTLMSSP_NEGOTIATE_VERSION)] */
}/* [public,flag(LIBNDR_PRINT_ARRAY_HEX)] */;

struct LM_RESPONSE {
	uint8_t Response[24];
}/* [public,flag(LIBNDR_PRINT_ARRAY_HEX)] */;

struct LMv2_RESPONSE {
	uint8_t Response[16];
	uint8_t ChallengeFromClient[8];
}/* [public,flag(LIBNDR_PRINT_ARRAY_HEX)] */;

union ntlmssp_LM_RESPONSE {
	struct LM_RESPONSE v1;/* [case(24)] */
}/* [nodiscriminant] */;

struct NTLM_RESPONSE {
	uint8_t Response[24];
}/* [flag(LIBNDR_PRINT_ARRAY_HEX),public] */;

struct NTLMv2_CLIENT_CHALLENGE {
	uint8_t RespType;/* [value] */
	uint8_t HiRespType;/* [value] */
	uint16_t Reserved1;
	uint32_t Reserved2;
	NTTIME TimeStamp;
	uint8_t ChallengeFromClient[8];
	uint32_t Reserved3;
	struct AV_PAIR_LIST AvPairs;/* [subcontext(0),flag(LIBNDR_FLAG_REMAINING)] */
}/* [flag(LIBNDR_PRINT_ARRAY_HEX)] */;

struct NTLMv2_RESPONSE {
	uint8_t Response[16];
	struct NTLMv2_CLIENT_CHALLENGE Challenge;
}/* [public,flag(LIBNDR_PRINT_ARRAY_HEX)] */;

union ntlmssp_NTLM_RESPONSE {
	struct NTLM_RESPONSE v1;/* [case(0x18)] */
	struct NTLMv2_RESPONSE v2;/* [default] */
}/* [nodiscriminant,public] */;

struct MIC {
	uint8_t MIC[16];
}/* [flag(LIBNDR_PRINT_ARRAY_HEX)] */;

struct AUTHENTICATE_MESSAGE {
	const char *Signature;/* [value("NTLMSSP"),charset(DOS)] */
	enum ntlmssp_MessageType MessageType;/* [value(NtLmAuthenticate)] */
	uint16_t LmChallengeResponseLen;
	uint16_t LmChallengeResponseMaxLen;/* [value(LmChallengeResponseLen)] */
	union ntlmssp_LM_RESPONSE *LmChallengeResponse;/* [subcontext(0),relative,subcontext_size(LmChallengeResponseLen),switch_is(LmChallengeResponseLen)] */
	uint16_t NtChallengeResponseLen;
	uint16_t NtChallengeResponseMaxLen;/* [value(NtChallengeResponseLen)] */
	union ntlmssp_NTLM_RESPONSE *NtChallengeResponse;/* [switch_is(NtChallengeResponseLen),relative,subcontext_size(NtChallengeResponseMaxLen),subcontext(0)] */
	uint16_t DomainNameLen;/* [value(ndr_ntlmssp_string_length(NegotiateFlags,DomainName))] */
	uint16_t DomainNameMaxLen;/* [value(DomainNameLen)] */
	const char * DomainName;/* [subcontext_size(DomainNameLen),flag(ndr_ntlmssp_negotiated_string_flags(r->NegotiateFlags)),relative,subcontext(0)] */
	uint16_t UserNameLen;/* [value(ndr_ntlmssp_string_length(NegotiateFlags,UserName))] */
	uint16_t UserNameMaxLen;/* [value(UserNameLen)] */
	const char * UserName;/* [subcontext(0),subcontext_size(UserNameLen),flag(ndr_ntlmssp_negotiated_string_flags(r->NegotiateFlags)),relative] */
	uint16_t WorkstationLen;/* [value(ndr_ntlmssp_string_length(NegotiateFlags,Workstation))] */
	uint16_t WorkstationMaxLen;/* [value(WorkstationLen)] */
	const char * Workstation;/* [relative,flag(ndr_ntlmssp_negotiated_string_flags(r->NegotiateFlags)),subcontext_size(WorkstationLen),subcontext(0)] */
	uint16_t EncryptedRandomSessionKeyLen;/* [value(EncryptedRandomSessionKey->length)] */
	uint16_t EncryptedRandomSessionKeyMaxLen;/* [value(EncryptedRandomSessionKeyLen)] */
	DATA_BLOB *EncryptedRandomSessionKey;/* [subcontext_size(EncryptedRandomSessionKeyLen),relative,subcontext(0)] */
	uint32_t NegotiateFlags;
	union ntlmssp_Version Version;/* [switch_is(NegotiateFlags&NTLMSSP_NEGOTIATE_VERSION)] */
}/* [public,flag(LIBNDR_FLAG_REMAINING)] */;

struct NTLMSSP_MESSAGE_SIGNATURE {
	uint32_t Version;/* [value(NTLMSSP_SIGN_VERSION)] */
	uint32_t RandomPad;
	uint32_t Checksum;
	uint32_t SeqNum;
}/* [public] */;

struct NTLMSSP_MESSAGE_SIGNATURE_NTLMv2 {
	uint32_t Version;/* [value(NTLMSSP_SIGN_VERSION)] */
	uint8_t Checksum[8];
	uint32_t SeqNum;
}/* [flag(LIBNDR_PRINT_ARRAY_HEX),public] */;


struct decode_NEGOTIATE_MESSAGE {
	struct {
		struct NEGOTIATE_MESSAGE negotiate;
	} in;

};


struct decode_CHALLENGE_MESSAGE {
	struct {
		struct CHALLENGE_MESSAGE challenge;
	} in;

};


struct decode_AUTHENTICATE_MESSAGE {
	struct {
		struct AUTHENTICATE_MESSAGE authenticate;
	} in;

};


struct decode_NTLMv2_CLIENT_CHALLENGE {
	struct {
		struct NTLMv2_CLIENT_CHALLENGE challenge;
	} in;

};


struct decode_NTLMv2_RESPONSE {
	struct {
		struct NTLMv2_RESPONSE response;
	} in;

};

#endif /* _HEADER_ntlmssp */
#endif /* _PIDL_HEADER_ntlmssp */
