#include "kernelUtil.h"
#include "memory/heap.h"

extern "C" void _start(BootInfo *bootInfo){
    KernelInfo kernelInfo = InitializeKernel(bootInfo);
    PageTableManager* pageTableManager = kernelInfo.pageTableManager;

    GlobalRenderer->Println("Kernel Initialized Successfully");

    GlobalRenderer->Println(to_hex_string((uint64_t)bootInfo->rsdp));

    GlobalRenderer->Println(to_hex_string((uint64_t)malloc(0x8000)));
    void* address = malloc(0x8000);
    GlobalRenderer->Println(to_hex_string((uint64_t)address));
    GlobalRenderer->Println(to_hex_string((uint64_t)malloc(0x100)));
    free(address);
    GlobalRenderer->Println(to_hex_string((uint64_t)malloc(0x100)));

    while(true);
}
