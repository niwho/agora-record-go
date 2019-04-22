package main

/*
#cgo LDFLAGS: -L/usr/local/lib  -L${SRCDIR}/cpp -lRecordEngine -lmyagora -lstdc++

#include <stdlib.h>
#include <stdbool.h>
#include "cpp/agora_api.h"
#include "cpp/user_join_info.h"
#include "cpp/recording_config.h"

extern void OnUserJoinedCallBack(RecordingEnginex *record ,unsigned int uid, UserJoinInfos* pinfos);

void OnUserJoinedCallBack_cgo(RecordingEnginex *record ,unsigned int uid, UserJoinInfos* pinfos){
	OnUserJoinedCallBack(record, uid, pinfos);
}

*/
import "C"

import (
	"sync"
	"unsafe"
)

var funMap sync.Map
type JoinInfos struct {
	RecordingDir string
}
func cuserJoinInfosToGo(inf *C.UserJoinInfos) JoinInfos{
	infgo := JoinInfos{}
	infgo.RecordingDir = C.GoString(C.UJIGetRecordingDir(inf))
	return infgo
}

//export OnUserJoinedCallBack
func OnUserJoinedCallBack(record *C.RecordingEnginex,uid C.uint, pinfos *C.UserJoinInfos) {
	record, exist := funMap.Load(record)
	if !exist {
		return
	}

	info := cuserJoinInfosToGo(pinfos)
	record.(*AgoraRecord).OnUserJoined(info)
}

type AgoraRecord struct {
	RecordingEnginex *C.struct_RecordingEnginex
}

func (ar *AgoraRecord) NewRecordingEnginex() {
	ar.RecordingEnginex = C.CreateRecordingEngine()
	C.SetOnUserJoinedCallBack(ar.RecordingEnginex, (unsafe.Pointer(C.OnUserJoinedCallBack_cgo)))
}

func (ar *AgoraRecord) OnUserJoined(info JoinInfos) {

}

func main() {
	ag := AgoraRecord{}
	ag.NewRecordingEnginex()
}
