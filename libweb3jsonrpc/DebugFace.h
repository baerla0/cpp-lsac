#ifndef JSONRPC_CPP_STUB_DEV_RPC_DEBUGFACE_H_
#define JSONRPC_CPP_STUB_DEV_RPC_DEBUGFACE_H_

#include "ModularServer.h"

namespace dev {
    namespace rpc {
        class DebugFace : public ServerInterface<DebugFace>
        {
            public:
                DebugFace()
                {
                    this->bindAndAddMethod(jsonrpc::Procedure("debug_accountRangeAt", jsonrpc::PARAMS_BY_POSITION, jsonrpc::JSON_OBJECT, "param1",jsonrpc::JSON_STRING,"param2",jsonrpc::JSON_INTEGER,"param3",jsonrpc::JSON_STRING,"param4",jsonrpc::JSON_INTEGER, NULL), &dev::rpc::DebugFace::debug_accountRangeAtI);
                    this->bindAndAddMethod(jsonrpc::Procedure("debug_traceTransaction", jsonrpc::PARAMS_BY_POSITION, jsonrpc::JSON_OBJECT, "param1",jsonrpc::JSON_STRING,"param2",jsonrpc::JSON_OBJECT, NULL), &dev::rpc::DebugFace::debug_traceTransactionI);
                    this->bindAndAddMethod(jsonrpc::Procedure("debug_storageRangeAt", jsonrpc::PARAMS_BY_POSITION, jsonrpc::JSON_OBJECT, "param1",jsonrpc::JSON_STRING,"param2",jsonrpc::JSON_INTEGER,"param3",jsonrpc::JSON_STRING,"param4",jsonrpc::JSON_STRING,"param5",jsonrpc::JSON_INTEGER, NULL), &dev::rpc::DebugFace::debug_storageRangeAtI);
                    this->bindAndAddMethod(jsonrpc::Procedure("debug_preimage", jsonrpc::PARAMS_BY_POSITION, jsonrpc::JSON_OBJECT, "param1",jsonrpc::JSON_STRING, NULL), &dev::rpc::DebugFace::debug_preimageI);
                    this->bindAndAddMethod(jsonrpc::Procedure("debug_traceBlockByNumber", jsonrpc::PARAMS_BY_POSITION, jsonrpc::JSON_OBJECT, "param1",jsonrpc::JSON_INTEGER,"param2",jsonrpc::JSON_OBJECT, NULL), &dev::rpc::DebugFace::debug_traceBlockByNumberI);
                    this->bindAndAddMethod(jsonrpc::Procedure("debug_traceBlockByHash", jsonrpc::PARAMS_BY_POSITION, jsonrpc::JSON_OBJECT, "param1",jsonrpc::JSON_STRING,"param2",jsonrpc::JSON_OBJECT, NULL), &dev::rpc::DebugFace::debug_traceBlockByHashI);
                    this->bindAndAddMethod(jsonrpc::Procedure("debug_traceCall", jsonrpc::PARAMS_BY_POSITION, jsonrpc::JSON_OBJECT, "param1",jsonrpc::JSON_OBJECT,"param2",jsonrpc::JSON_STRING,"param3",jsonrpc::JSON_OBJECT, NULL), &dev::rpc::DebugFace::debug_traceCallI);
                }
                inline virtual void debug_accountRangeAtI(const Json::Value &request, Json::Value &response)
                {
                    response = this->debug_accountRangeAt(request[0u].asString(), request[1u].asInt(), request[2u].asString(), request[3u].asInt());
                }
                inline virtual void debug_traceTransactionI(const Json::Value &request, Json::Value &response)
                {
                    response = this->debug_traceTransaction(request[0u].asString(), request[1u]);
                }
                inline virtual void debug_storageRangeAtI(const Json::Value &request, Json::Value &response)
                {
                    response = this->debug_storageRangeAt(request[0u].asString(), request[1u].asInt(), request[2u].asString(), request[3u].asString(), request[4u].asInt());
                }
                inline virtual void debug_preimageI(const Json::Value &request, Json::Value &response)
                {
                    response = this->debug_preimage(request[0u].asString());
                }
                inline virtual void debug_traceBlockByNumberI(const Json::Value &request, Json::Value &response)
                {
                    response = this->debug_traceBlockByNumber(request[0u].asInt(), request[1u]);
                }
                inline virtual void debug_traceBlockByHashI(const Json::Value &request, Json::Value &response)
                {
                    response = this->debug_traceBlockByHash(request[0u].asString(), request[1u]);
                }
                inline virtual void debug_traceCallI(const Json::Value &request, Json::Value &response)
                {
                    response = this->debug_traceCall(request[0u], request[1u].asString(), request[2u]);
                }
                virtual Json::Value debug_accountRangeAt(const std::string& param1, int param2, const std::string& param3, int param4) = 0;
                virtual Json::Value debug_traceTransaction(const std::string& param1, const Json::Value& param2) = 0;
                virtual Json::Value debug_storageRangeAt(const std::string& param1, int param2, const std::string& param3, const std::string& param4, int param5) = 0;
                virtual std::string debug_preimage(const std::string& param1) = 0;
                virtual Json::Value debug_traceBlockByNumber(int param1, const Json::Value& param2) = 0;
                virtual Json::Value debug_traceBlockByHash(const std::string& param1, const Json::Value& param2) = 0;
                virtual Json::Value debug_traceCall(const Json::Value& param1, const std::string& param2, const Json::Value& param3) = 0;
        };

    }
}
#endif //JSONRPC_CPP_STUB_DEV_RPC_DEBUGFACE_H_
