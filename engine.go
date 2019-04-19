package main

/*
#cgo LDFLAGS: -L/usr/local/lib  -L${SRCDIR}/cpp -lRecordEngine -lmyagora

#include "cpp/agora_api.h"

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
