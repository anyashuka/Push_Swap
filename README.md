# Push_Swap

#### Final Score 105/100

## Challenge

Implement a bespoke sorting algorithm. <br />

The task: sort a random list of integers (given via command line arguments), using the smallest number of moves, 2 stacks <br />
and a limited set of operations. <br />
<br />
In this project, we start with two emtpy stacks: **stack a** and **stack b**. We must create two programs: ```checker``` and ```push_swap```. <br />
The ```checker``` program reads a random list of integers from the stdin, stores them in **stack a** and checks to see
if they are sorted in ascending order. <br />
The ```push_swap``` program calculates the moves to sort the integers – *pushing, popping, swapping* and *rotating* 
them between **stack a** and **stack b** – and displays those directions on the stdout. <br />
You can pipe ```push_swap``` into ```checker```, and ```checker``` will verify that ```push_swap```'s instructions were successful. 
<br />
<br /> 

Only these moves are allowed:
- `sa` : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).
- `sb` : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).
- `ss` : `sa` and `sb` at the same time.
- `pa` : push a - take the first element at the top of b and put it at the top of a. Do
nothing if b is empty.
- `pb` : push b - take the first element at the top of a and put it at the top of b. Do
nothing if a is empty.
- `ra` : rotate a - shift up all elements of stack a by 1. The first element becomes
the last one.
- `rb` : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
- `rr` : `ra` and `rb` at the same time.
- `rra` : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
- `rrb` : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
- `rrr` : `rra` and `rrb` at the same time.
<br />

Both programs must mandatorily parse input for errors, including empty strings, no parameters, 
non-numeric parameters, duplicates, and invalid/non-existent instructions.

**Push_Swap** must conform to the [42 Norm](https://cdn.intra.42.fr/pdf/pdf/960/norme.en.pdf). <br />
Using normal ```libc``` functions is strictly forbidden. Students are however, allowed to use: ```write```, ```read```, ```malloc```, ```free```, ```exit```. 
It must not have any memory leaks. Errors must be handled carefully. <br />
In no way can it quit in an unexpected manner (segmentation fault, bus error, double free, etc).

## Usage
Run ```make```.

The **checker** program is used as follows:
```c
  ./checker 5 2 3 1 4
```
```c
  ./checker "-50 -400 -20 -1 -100"
```
```c
  ./checker "-22" "35" "40" "-15" "75"
```

The **push_swap** program is used in the same way
```c
  ./push_swap 5 2 3 1 4
```

You can run the two together using:
```c
  ARG=`ruby -e "puts (0..100).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker -v $ARG
```
Note: the **-v (debug) flag** shows the stack status after each operation. 
![screen capture of checker and push_swap](./images/visualizer.gif)
<br />

To see push_swap in action, run ```make``` and then the following script:
```
python3 pyviz.py `ruby -e "puts (-200..200).to_a.shuffle.join(' ')"`
```
![screen capture of checker and push_swap](./images/visualizer2.gif)
