#ifndef _OMG_ROIS_SPEECH_SYNTHESIS_H_
#define _OMG_ROIS_SPEECH_SYNTHESIS_H_

/************************************/
/* RoIS_Speech_Synthesis.h  */
/************************************/
#include <RoIS_Common.hpp>

namespace Speech_Synthesis
{
  class Command : public RoIS_Common::Command{
    public:
	  ReturnCode_t set_parameter(
		std::string speech_text,
		std::string SSML_text,
		Integer volume,
		std::string language,
		RoIS_Identifier character
	  );
  };

  class Query : public RoIS_Common::Query{
    public:
	  ReturnCode_t get_parameter(
		std::string& speech_text,
		std::string& SSML_text,
		Integer& volume,
		std::string& language,
		RoIS_Identifier& character,
		std::vector<std::string>& synthesizable_languages,
		RoIS_IdentifierList& synthesizable_characters
	  );
  };

  class Event : public RoIS_Common::Event{
  };
};

#endif
