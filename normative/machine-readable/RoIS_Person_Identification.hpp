#ifndef _OMG_ROIS_PERSON_IDENTIFICATION_H_
#define _OMG_ROIS_PERSON_IDENTIFICATION_H_

/***************************************/
/* RoIS_Person_Identification.h  */
/***************************************/
#include <RoIS_Common.hpp>

namespace Person_Identification
{
  class Command : public RoIS_Common::Command{
  };

  class Query : public RoIS_Common::Query{
  };

  class Event : public RoIS_Common::Event{
    public:
	  void person_identified(
		DateTime timestamp,
		RoIS_IdentifierList person_ref
	  );
  };
};

#endif

