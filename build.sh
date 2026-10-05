#!/bin/bash
case $1 in
	"d")
		rm -rf "./.build"
		cmake -B "./.build" -DCMAKE_BUILD_TYPE=Debug
		;;
	"rl")
		rm -rf "./.build"
		cmake -B "./.build" -DCMAKE_BUILD_TYPE=Release
		;;
	"b")
		cmake --build "./.build" --parallel
		;;
	"r")
		./.build/"$2" "${@:3}"
		;;
esac