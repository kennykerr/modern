#include "pch.h"
#include <conio.h>

using namespace Modern;

using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::Web::Syndication;

int main()
{
	Initialize();

	Uri const uri(L"http://kennykerr.ca/feed");
	SyndicationClient const client;

	client.RetrieveFeedAsync(uri).Completed([](auto const & sender, AsyncStatus)
	{
		ISyndicationFeed feed = sender.GetResults();

		for (ISyndicationItem const & item : feed.Items())
		{
			String title = item.Title().Text();

			printf("%ls\n", title.Buffer());
		}
	});

	_getch();
}

