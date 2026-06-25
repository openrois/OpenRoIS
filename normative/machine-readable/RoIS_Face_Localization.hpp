#ifndef _OMG_ROIS_FACE_LOCALIZATION_H_
#define _OMG_ROIS_FACE_LOCALIZATION_H_

/***********************************/
/* RoIS_Face_Localization.h  */
/***********************************/
#include <RoIS_Common.hpp>

namespace Face_Localization
{
  class Command : public RoIS_Common::Command{
    public:
	  ReturnCode_t set_parameter(
        Integer detection_threshold,
		Integer minimum_interval
      );					
  };

  class Query : public RoIS_Common::Query{
    public:
      ReturnCode_t get_parameter(
        Integer& detection_threshold,
		Integer& minimum_interval
      );					
  };

  class Event : public RoIS_Common::Event{
    public:
      void face_localized(
		DateTime timestamp,
		RoIS_IdentifierList face_ref,
		std::vector<RoLo::Architecture::Data> position_data
      );
  };
};

#endif
