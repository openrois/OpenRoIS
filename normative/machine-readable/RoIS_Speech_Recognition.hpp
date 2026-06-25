#ifndef _OMG_ROIS_SPEECH_RECOGNITION_H_
#define _OMG_ROIS_SPEECH_RECOGNITION_H_

/**************************************/
/* RoIS_Speech_Recognition.h  */
/**************************************/
#include <RoIS_Common.hpp>

namespace Speech_Recognition
{
  class Command : public RoIS_Common::Command{
    public:
	  ReturnCode_t set_parameter(
		std::vector<std::string> languages,
		std::string grammer,
		std::string rule
	  );
  };

  class Query : public RoIS_Common::Query{
    public:
	  ReturnCode_t get_parameter(
		std::vector<std::string>& recognizable_languages,
		std::vector<std::string>& languages,
		std::string& grammer,
		std::string& rule
	  );
  };

  class Event : public RoIS_Common::Event{
    public:
	  void speech_recognized(
		DateTime timestamp,
		std::vector<std::string> recognized_text
	  );
	  void speech_input_started(
		DateTime timestamp
	  );
	  void speech_input_finished(
		DateTime timestamp
	  );
  };
};

#endif

