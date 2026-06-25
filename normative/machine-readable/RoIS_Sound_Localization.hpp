#ifndef _OMG_ROIS_SOUND_LOCALIZATION_H_
#define _OMG_ROIS_SOUND_LOCALIZATION_H_

/************************************/
/* RoIS_Sound_Localization.h  */
/************************************/

#include <RoIS_Common.hpp>

namespace Sound_Localization
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
	  void sound_localized(
		DateTime timestamp,
		RoIS_IdentifierList sound_ref,
		std::vector<RoLo::Architecture::Data> position_data
	  );
  };
};

#endif
