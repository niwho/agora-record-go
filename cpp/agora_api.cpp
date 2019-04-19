#include <iostream>

#include "agora_api.h"
#include "record.h"
using namespace std;


AGORA_API RecordingEnginex* CreateRecordingEngine(){
   return (RecordingEnginex*)new RecordingEngine();
}

