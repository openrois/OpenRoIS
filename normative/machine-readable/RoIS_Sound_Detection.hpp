#ifndef _OMG_ROIS_SOUND_DETECTION_H_
#define _OMG_ROIS_SOUND_DETECTION_H_

/**********************************/
/* RoIS_Sound_Detection.h  */
/**********************************/
#include <RoIS_Common.hpp>

namespace Sound_Detection
{
  class Command : public RoIS_Common::Command{
  };

  class Query : public RoIS_Common::Query{
  };

  class Event : public RoIS_Common::Event{
    public:
	  void sound_detected(
		DateTime timestamp,
		Integer number
	  );
  };
};

#endif
