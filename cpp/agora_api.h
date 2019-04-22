#ifndef __C_AGORA_API_H__
#define __C_AGORA_API_H__

#include "common.h"
#include "recording_config.h"
#include <stdlib.h>
#include "user_join_info.h"
#ifdef __cplusplus
extern "C" {
#endif

typedef struct RecordingEnginex RecordingEnginex;


typedef void (*ponError)(RecordingEnginex*,int);
typedef void (*ponWarning)(RecordingEnginex*,int);
typedef void (*ponJoinChannelSuccess)(RecordingEnginex*,const char *, uid_t);
typedef void (*ponLeaveChannel)(RecordingEnginex*);
typedef void (*ponUserJoined)(RecordingEnginex*,uid_t , UserJoinInfos*);
typedef void (*ponUserOffline)(RecordingEnginex*,uid_t , int);


AGORA_API RecordingEnginex* CreateRecordingEngine();
AGORA_API void SetOnErrorEventCallBack(RecordingEnginex* handler, void* onError);
AGORA_API void SetOnUserJoinedCallBack(RecordingEnginex* handler, void* onUserJoined);

AGORA_API int CreateChannel(RecordingEnginex* record, const char *appid,
    const char *channelKey, const char* name, uint32_t uid, bool decodeAudio,
    bool decodeVideo, RecordingConfig*config);

AGORA_API int SetVideoMixLayout(RecordingEnginex* handler);
AGORA_API bool LeaveChannel(RecordingEnginex* handler);
AGORA_API bool Release(RecordingEnginex* handler);
AGORA_API bool Stopped(RecordingEnginex* handler);

#ifdef __cplusplus
};
#endif
#endif  //__C_AGORA_API_H__
