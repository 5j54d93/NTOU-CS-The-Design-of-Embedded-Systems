# Digital System Design 數位系統設計：作業三

- 題目 1：[階梯波](https://github.com/5j54d93/NTOU-CS/tree/main/Digital%20System%20Design/HW3#題目-1階梯波)
- 題目 2：[可串接 1 bit BCD 上數器](https://github.com/5j54d93/NTOU-CS/tree/main/Digital%20System%20Design/HW3#題目-2可串接-1-bit-bcd-上數器)
- 題目 3：[用題目 2 以方塊圖實做2 bit BCD 上數器](https://github.com/5j54d93/NTOU-CS/tree/main/Digital%20System%20Design/HW3#題目-3用題目-2-以方塊圖實做2-bit-bcd-上數器)
- [License](https://github.com/5j54d93/NTOU-CS/tree/main/Digital%20System%20Design/HW3#digital-system-designlicense-ricky-chuang)

## 題目 1：[階梯波](https://github.com/5j54d93/NTOU-CS/blob/main/Digital%20System%20Design/HW3/staircase_8bits.vhd)

### 說明

循環的階梯波，高為 8。

- 輸入 Input：CLK、RESET
- 輸出 Output：F

### 模擬測試波形圖

<img src="https://github.com/5j54d93/NTOU-CS/blob/main/Digital%20System%20Design/HW3/Photo/HW3-1.png" width='100%' height='100%'/>

## 題目 2：[可串接 1 bit BCD 上數器](https://github.com/5j54d93/NTOU-CS/blob/main/Digital%20System%20Design/HW3/cascade_BCD_counter_1bit.vhd)

### 說明

- 輸入 Input：CLK、RESET、CASIN
- 輸出 Output：CASOUT、F

`CASIN = 0` 時，前面沒進位，不能數。  
`CASIN = 1` 時，前面有進位，可以數。  
`CASOUT = 0` 時，自己還沒數滿，不用沒進位給下一位，下一個不能數。  
`CASOUT = 1` 時，自己數滿了，要進位給下一位，下一個可以數。

### 模擬測試波形圖

<img src="https://github.com/5j54d93/NTOU-CS/blob/main/Digital%20System%20Design/HW3/Photo/HW3-2.png" width='100%' height='100%'/>

## 題目 3：用題目 2 以方塊圖實做2 bit BCD 上數器

### 說明

- 輸入 Input：CLK、RESET、CASIN
- 輸出 Output：CASOUT、F

<img src="https://github.com/5j54d93/NTOU-CS/blob/main/Digital%20System%20Design/HW3/Photo/HW3-3.png" width='100%' height='100%'/>

### 模擬測試波形圖

<img src="https://github.com/5j54d93/NTOU-CS/blob/main/Digital%20System%20Design/HW3/Photo/HW3-3-1.png" width='100%' height='100%'/>
<img src="https://github.com/5j54d93/NTOU-CS/blob/main/Digital%20System%20Design/HW3/Photo/HW3-3-2.png" width='100%' height='100%'/>

## Digital System Design｜License：© Ricky Chuang

This package is licensed under MIT license. See [LICENSE](https://github.com/5j54d93/NTOU-CS/blob/main/LICENSE) for details.
