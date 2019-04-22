#ifndef __C_EVENT_H__
#define __C_EVENT_H__

#include <iostream>
#include "common.h"
#include "include/IAgoraRecordingEngine.h"
//#include "include/base/atomic.h"
#include "user_join_info.h"
#include "agora_api.h"
#include <atomic>

using namespace agora::recording;
using namespace std;



//typedef agora::recording::RecordingConfig RecordingConfig;
typedef std::atomic<bool> atomic_bool_t;


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
    if (m_onError!=NULL){
      m_onError((RecordingEnginex*)this, error);
    }
  }
  void onWarning(int warn){
    if (m_onWarning!=NULL){
      this->m_onWarning((RecordingEnginex*)this, warn);
    }
  }

  void onJoinChannelSuccess(const char * channelId, uid_t uid){
      this->m_onJoinChannelSuccess((RecordingEnginex*)this, channelId, uid);
  }
  void onLeaveChannel(){
      this->m_onLeaveChannel((RecordingEnginex*)this);
  };

  void onUserJoined(uid_t uid, agora::recording::UserJoinInfos &infos){
      ::UserJoinInfos * pinfos  = (::UserJoinInfos *)(&infos);
      this->m_onUserJoined((RecordingEnginex*)this, uid, pinfos);
  }
  void onUserOffline(uid_t uid, USER_OFFLINE_REASON_TYPE reason){
      this->m_onUserOffline((RecordingEnginex*)this,uid, reason);
  }

  void SetonError(ponError onError){
      this->m_onError = onError;
  }

  void SetonWarning(ponWarning onWarning){
      this->m_onWarning = onWarning;
   }

  void SetonJoinChannelSuccess(ponJoinChannelSuccess onJoinChannelSuccess){
      this->m_onJoinChannelSuccess = onJoinChannelSuccess;
  }
  void SetonLeaveChannel(ponLeaveChannel onLeaveChannel){
      this->m_onLeaveChannel = onLeaveChannel;
  }

    void SetonUserJoined(ponUserJoined onUserJoined){
      this->m_onUserJoined = onUserJoined;
  }

  void SetonUserOffline(ponUserOffline onUserOffline){
      this->m_onUserOffline = onUserOffline;
  }

  int setVideoMixLayout();
  bool leaveChannel();
  bool release();
  bool stopped() const;

private:
  ponError m_onError;
  ponWarning m_onWarning;
  ponJoinChannelSuccess m_onJoinChannelSuccess;
  ponLeaveChannel m_onLeaveChannel;
  ponUserJoined m_onUserJoined;
  ponUserOffline m_onUserOffline;

  atomic_bool_t m_stopped;

  agora::recording::IRecordingEngine *m_recorder;



};
#endif