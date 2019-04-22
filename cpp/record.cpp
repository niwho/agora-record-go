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

int RecordingEngine::setVideoMixLayout(){
    return 0;
}

bool RecordingEngine::leaveChannel(){
    if (m_recorder) {
        m_recorder->leaveChannel();
        m_stopped = true;
      }

      return true;
}

bool RecordingEngine::release(){
if (m_recorder) {
    m_recorder->release();
    m_recorder = NULL;
  }

  return true;
}

bool RecordingEngine::stopped() const{
    return m_stopped;
}