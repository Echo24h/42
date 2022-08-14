#!/bin/sh

have_command () {
    command -v "$1" &>/dev/null
}

make ft
./prog > test_ft.out

make std
./prog > test_std.out

if have_command code
then
	code --diff test_ft.out test_std.out
else
	vimdiff test_ft.out test_std.out
fi
