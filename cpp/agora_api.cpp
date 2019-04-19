#include "agora_api.h"
#include "record.h"

#ifdef __cplusplus
extern "C" {
#endif

AGORA_API RecordingEnginex* CreateRecordingEngine(){
   return (RecordingEnginex*)new RecordingEngine();
}

AGORA_API SetOnErrorEventHandler(RecordingEnginex* handler, void* onError){
   ((RecordingEngine*)handler)->SetonError((ponError)onError);
}


#ifdef __cplusplus
};
#endif