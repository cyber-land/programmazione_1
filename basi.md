# Codifiche binarie
slide 4.4
i numeri vengono rappresentati in `big endian`, in cui i bit più significativi vengono scritti per primi

## Fixed point
https://www.geeksforgeeks.org/fixed-point-representation/

**intero senza segno**
the range is `0` to `2^bitsize`

**1's complement form**
One bit is essentially used as a sign bit for 1’s complement numbers, leaving you with only 7 bits to store the actual number in an 8-bit number.
the range is `-2^(bitsize-1)+1` to `2^(bitsize-1)-1`

**2's complement form (CA2)**
la conversione funziona sia partendo da `unsigned int` che `signed int` :
Two's complement is executed by inverting (i.e. flipping) all bits, then adding a place value of 1 to the inverted number
```
127 = 01111111 =(2CA)> 10000001
128 = 10000000 =(2CA)> 10000000
```
the range is `-2^(bitsize-1)` to `2^(bitsize-1)-1`

## Floating point

https://www.geeksforgeeks.org/floating-point-representation-basics/

The IEEE 754 standard defines a binary floating point format

|Precision|Sign|Exponent|Significant|
|-|-|-|-|
|Single precision|1|8|23+1|
|Double precision|1|11|52+1|

# Cambi di basi
4.3
https://youtu.be/c490tIOChTw

(base particolare) => binario => (base particolare)

```
(dec) 19 9 4 2 1
divisione x 2
resto  1 1 0 0 1
leggere il resto da dx a sx
```

```
6E (base 16)
6 = 0110
E = 1110
concatenazione
01101110
64+32+8+4+2 = 110 (dec)

110/16^1 = 6 (resto 14) => 6
14/16^0  = 14 (resto 0) => E
```
