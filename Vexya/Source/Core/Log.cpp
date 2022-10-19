#include <Core/Log.h>

namespace Vexya 
{
    std::shared_ptr<Logger> Log::s_EngineLogger;
    std::shared_ptr<Logger> Log::s_InstanceLogger;

    ErrorCode Log::initialize()
    {
        bool isCreated[2] = { false , false };

        s_EngineLogger = std::make_shared<Logger>("ENGINE", &isCreated[0]);
        s_InstanceLogger = std::make_shared<Logger>("INSTNACE", &isCreated[1]);

        if (!(isCreated[0] && isCreated[1]))
            return ErrorCode::LoggingInitializationFail;

        return ErrorCode::NoError;
    }
}
