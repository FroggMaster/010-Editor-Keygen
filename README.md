# 010 Editor KeyGen

A License Key generator for [010 Editor](http://www.sweetscape.com/download/010editor/).
Written purely in Assembly

## Warning

It is for **EDUCATIONAL PURPOSES** only.

## Features

1. Arbitrary usernames are supported

2. License expiration date can be customized (any date between the next day and December 31, 3000)

3. N-User License Keys can be generated where 1 ≤ N ≤ 1000

You **DON'T NEED MSVCRT** to run this program

---

## Build Instructions

**Current (recommended)**

1. Run `Build.cmd`.
2. Find the built executable in the `bin` folder.

> This is the preferred/current build workflow. It automates assembling and places the final executable in `bin`.

<details>
<summary>Legacy/Manual Build Instructions</summary>

If you prefer to assemble manually (legacy method), follow these steps:

1. Download [Flat Assembler](http://flatassembler.net/download.php)

   or
   
   If you are on Linux, you may use `sudo apt-get install fasm`

2. Assemble using the following command

   `fasm main.asm`

The current support is for Windows only.

~~I'll be adding a linux executable soon~~ _Probably not going to happen the original author never did this and I have no intention of doing it either try WINE._
</details>

---

## Screenshot

![Screenshot](screenshot.gif)

## License

[MIT](/LICENSE)
