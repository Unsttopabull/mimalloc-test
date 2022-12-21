#include <mimalloc.h>

int main()
{
    auto version = mi_version();

    auto newHeap = mi_heap_new();
    auto prevHeap = mi_heap_set_default(newHeap);

    return 0;
}
