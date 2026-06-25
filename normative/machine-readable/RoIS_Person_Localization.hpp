#ifndef _OMG_ROIS_PERSON_LOCALIZATION_H_
#define _OMG_ROIS_PERSON_LOCALIZATION_H_

/**************************************/
/* RoIS_Person_Localization.h  */
/**************************************/
#include <RoIS_Common.hpp>

namespace Person_Localization
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
	  void person_localized(
		DateTime timestamp,
		RoIS_IdentifierList person_ref,
		std::vector<RoLo::Architecture::Data> position_data
	  );
  };
};

#endif
