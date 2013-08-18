#include <oauth2/ServiceConfiguration.h>

#include <cassert>

namespace OAuth2
{
    ServiceConfiguration::ServiceConfiguration(GrantType grantType,
            const std::string &authCodeEndpoint, const std::string &tokenEndpoint,
            const std::string &clientId, const std::string &redirectUri,
            const std::string &scope, const std::string &username,
            const std::string &password) :
            grantType(grantType), authEndpoint(authCodeEndpoint),
            tokenEndpoint(tokenEndpoint), clientId(clientId),
            redirectUri(redirectUri), scope(scope),
            username(username), password(password)
    {
    }

    GrantType ServiceConfiguration::getGrantType() const
    {
        return grantType;
    }

    std::string ServiceConfiguration::getGrantTypeString() const
    {
        switch (grantType) {
        case AUTH_CODE_GRANT:
            return "authorization_code";
        case OWNER_CREDENTIALS_GRANT:
            return "password";
        case CLIENT_CREDENTIALS_GRANT:
            return "client_credentials";
        default:
            assert(false && "This grant type doesn't have an associated string");
        }
    }

    std::string ServiceConfiguration::getResponseType() const
    {
        switch (grantType) {
        case AUTH_CODE_GRANT:
            return "code";
        case IMPLICIT_GRANT:
            return "token";
        default:
            assert(false && "This grant type doesn't have a response type");
        }
    }

    const std::string &ServiceConfiguration::getAuthEndpoint() const
    {
        return authEndpoint;
    }

    const std::string &ServiceConfiguration::getTokenEndpoint() const
    {
        return tokenEndpoint;
    }

    const std::string &ServiceConfiguration::getClientId() const
    {
        return clientId;
    }

    const std::string &ServiceConfiguration::getRedirectUri() const
    {
        return redirectUri;
    }

    const std::string &ServiceConfiguration::getScope() const
    {
        return scope;
    }

    const std::string &ServiceConfiguration::getUsername() const
    {
        return username;
    }

    const std::string &ServiceConfiguration::getPassword() const
    {
        return password;
    }
}
