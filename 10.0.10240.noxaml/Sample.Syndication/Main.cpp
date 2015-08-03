#include "pch.h"

using namespace std;
using namespace Modern;

using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::Web::Syndication;

std::future<void> Sample()
{
    Uri const uri(L"http://kennykerr.ca/feed");
    SyndicationClient const client;

    SyndicationFeed feed = await client.RetrieveFeedAsync(uri);

    for (SyndicationItem const & item : feed.Items())
    {
        String title = item.Title().Text();

        printf("%ls\n", title.Buffer());
    }
}

int main()
{
    Initialize();

    Sample().get();
}

