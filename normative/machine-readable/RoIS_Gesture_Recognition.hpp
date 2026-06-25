#ifndef _OMG_ROIS_GESTURE_RECOGNITION_H_
#define _OMG_ROIS_GESTURE_RECOGNITION_H_

/***************************************/
/* RoIS_Gesture_Recognition.h  */
/***************************************/
#include <RoIS_Common.hpp>

namespace Gesture_Recognition
{
  class Command : public RoIS_Common::Command{
  };

  class Query : public RoIS_Common::Query{
    public:
	  ReturnCode_t get_parameter(
		RoIS_IdentifierList& recognizable_gestures
	  );
  };

  class Event : public RoIS_Common::Event{
    public:
	  void gesture_recognized(
		DateTime timestamp,
		RoIS_IdentifierList gesture_ref
	  );
  };
};

#endif
