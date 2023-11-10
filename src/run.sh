#!/bin/bash
set -xue

# path of QEMU
QEMU=/usr/local/bin/qemu-system-riscv32

# path of clang
CC=/usr/local/opt/llvm/bin/clang
OBJCOPY=/usr/local/opt/llvm/bin/llvm-objcopy

CFLAGS="-std=c11 -O2 -g3 -Wall -Wextra --target=riscv32 -ffreestanding -nostdlib"

# build shell
$CC $CFLAGS -Wl,-Tuser.ld -Wl,-Map=shell.map -o shell.elf shell.c user.c common/common.c
$OBJCOPY --set-section-flags .bss=alloc,contents -O binary shell.elf shell.bin
$OBJCOPY -Ibinary -Oelf32-littleriscv shell.bin shell.bin.o

# build kernel
$CC $CFLAGS -Wl,-Tkernel/kernel.ld -Wl,-Map=kernel/kernel.map -o kernel/kernel.elf \
    kernel/kernel.c kernel/fs.c common/common.c kernel/page.c kernel/sbi_call.c kernel/process.c kernel/trap.c shell.bin.o -I ./

# run QEMU
$QEMU -machine virt -bios default -nographic -serial mon:stdio --no-reboot \
    -d unimp,guest_errors,int,cpu_reset -D qemu.log \
    -drive id=drive0,file=lorem.txt,format=raw \
    -device virtio-blk-device,drive=drive0,bus=virtio-mmio-bus.0 \
    -kernel kernel/kernel.elf
