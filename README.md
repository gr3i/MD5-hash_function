**MD5-hash_function**

Because of Advent of Code, where I need to use the MD5 hash function, I decided to create my own implementation of MD5 in C as a side project.
I know that MD5 is not secure. It's just good as a learning side project.

There will be many small projects around, so I will atleast learn here, how to create side branches on GitHub as well and etc..

Progress:

Make function to convert decimal to hexadecimal [DONE]
Make function to convert hexadecimal to bits [DONE]
Make bitwise functions:
- bitwise OR [DONE]
- bitwise AND [DONE]
- bitwise XOR [DONE]
- bitwise NOT [DONE]
- bitwise ADD [DONE]
Make bit rotation function [DONE]

Input of MD5 is 512 bits and the output is 128 bits. 
MD5 works with 32 bits words, I have to divide 128 bits into 4 words. 
Each of the words will have the variable name (A, B, C, D) -> e.g. A = 0xefcdba78
I will have current state (A, B, C, D) and the next state (A', B', C', D')

The MD5 hash function is not finished yet.
