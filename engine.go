package agora_record_go

/*
#cgo CFLAGS: -I${SRCDIR}/cpp
#cgo LDFLAGS: -L/usr/local/lib  -L${SRCDIR}/cpp -lRecordEngine -lmyagora

#include <stdlib.h>
#include "cpp/agora_api.h"
//#include <rocketmq/CPushConsumer.h>

//extern int consumeMessageCallback(CPushConsumer *consumer, CMessageExt *msg);
//
//int callback_cgo(CPushConsumer *consumer, CMessageExt *msg) {
//	return consumeMessageCallback(consumer, msg);
//}
*/
import "C"

type AgoraRecord struct{
	RecordingEnginex *C.struct_RecordingEnginex
}

func (ar *AgoraRecord) NewRecordingEnginex(){
	ar.RecordingEnginex = C.CreateRecordingEngine()
}