#!/bin/sh

#用来链接编译指令的文件, 以便于一些文本编辑器使用
set -e
cmake -B ".build" -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
cp .build/compile_commands.json .