#ifndef _OMG_ROIS_COMMON_H_
#define _OMG_ROIS_COMMON_H_

/***********************************/
/* RoIS_Common.h */
/***********************************/
#include <RoIS_HRI.hpp>
using namespace RoIS_HRI;

#include <RoIS_Service.hpp>
using namespace RoIS_Service;

namespace RoIS_Common{
  enum Component_Status
  {
    UNINITIALIZED,
    READY,
    BUSY,
    WARNING,
    ERROR
  };

  enum Stream_Status
  {
    STREAMING_NOT_CONNECTED,
    STREAMING_NOT_RUNNING,
    STREAMING_RUNNING,
    STREAMING_SUSPENDED,
    STREAMING_RESUMED,
  };

  class Command{
    public:
      virtual ReturnCode_t start();
      virtual ReturnCode_t stop();
      virtual ReturnCode_t suspend();
      virtual ReturnCode_t resume();
  };

  class Query{
    public:
      virtual ReturnCode_t component_status(
        Component_Status& status
      );
  };

  class Event{
  };
};

#endif
