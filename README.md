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
On each iteration I will calculate next state of A', B', C' and D' and set the current state to be next state.  
The update works as follows:  
C' is equal to A  
D' is equal to C
A' is equal to D
Most of the A update is simply permutation however B' is the combination of A, B, C, D and the 32 bit word from the input.  
If it's first iteration I will use the first 32 bit word from the input.  
i = 0  
i % 16 = 0  
I will explain combine funtion below.  
Next state will become after I set that A is equal to A', B is equal to B', C to C' and D to D'.  
Three out of four of the values from the last state are permutated however B is a new value that is a function of the previous state 
and the first 32 bits from the input.  
I will run the program for 15 more iterations to digest the rest of the input.
This complete the first loop.  
There will be total of four loops.  

On the second loop. (That is iterations 16 through 31) I don't visit the input in sequential order, but in the order specified by (5i + 1) % 16 that visits
each of the 32-bit segments in the input once but in the order shown in the animation. (Can see in the video)  
i = 16  
(5i + 1) % 16 =  

On the third loop I visit the inputs in the order dictated by (3i + 5) % 16  
i = 32  
(3i + 5) % 16 = 

On the fourth loop I visit the inputs in the order defined by 7i % 16   
i = 48  
7i % 16 =  

After 4 loops or 64 iterations, the current state becomes the output of the MD5 hash function.  
The output of the MD5 hash function is the final values of A, B, C and D concatenated together after being updated 64 times.  


The MD5 hash function is not finished yet.
