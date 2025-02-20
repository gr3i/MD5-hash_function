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
C' is equal to B  
D' is equal to C  
A' is equal to D  
Most of the update is simply permutation however B' is the combination of A, B, C, D and the 32 bit word from the input.  
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

What the combine function is doing:  
The first part is to combine the inputs B, C, D into a single value via a function F.  
Function F looks like this:  
def F(B, C, D, i):  
  if 0 <= i <= 15:  
    return (B & C) | ((~B) & D)  
  if 16 <= i <= 31:  
    return (D & B) | ((~D) & C)  
  if 32 <= i <= 47:  
    return B ^ C ^ D  
  if 48 <= i <= 63:  
    return C ^ (B | (~D))  

Combine function  
redBox(F(B, C, D, i) + A + input[currentIndex])  
currentIndex(i) =   
i % 16 if 0 <= i < 16  
(5i + 1) % 16 if 16 <= i < 32  
(3i + 5) % 16 if 32 <= i < 48  
7i % 16 if 48 <= i < 64  

What happens in the red box. The red box contains two addition and one rotation.  
MD5 introduces 64 hard-coded constants in an array called K. I will use same array in my MD5 hash function code. These are used for the first addition.  The value from K that I use depends on the current iteration i. (There are 64 iterations and the array K has 64 values) 

Just for fact... How are these constants generated?  
Each of these values is obtained using the formula: K[i] = [2^32 x |sin(i + 1)|] where i is the index
(0 to 63), and the sine funcation is applied in radians.

Next I have 64 constants that determine how much I will rotate the 32 bits by.  
The array is called r.  

combine = rotate((F(B, C, D, i) + A + input[currentIndex] + K[i]), r[i]) + B  


The MD5 hash function is not finished yet.
