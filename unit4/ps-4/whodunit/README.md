# Questions

## What's `stdint.h`?

A library that provide a set of typedefs that specify exact-width integer types, together with the minimum and maximum allowable values for each types, using macro.

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

These are for clarifying integer value that is either unsigned or signed. Ex: Uint8_t is an unsigned 8 bit interger (0-255) where the last bit isn't reserved for sign.

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

BYTE = 8-bit unsigned value
DWORD = 32-bit unsigned value
LONG = 32-bit signed value
WORD = 16-bit unsigned value

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

The first two bytes of any BMP file must be "BM" in ASCII or "0x42 0x4D" in hexadecimal.

## What's the difference between `bfSize` and `biSize`?

bfSize = contains the size in byte of a bitmap file size,
biSize = number of bytes required by the structure

## What does it mean if `biHeight` is negative?

When biHeight is negative the bitmap is top-down DIB and its origin is the upper-left corner.

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

biBitCount

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

If fopen returns NULL, the file might not exist or in the correct format.

## Why is the third argument to `fread` always `1` in our code?

Because we are reading one byte at a time from the bitmap.

## What value does line 65 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

The value that copy.c assign to padding if the bi.biWidth = 3, will be "3".

## What does `fseek` do?

Move file pointer to the given location

## What is `SEEK_CUR`?

To move the file pointer from the current location

## Whodunit?

It was Professor Plum with the candlestick in the library.
