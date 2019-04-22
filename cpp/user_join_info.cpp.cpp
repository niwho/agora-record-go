#include <string>
#include <stdlib.h>
#include <string.h>
#include "user_join_info.h"
#include "include/IAgoraRecordingEngine.h"

AGORA_API int UJISetRecordingDir(UserJoinInfos* userJoinInfos, const char * dir){
    char* m = (char*)malloc(strlen(dir)+1);
    strcpy(m, dir);
    ((agora::recording::UserJoinInfos*)userJoinInfos)->recordingDir = m;
    return 0;
}

AGORA_API const char * UJIGetRecordingDir(UserJoinInfos* userJoinInfos){
    return  ((agora::recording::UserJoinInfos*)userJoinInfos)->recordingDir;
}