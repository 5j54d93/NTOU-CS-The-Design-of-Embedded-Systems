# Digital System Design 數位系統設計：作業一

- [題目 1：用 Logic Gate 實作 4 bits 加減法器](https://github.com/5j54d93/NTOU-CS/tree/main/Digital%20System%20Design/HW1#題目-1用-logic-gate-實作-4-bits-加減法器)
- [題目 2：用 '+' 和 '-' 實作 4 bits 加減法器](https://github.com/5j54d93/NTOU-CS/tree/main/Digital%20System%20Design/HW1#題目-2用--和---實作-4-bits-加減法器)
- [題目 3：用 2 對 1 多工器和 4 對 1 多工器，組成 8 對 1 多工器](https://github.com/5j54d93/NTOU-CS/tree/main/Digital%20System%20Design/HW1#題目-3用-2-對-1-多工器和-4-對-1-多工器組成-8-對-1-多工器)
- [License](https://github.com/5j54d93/NTOU-CS/tree/main/Digital%20System%20Design/HW1#ntou-cslicensedigital-system-design-數位系統設計)

## 題目 1：[用 Logic Gate 實作 4 bits 加減法器](https://github.com/5j54d93/NTOU-CS/blob/main/Digital%20System%20Design/HW1/adder_subtractor_4bits_logic_gate.vhd)

### 說明

- 輸入 Input：A、B
- 模式 Mode：M
- 輸出 Output：S（結果）、Co（進位）

`M = 0` 時，做加法，S = A + B。  
`M = 1` 時，做減法，S = A - B。

### 模擬測試波形圖

<img src="https://github.com/5j54d93/NTOU-CS/blob/main/Digital%20System%20Design/HW1/Photo/HW1-1.png" width='100%' height='100%'/>

## 題目 2：[用 '+' 和 '-' 實作 4 bits 加減法器](https://github.com/5j54d93/NTOU-CS/blob/main/Digital%20System%20Design/HW1/adder_subtractor_4bits.vhd)

### 說明

- 輸入 Input：A、B
- 模式 Mode：M
- 輸出 Output：S（結果）、Co（進位）

`M = 0` 時，做加法，S = A + B。  
`M = 1` 時，做減法，S = A - B。

### 模擬測試波形圖

<img src="https://github.com/5j54d93/NTOU-CS/blob/main/Digital%20System%20Design/HW1/Photo/HW1-2.png" width='100%' height='100%'/>

## 題目 3：[用 2 對 1 多工器和 4 對 1 多工器，組成 8 對 1 多工器](https://github.com/5j54d93/NTOU-CS/blob/main/Digital%20System%20Design/HW1/demux_8_to_1.vhd)

### 說明

先由 S(0) 決定，X(0) 等於 I(0)、I(1)、I(2)、I(3) 其中一個，S(1) 決定，X(1) 等於 I(4)、I(5)、I(6)、I(7) 其中一個，再由 S(2) 決定輸出 X(0) 或 X(1)。

- 輸入 Input：I、S
- 輸出 Output：F

兩個 4 對 1

|S(0)|S(1)|X(0)|X(1)|
|:-:|:-:|:-:|:-:|
|0|0|I(0)|I(4)|
|0|1|I(1)|I(5)|
|1|0|I(2)|I(6)|
|1|1|I(3)|I(7)|

一個 2 對 1

|S(2)|F|
|:-:|:-:|
|0|X(0)|
|1|X(1)|

### 模擬測試波形圖

<img src="https://github.com/5j54d93/NTOU-CS/blob/main/Digital%20System%20Design/HW1/Photo/HW1-3.png" width='100%' height='100%'/>

## NTOU CS｜License：Digital System Design 數位系統設計

This package is licensed under MIT license. See [LICENSE](https://github.com/5j54d93/NTOU-CS/blob/main/LICENSE) for details.
