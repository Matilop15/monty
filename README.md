# Monty Project 

![image](https://github.com/Matilop15/monty/blob/main/img/monty.jpg)

Stacks, Queues - LIFO, FIFO, January 2022

# Description

A language interpreter made in the C programming language to manage stacks and queues (LIFO and FIFO). The aim is to interpret Monty bytecodes files. [Monty](http://montyscoconut.github.io/) is a language that aims to close the gap between scripting and programming languages.

# Compilation

To compile this project, you can use the following command:

```
gcc -Wall -Werror -Wextra -pedantic -std=c90 *.c -o monty
```

# Option Codes

## Push opcode

The opcode `push` pushes an element to the stack.

**Usage:** `push <int>`, where *int* is an integer.

## Pall opcode

The opcode `pall` prints all the values on the stack, starting from the top of the stack.

**Usage:** `pall`. If the stack is empty, `pall` don’t print anything.

```
root@985e10084b49:~/monty# cat -e bytecodes/00.m
push 1$
push 2$
push 3$
pall$
root@985e10084b49:~/monty# ./monty bytecodes/00.m
3
2
1
root@985e10084b49:~/monty#
```

## Pint opcode

The opcode `pint` prints the value at the top of the stack, followed by a new line.

**Usage:** `pint`. If the stack is empty, `pint` print an error message.

```
root@985e10084b49:~/monty# cat bytecodes/06.m
push 1
pint
push 2
pint
push 3
pint
root@985e10084b49:~/monty# ./monty bytecodes/06.m
1
2
3
root@985e10084b49:~/monty#
```

## Pop opcode

The opcode `pop` removes the top element of the stack.

**Usage:** `pop`. If the stack is empty, `pop` print an error message.

```
root@985e10084b49:~/monty# cat bytecodes/07.m
push 1
push 2
push 3
pall
pop
pall
pop
pall
pop
pall
root@985e10084b49:~/monty# ./monty bytecodes/07.m
3
2
1
2
1
1
root@985e10084b49:~/monty#
```

## Swap opcode

The opcode `swap` swaps the top two elements of the stack.

**Usage:** `swap`. If the stack contains less than two elements, `swap` print an error message.

```
root@985e10084b49:~/monty# cat bytecodes/09.m
push 1
push 2
push 3
pall
swap
pall
root@985e10084b49:~/monty# ./monty bytecodes/09.m
3
2
1
2
3
1
root@985e10084b49:~/monty#

```

## Add opcode

The opcode `add` adds the top two elements of the stack. The result is stored in the second top element of the stack, and the top element is removed, so that at the end:

* The top element of the stack contains the result
* The stack is one element shorter

**Usage:** `add`. If the stack contains less than two elements, `add` print an error message.

```
root@985e10084b49:~/monty# cat bytecodes/12.m
push 1
push 2
push 3
pall
add
pall
root@985e10084b49:~/monty# ./monty bytecodes/12.m
3
2
1
5
1
root@985e10084b49:~/monty# 

```

## Nop opcode

The opcode `nop` doesn’t do anything.

**Usage:** `nop`.

```
root@985e10084b49:~/monty# cat -e bytecodes/nop.m
nop$
push 1$
nop$
push 2$
nop$
push 3$
nop$
pall$
nop$
pall$
root@985e10084b49:~/monty# ./monty bytecodes/nop.m
3
2
1
3
2
1
root@985e10084b49:~/monty#
```

## Sub opcode

The opcode `sub` subtracts the top element of the stack from the second top element of the stack. The result is stored in the second top element of the stack, and the top element is removed, so that at the end:

* The top element of the stack contains the result
* The stack is one element shorter

**Usage:** `sub`. If the stack contains less than two elements, `sub` print an error message.

```
root@985e10084b49:~/monty# cat -e bytecodes/sub.m
push 1$
push 2$
push 10$
push 3$
sub$
pall$
root@985e10084b49:~/monty# ./monty bytecodes/sub.m
7
2
1
root@985e10084b49:~/monty#

```

## Div opcode

The opcode `div` divides the second top element of the stack by the top element of the stack. The result is stored in the second top element of the stack, and the top element is removed, so that at the end:

* The top element of the stack contains the result
* The stack is one element shorter

**Usage:** `div`. If the stack contains less than two elements, `div` print an error message.

```
root@985e10084b49:~/monty# cat -e bytecodes/div.m
push 1$
push 2$
push 10$
push 5$
div$
pall$
root@985e10084b49:~/monty# ./monty bytecodes/div.m
2
2
1
root@985e10084b49:~/monty#
```
## Mul opcode

The opcode `mul` multiplies the second top element of the stack with the top element of the stack. The result is stored in the second top element of the stack, and the top element is removed, so that at the end:

* The top element of the stack contains the result
* The stack is one element shorter

**Usage:** `mul`. If the stack contains less than two elements, `mul` print an error message.

```
root@985e10084b49:~/monty# cat -e bytecodes/mul.m
push 1$
push 2$
push 20$
push 5$
mul$
pall$
root@985e10084b49:~/monty# ./monty bytecodes/mul.m
100
2
1
root@985e10084b49:~/monty#

```

## Some Brainf\*ck Tasks

[Brainfck](https://en.wikipedia.org/wiki/Brainfuck) is an esoteric programming language created in 1993 by Urban Müller. Here are some testing scripts.

## Print Holberton

Write a Brainf\*ck script that prints Holberton, followed by a new line.

* All your Brainf\*ck files should be stored inside the bf sub directory
* You can install the bf interpreter to test your code: `sudo apt-get install bf`

**Source:** [1000-school.bf](https://github.com/Matilop15/monty/blob/main/bf/1000-school.bf)

```
root@985e10084b49:~/monty/bf# bf 1000-school.bf
School
root@985e10084b49:~/monty/bf# bf 1001-add.bf
```

<!-- AUTHORS -->
## Authors
*Matias Lopez* - [Linkedin](https://www.linkedin.com/in/matias-l%C3%B3pez-777796194/) | [Github](https://github.com/Matilop15)

*Oscar Bedat* - [Linkedin](https://www.linkedin.com/in/oscarbedat/) | [Github](https://github.com/Ouyei)
