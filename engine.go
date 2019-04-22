package main

/*
#cgo LDFLAGS: -L${SRCDIR}/cpp/libs  -L${SRCDIR}/cpp -lRecordEngine -lmyagora -lstdc++

#include "cpp/agora_api.h"
extern void OnUserJoinedCallBack(RecordingEnginex *record ,unsigned int uid);

static void OnUserJoinedCallBack_cgo(RecordingEnginex *record ,unsigned int uid){
	OnUserJoinedCallBack(record, uid);
}

*/
import "C"

type AgoraRecord struct {
	RecordingEnginex *C.struct_RecordingEnginex
}

func (ar *AgoraRecord) NewRecordingEnginex() {
	ar.RecordingEnginex = C.CreateRecordingEngine()
}

func main() {
	ag := AgoraRecord{}
	ag.NewRecordingEnginex()
}
//export OnUserJoinedCallBack
func OnUserJoinedCallBack(record *C.RecordingEnginex,uid C.uint) {
}
