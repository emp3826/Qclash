#pragma once
#include "base/QvBase.hpp"
#include "utils/QvHelpers.hpp"

namespace Qvmessocket::core::connection::serialization
{
    const inline QString QV2RAY_SERIALIZATION_COMPLEX_CONFIG_PLACEHOLDER = "(N/A)";
    const inline QString QV2RAY_SSD_DEFAULT_NAME_PATTERN = "%1 - %2 (rate %3)";
    QList<std::pair<QString, CONFIGROOT>> ConvertConfigFromString(const QString &link, QString *aliasPrefix, QString *errMessage,
                                                                  QString *newGroupName = nullptr);
    const QString ConvertConfigToString(const ConnectionGroupPair &id, bool isSip002 = true);
    const QString ConvertConfigToString(const QString &alias, const QString &groupName, const CONFIGROOT &server, bool isSip002 = true);

    namespace vmess
    {
        CONFIGROOT Deserialize(const QString &vmess, QString *alias, QString *errMessage);
        const QString Serialize(const StreamSettingsObject &transfer, const VMessServerObject &server, const QString &alias);
    }

    namespace vmess_new
    {
        CONFIGROOT Deserialize(const QString &vmess, QString *alias, QString *errMessage);
        const QString Serialize(const StreamSettingsObject &transfer, const VMessServerObject &server, const QString &alias);
    }

    namespace ss
    {
        CONFIGROOT Deserialize(const QString &ss, QString *alias, QString *errMessage);
        const QString Serialize(const ShadowSocksServerObject &server, const QString &alias, bool isSip002);
    }

    namespace ssd
    {
        QList<std::pair<QString, CONFIGROOT>> Deserialize(const QString &uri, QString *groupName, QStringList *logList);
    }

}

using namespace Qvmessocket::core;
using namespace Qvmessocket::core::connection;
using namespace Qvmessocket::core::connection::serialization;
