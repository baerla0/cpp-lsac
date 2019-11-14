#include "LoggingProgramOptions.h"

namespace po = boost::program_options;

namespace dev
{
po::options_description createLoggingProgramOptions(unsigned _lineLength, LoggingOptions& _options)
{
    po::options_description optionsDescr("LOGGING OPTIONS", _lineLength);
    auto addLoggingOption = optionsDescr.add_options();
    addLoggingOption("log-verbosity,v", po::value<int>(&_options.verbosity)->value_name("<0 - 4>"),
        "Set the log verbosity from 0 to 4 (default: 2).");
    addLoggingOption("log-channels",
        po::value<std::vector<std::string>>(&_options.includeChannels)
            ->value_name("<channel_list>")
            ->multitoken(),
        "Space-separated list of the log channels to show (default: show all channels).");
    addLoggingOption("log-exclude-channels",
        po::value<std::vector<std::string>>(&_options.excludeChannels)
            ->value_name("<channel_list>")
            ->multitoken(),
        "Space-separated list of the log channels to hide.\n");

    return optionsDescr;
}

}  // namespace devcccc
