#pragma once
#include "base/QvBase.hpp"

static const inline QStringList V2RayLogLevel = { "none", "debug", "info", "warning", "error" };

namespace Qvmessocket::core::connection::generation
{
    namespace routing
    {
        enum RuleType
        {
            RULE_DOMAIN,
            RULE_IP
        };
        ROUTERULE GenerateSingleRouteRule(RuleType t, const QString &str, const QString &outboundTag, const QString &type = "field");
        ROUTERULE GenerateSingleRouteRule(RuleType t, const QStringList &list, const QString &outboundTag, const QString &type = "field");
        ROUTING GenerateRoutes(bool enableProxy, bool bypassCN, bool bypassLAN, const QString &outboundTag, const QvConfig_Route &routeConfig);
    }

    namespace misc
    {
        QJsonObject GenerateAPIEntry(const QString &tag, bool withHandler = true, bool withLogger = true, bool withStats = true);
    }

    namespace inbounds
    {
        INBOUNDSETTING GenerateDokodemoIN(const QString &address, int port, const QString &network, int timeout = 0, bool followRedirect = false);
        INBOUNDSETTING GenerateHTTPIN(bool auth, const QList<AccountObject> &accounts, int timeout = 300, bool allowTransparent = true);
        INBOUNDSETTING GenerateSocksIN(const QString &auth, const QList<AccountObject> &_accounts, bool udp = false, const QString &ip = "127.0.0.1");
        INBOUNDS GenerateDefaultInbounds();
        QJsonObject GenerateSniffingObject(bool enabled, QList<QString> destOverride, bool metadataOnly = false);
        INBOUND GenerateInboundEntry(const QString &tag,               //
                                     const QString &protocol,          //
                                     const QString &listen,            //
                                     int port,                         //
                                     const INBOUNDSETTING &settings,   //
                                     const QJsonObject &sniffing = {}, //
                                     const QJsonObject &allocate = {});
    }

    namespace outbounds
    {
        OUTBOUNDSETTING GenerateFreedomOUT(const QString &domainStrategy, const QString &redirect);
        OUTBOUNDSETTING GenerateShadowSocksOUT(const QList<ShadowSocksServerObject> &servers);
        OUTBOUNDSETTING GenerateShadowSocksServerOUT(const QString &address, int port, const QString &method, const QString &password);
        OUTBOUNDSETTING GenerateHTTPSOCKSOut(const QString &address, int port, bool useAuth, const QString &username, const QString &password);
        OUTBOUND GenerateOutboundEntry(const QString &tag,                //
                                       const QString &protocol,           //
                                       const OUTBOUNDSETTING &settings,   //
                                       const QJsonObject &streamSettings, //
                                       const QJsonObject &mux = {},       //
                                       const QString &sendThrough = "0.0.0.0");
    }

    namespace filters
    {
        void OutboundMarkSettingFilter(CONFIGROOT &root, const int mark);
        void RemoveEmptyMuxFilter(CONFIGROOT &root);
        void DNSInterceptFilter(CONFIGROOT &root, const bool have_tproxy, const bool have_tproxy_v6, const bool have_socks);
        void BypassBTFilter(CONFIGROOT &root);
        void mKCPSeedFilter(CONFIGROOT &root);
        void FillupTagsFilter(CONFIGROOT &root, const QString &subKey);
    }

}

using namespace Qvmessocket::core;
using namespace Qvmessocket::core::connection;
using namespace Qvmessocket::core::connection::generation;
using namespace Qvmessocket::core::connection::generation::filters;
using namespace Qvmessocket::core::connection::generation::inbounds;
using namespace Qvmessocket::core::connection::generation::outbounds;
using namespace Qvmessocket::core::connection::generation::routing;
using namespace Qvmessocket::core::connection::generation::misc;
