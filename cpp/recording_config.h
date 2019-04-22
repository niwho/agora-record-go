#ifndef __C_RECORDING_CONFIG_H__
#define __C_RECORDING_CONFIG_H__

#include "common.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct RecordingConfig RecordingConfig;

AGORA_API RecordingConfig* GetRecordingConfigDefault();
AGORA_API int RCSetChannelProfileType(RecordingConfig*,int);
AGORA_API int RCSetIsAudioOnly(RecordingConfig*,bool);
AGORA_API int RCSetIsMixinEnabled(RecordingConfig*,bool);
AGORA_API int RCSetDecryptionMode(RecordingConfig*,const char*);
AGORA_API int RCSetSecret(RecordingConfig*,const char*);
AGORA_API int RCSetIdleLimitSec(RecordingConfig*,int);
AGORA_API int RCSetAppliteDir(RecordingConfig*,const char*);
AGORA_API int RCSetLowUdpPort(RecordingConfig*,int);
AGORA_API int RCSetHighUdpPort(RecordingConfig*,int);

AGORA_API int RCGetChannelProfileType(RecordingConfig*);
AGORA_API bool RCGetIsAudioOnly(RecordingConfig*);
AGORA_API bool RCGetIsMixinEnabled(RecordingConfig*);
AGORA_API const char* RCGetDecryptionMode(RecordingConfig*);
AGORA_API const char* RCGetSecret(RecordingConfig*);
AGORA_API int RCGetIdleLimitSec(RecordingConfig);
AGORA_API const char* RCGetAppliteDir(RecordingConfig*);
AGORA_API int RCGetLowUdpPort(RecordingConfig*);
AGORA_API int RCGetHighUdpPort(RecordingConfig*);

#ifdef __cplusplus
};
#endif
#endif  //__C_RECORDING_CONFIG_H__

