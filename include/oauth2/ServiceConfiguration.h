#ifndef O2SERVICECONFIGURATION_H_
#define O2SERVICECONFIGURATION_H_

#include <string>

namespace OAuth2
{
    enum GrantType {AUTH_CODE_GRANT, IMPLICIT_GRANT,
        OWNER_CREDENTIALS_GRANT, CLIENT_CREDENTIALS_GRANT};

    /**
     * Groups OAuth 2.0 config values
     */
    class ServiceConfiguration
    {
        //TODO: Remove when ServiceBuilder will be ready.
        friend class ServiceTests2;

    public:
        GrantType getGrantType() const;

        /**
         * Get 'grant_type' parameter string, e.g. 'authorization_code' for Authorization Code Grant
         * @throws runtime_error Throws exception if there is no 'grant_type' for given grant type
         */
        std::string getGrantTypeString() const;

        /**
         * Get 'response_type' parameter string, e.g. 'code' for Authorization Code Grant
         * @throws runtime_error Throws exception if there is no
         * 'response_type' for given grant type
         */
        std::string getResponseType() const;

        const std::string &getAuthEndpoint() const;
        const std::string &getTokenEndpoint() const;
        const std::string &getClientId() const;
        const std::string &getRedirectUri() const;
        const std::string &getScope() const;

        const std::string &getUsername() const;
        const std::string &getPassword() const;

    private:
        friend class ServiceBuilder;
        /**
         * @param grantType OAuth 2.0 Authorization method
         * @param authCodeEndpoint URL to obtain an authorization code
         * @param tokenEndpoint URL to obtain an access token
         * @param clientId ID of the client
         * @param redirectUri URL to redirect the user after access was granted
         * @param scope Scope of the access request
         * @param username Resource owner username,
         * used for Resource Owner Password Credentials Grant
         * @param password Resource owner Password,
         * used for Resource Owner Password Credentials Grant
         */
        ServiceConfiguration(GrantType grantType, const std::string &authCodeEndpoint,
                const std::string &tokenEndpoint, const std::string &clientId,
                const std::string &redirectUri, const std::string &scope,
                const std::string &username, const std::string &password);

    private:
        GrantType grantType;
        std::string authEndpoint;
        std::string tokenEndpoint;
        std::string clientId;
        std::string redirectUri;
        std::string scope;
        std::string username;
        std::string password;
    };
}
#endif
