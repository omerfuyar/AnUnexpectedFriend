#define SHUCIO_IMPLEMENTATION
#include "shucio/shucio.h"
#include "AnUnexpectedFriend.h"
#include "time.h"

typedef struct ChatEntry
{
    const __useconds_t milliseconds;
    const char *message;
} ChatEntry;

const ChatEntry const entries[] = {
#define CHAT_ENTRY(a, b) (const ChatEntry){.milliseconds = a, .message = b},
    CHAT_LIST
#undef CHAT_ENTRY
};

int main(void)
{
    SHU_Initialize();
    SHU_ClearTerminal();

    size_t index = 0;
    while (index < (sizeof(entries) / sizeof(ChatEntry)))
    {
        const ChatEntry *entry = &entries[index];

        usleep(entry->milliseconds * 1000);
        SHU_PutString("> %s\n", entry->message);

        SHU_("> ");

        index++;
    }

    return 0;
}