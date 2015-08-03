#include "pch.h"

using namespace std;
using namespace Modern;

using namespace Windows::Storage;
using namespace Windows::Storage::Streams;
using namespace Windows::Graphics::Imaging;
using namespace Windows::Media::Ocr;

String MessagePath()
{
    // StorageFile.GetFileFromPathAsync doesn't appear to honor the "current directory"
    // so we have to get that ourselves...

    wchar_t buffer[1024] = {};
    GetCurrentDirectory(_countof(buffer), buffer);

    check(PathCchAppendEx(buffer, _countof(buffer), L"message.png", PATHCCH_ALLOW_LONG_PATHS));

    return buffer;
}

future<String> Sample()
{
    StorageFile file = await StorageFile::GetFileFromPathAsync(MessagePath());

    IRandomAccessStream stream = await file.OpenAsync(FileAccessMode::Read);

    BitmapDecoder decoder = await BitmapDecoder::CreateAsync(stream);

    SoftwareBitmap bitmap = await decoder.GetSoftwareBitmapAsync();

    OcrEngine engine = OcrEngine::TryCreateFromUserProfileLanguages();

    OcrResult result = await engine.RecognizeAsync(bitmap);

    return result.Text();
}

int main()
{
    Initialize();

    String text = Sample().get();

    printf("%ls\n", text.Buffer());
}
