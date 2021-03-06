#include <oauth1/Token.h>

#include <gtest/gtest.h>

namespace OAuthTesting
{
    class TokenTests: public testing::Test
    {
    };

    TEST_F(TokenTests, parse_valid)
    {
        OAuth1::Token token("oauth_token=hh5s93j4hdidpola&"
                "oauth_token_secret=hdhd0244k9j7ao03&oauth_callback_confirmed=true");
        ASSERT_EQ("hh5s93j4hdidpola", token.getToken());
        ASSERT_EQ("hdhd0244k9j7ao03", token.getSecret());
    }

    TEST_F(TokenTests, parse_invalid)
    {
        ASSERT_THROW({OAuth1::Token token("data=value&"
                "oauth_token_secret=hdhd0244k9j7ao03&oauth_callback_confirmed=true");}
            ,std::invalid_argument);
        ASSERT_THROW({OAuth1::Token token("completely invalid data");}
            ,std::invalid_argument);
    }
}
