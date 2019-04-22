#include <iostream>

#include "agora_api.h"
#include "record.h"
using namespace std;


AGORA_API RecordingEnginex* CreateRecordingEngine(){
   return (RecordingEnginex*)new RecordingEngine();
}

AGORA_API void SetOnErrorEventHandler(RecordingEnginex* record, void* onError){
    ((RecordingEngine*)record)->SetonError((ponError)onError);
}

AGORA_API void SetOnUserJoinedCallBack(RecordingEnginex* record, void* onUserJoined){
     ((RecordingEngine*)record)->SetonUserJoined((ponUserJoined)onUserJoined);
}

AGORA_API int CreateChannel(RecordingEnginex* record, const char *appid,
    const char*channelKey, const char *name, uint32_t uid, bool decodeAudio,
    bool decodeVideo, ::RecordingConfig*config){

    agora::recording::RecordingConfig* cfg = (agora::recording::RecordingConfig*) config;
    return  ((RecordingEngine*)record)->createChannel(appid, channelKey, name, uid, decodeAudio,
            decodeVideo, *cfg);
}

AGORA_API int SetVideoMixLayout(RecordingEnginex* record){
     ((RecordingEngine*)record)->setVideoMixLayout();
     return 0;
}
AGORA_API bool LeaveChannel(RecordingEnginex* record){
    ((RecordingEngine*)record)->leaveChannel();
    return 0;
}
AGORA_API bool Release(RecordingEnginex* record){
    ((RecordingEngine*)record)->setVideoMixLayout();
    return 0;

}
AGORA_API bool Stopped(RecordingEnginex* record){
    return ((RecordingEngine*)record)->stopped();
}