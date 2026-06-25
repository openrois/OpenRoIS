#ifndef _OMG_ROIS_PERSON_DETECTION_H_
#define _OMG_ROIS_PERSON_DETECTION_H_

/***********************************/
/* RoIS_Person_Detection.h  */
/***********************************/
#include <RoIS_Common.hpp>

namespace Person_Detection
{
  class Command : public RoIS_Common::Command{
  };

  class Query : public RoIS_Common::Query{
  };

  class Event : public RoIS_Common::Event{
    public:
	  void person_detected(
		DateTime timestamp,
		Integer number
	  );
  };
};

#endif
