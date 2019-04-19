#include <iostream>

#include "agora_api.h"
#include "record.h"
using namespace std;
#ifdef __cplusplus
extern "C" {
#endif

AGORA_API RecordingEnginex* CreateRecordingEngine(){
   return (RecordingEnginex*)new RecordingEngine();
}

AGORA_API void SetOnErrorEventHandler(RecordingEnginex* handler, void* onError){
   ((RecordingEngine*)handler)->SetonError((ponError)onError);
}


#ifdef __cplusplus
};
#endif
