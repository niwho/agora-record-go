#include "record.h"

int RecordingEngine::createChannel(const string &appid, const string &channelKey, const string &name,
    uint32_t uid,
    bool decodeAudio, bool decodeVideo,
    agora::recording::RecordingConfig &config)
{
  if ((m_recorder = agora::recording::IRecordingEngine::createAgoraRecordingEngine(appid.c_str(), this)) == NULL)
    return 0;


  return m_recorder->joinChannel(channelKey.c_str(), name.c_str(), uid, config);
}