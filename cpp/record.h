#ifndef __C_EVENT_H__
#define __C_EVENT_H__

#include "include/IAgoraRecordingEngine.h"

typedef void (*ponError)(int);
typedef void (*ponWarning)(int);
typedef void (*ponJoinChannelSuccess)(const char *, uid_t);
typedef void (*ponLeaveChannel)();
typedef void (*ponUserJoined)(uid_t , UserJoinInfos);
typedef void (*ponUserOffline)(uid_t , USER_OFFLINE_REASON_TYPE);

typedef agora::recording::RecordingConfig RecordingConfig;


class RecordingEngine: public IRecordingEngineEventHandler {
 public:
  RecordingEngine() {}

  RecordingEngine(
    ponError onError,
    ponWarning onWarning,
    ponJoinChannelSuccess onJoinChannelSuccess,
    ponLeaveChannel onLeaveChannel,
    ponUserJoined onUserJoined,
    ponUserOffline onUserOffline
  ) {
    m_onError = onError;
    m_onWarning = onWarning;
    m_onJoinChannelSuccess = onJoinChannelSuccess;
    m_onLeaveChannel = onLeaveChannel;
    m_onUserJoined = onUserJoined;
    m_onUserOffline = onUserOffline;
  }

  ~RecordingEngine() {
    if (m_recorder) {
        m_recorder->release();
      }
  }

  int createChannel(const string &appid, const string &channelKey, const string &name,
      uint32_t uid,
      bool decodeAudio, bool decodeVideo,
      agora::recording::RecordingConfig &config);

  void onError(int error){
    if this->m_onError!=NULL{
      this->m_onError(error);
    }
  }
  void onWarning(int warn){
      this->m_onWarning(warn);
  }

  void onJoinChannelSuccess(const char * channelId, uid_t uid){
      this->m_onJoinChannelSuccess(channelId, uid);
  }
  void onLeaveChannel(){
      this->m_onLeaveChannel();
  };

  void onUserJoined(uid_t uid, UserJoinInfos &infos){
      this->m_onUserJoined(uid, infos);
  }
  void onUserOffline(uid_t uid, USER_OFFLINE_REASON_TYPE reason){
      this->m_onUserOffline(uid, reason);
  }

  void SetonError(onError ponError){
      this->m_onError = onError;
  }

  void SetonWarning(onWarning ponWarning){
      this->m_onWarning = onWarning;
   }

  void SetonJoinChannelSuccess(onJoinChannelSuccess ponJoinChannelSuccess){
      this->m_onError = onError;
  }
  void SetonLeaveChannel(onError ponLeaveChannel){
      this->m_onLeaveChannel = ononLeaveChannel;
  }

    void SetonUserJoined(onUserJoined ponUserJoined){
      this->m_onUserJoined = onUserJoined;
  }

  void SetonUserOffline(onUserOffline ponUserOffline){
      this->m_onUserOffline = onUserOffline;
  }


private:
  ponError m_onError;
  ponWarning m_onWarning;
  ponJoinChannelSuccess m_onJoinChannelSuccess;
  ponLeaveChannel m_onLeaveChannel;
  ponUserJoined m_onUserJoined;
  ponUserOffline m_onUserOffline;

  agora::recording::IRecordingEngine *m_recorder;



};
#endif