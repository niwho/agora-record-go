#include <string>
#include <stdlib.h>
#include <string.h>
#include "video_mixing_layout.h"
#include "include/IAgoraRecordingEngine.h"


AGORA_API VideoMixingLayout* GetVideoMixingLayoutDefault(){
 return (VideoMixingLayout*)new agora::recording::VideoMixingLayout();
}

AGORA_API int VMLSetCanvasWidth(VideoMixingLayout* vml,int canvasWidth){
    ((agora::recording::VideoMixingLayout*)(vml))-> canvasWidth = canvasWidth;
    return 0;
}

AGORA_API int VMLSetCanvasHeight(VideoMixingLayout*vml,int canvasHeight){
     ((agora::recording::VideoMixingLayout*)(vml))->canvasHeight = canvasHeight;
     return 0;
}

AGORA_API int VMLSetBackgroundColor(VideoMixingLayout*vml, const char* backgroundColor){
    //
     char* m = (char*)malloc(strlen(backgroundColor)+1);
     strcpy(m, backgroundColor);
     ((agora::recording::VideoMixingLayout*)(vml))->backgroundColor = (const char*)m;
     return 0;
}

AGORA_API int VMLSetAppData(VideoMixingLayout*vml, const char* appData, unsigned int appDataLength){
    //
     char* m = (char*)malloc(appDataLength);
     memcpy(m, appData, appDataLength);
     ((agora::recording::VideoMixingLayout*)(vml))-> appData = m;
     ((agora::recording::VideoMixingLayout*)(vml))->appDataLength = appDataLength;
     return 0;
}


AGORA_API int VMLNewRegions(VideoMixingLayout*vml, int count){
    const agora::recording::VideoMixingLayout::Region* oldRegions =  ((agora::recording::VideoMixingLayout*)(vml))->regions;
    if (oldRegions != NULL){
        delete []oldRegions;
    }
    ((agora::recording::VideoMixingLayout*)(vml))->regions = new agora::recording::VideoMixingLayout::Region[count];
    return 0;
}

AGORA_API Region* VMLGetRegion(VideoMixingLayout*vml, int idx){
    const agora::recording::VideoMixingLayout::Region* regions =  ((agora::recording::VideoMixingLayout*)(vml))->regions;
    if (regions == NULL){
        return NULL;
    }
    return (Region*)(regions+idx);
}


AGORA_API int RegionSetUid(Region* region, unsigned int uid){
    ((agora::recording::VideoMixingLayout::Region*)region)->uid = uid;
    return 0;
}
AGORA_API int RegionSetX(Region*region, double x){
    ((agora::recording::VideoMixingLayout::Region*)region)-> x= x;
    return 0;
}
AGORA_API int RegionSetY(Region*region, double y){
    ((agora::recording::VideoMixingLayout::Region*)region)->y = y;
    return 0;
}
AGORA_API int RegionSetWidth(Region*region, double width){
    ((agora::recording::VideoMixingLayout::Region*)region)->width = width;
    return 0;
}
AGORA_API int RegionSetHeight(Region*region, double height){
    ((agora::recording::VideoMixingLayout::Region*)region)->height = height;
    return 0;
}
AGORA_API int RegionSetZOrder(Region*region, int zOrder){
    ((agora::recording::VideoMixingLayout::Region*)region)->zOrder = zOrder;
    return 0;
}
AGORA_API int RegionSetAlpha(Region*region, double alpha){
    ((agora::recording::VideoMixingLayout::Region*)region)->alpha = alpha;
    return 0;
}

AGORA_API int RegionSetRenderMode(Region*region, int renderMode){
    ((agora::recording::VideoMixingLayout::Region*)region)->renderMode = renderMode;
    return 0;
}

