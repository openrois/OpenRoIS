#ifndef _OMG_ROIS_FACE_DETECTION_H_
#define _OMG_ROIS_FACE_DETECTION_H_

/*********************************/
/* RoIS_Face_Detection.h  */
/*********************************/
#include <RoIS_Common.hpp>

namespace Face_Detection
{
  class Command : public RoIS_Common::Command{
  };

  class Query : public RoIS_Common::Query{
  };

  class Event : public RoIS_Common::Event{
    public:
      void face_detected(
		DateTime timestamp,
		Integer number
	  );
  };
};

#endif
