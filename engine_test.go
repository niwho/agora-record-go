package agora_record_go


import (
	"testing"
	"fmt"
	)

func TestEngine(t *testing.T) {
	engine := AgoraRecord{}
	engine.NewRecordingEnginex()
	fmt.Println(engine)
}