# Digital System Design 數位系統設計：作業二

- 題目 1：用 Process 實作 4 bits 加法器
- 題目 2：實作 8 bits 上下數器（從 20₁₆ 到 A0₁₆）
- 題目 3：實作 3 位元 BCD 上數器（從 100 到 499）
- License

## 題目 1：[用 Process 實作 4 bits 加法器](https://github.com/5j54d93/NTOU-CS/blob/main/Digital%20System%20Design/HW2/adder_4bits_process.vhd)

### 說明

S = A + B

- 輸入 Input：A、B
- 輸出 Output：S（結果）、Co（進位） 

### 模擬測試波形圖

<img src="https://github.com/5j54d93/NTOU-CS/blob/main/Digital%20System%20Design/HW2/Photo/HW2-1.png" width='100%' height='100%'/>

## 題目 2：[實作 8 bits 上下數器（從 20₁₆ 到 A0₁₆）](https://github.com/5j54d93/NTOU-CS/blob/main/Digital%20System%20Design/HW2/updown_counter_8bits_20_to_A0.vhd)

### 說明

正緣觸發

- 輸入 Input：CLK、RESET
- 模式 Mode：UP_DOWN
- 輸出 Output：Q

`UP_DOWN = 0` 時，上數。  
`UP_DOWN = 1` 時，下數。

### 模擬測試波形圖

<img src="https://github.com/5j54d93/NTOU-CS/blob/main/Digital%20System%20Design/HW2/Photo/HW2-2-1.png" width='100%' height='100%'/>
<img src="https://github.com/5j54d93/NTOU-CS/blob/main/Digital%20System%20Design/HW2/Photo/HW2-2-2.png" width='100%' height='100%'/>
<img src="https://github.com/5j54d93/NTOU-CS/blob/main/Digital%20System%20Design/HW2/Photo/HW2-2-3.png" width='100%' height='100%'/>

## 題目 3：[實作 3 位元 BCD 上數器（從 100 到 499）](https://github.com/5j54d93/NTOU-CS/blob/main/Digital%20System%20Design/HW2/BCD_counter_3bits_100_to_499.vhd)

### 說明

正緣觸發

- 輸入 Input：CLK、RESET
- 輸出 Output：BCD

### 模擬測試波形圖

<img src="https://github.com/5j54d93/NTOU-CS/blob/main/Digital%20System%20Design/HW2/Photo/HW2-3-1.png" width='100%' height='100%'/>
<img src="https://github.com/5j54d93/NTOU-CS/blob/main/Digital%20System%20Design/HW2/Photo/HW2-3-2.png" width='100%' height='100%'/>

## NTOU CS｜License：Digital System Design 數位系統設計

This package is licensed under MIT license. See [LICENSE](https://github.com/5j54d93/NTOU-CS/blob/main/LICENSE) for details.
