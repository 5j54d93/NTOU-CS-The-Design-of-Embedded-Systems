# Digital System Design 數位系統設計：作業四

- 題目 1：用 4 bits 加減法器組成 10 bits 加減法器
- 題目 2：用 4 bits BCD 可串接上數器組成 3 位數 BCD 可串接上數器
- License

## 題目 1：[用 4 bits 加減法器組成 10 bits 加減法器](https://github.com/5j54d93/NTOU-CS/tree/main/Digital%20System%20Design/HW4/adder_subtractor_10bits)

### 說明

- 輸入 Input：X、Y、MODE、Cin
- 輸出 Output：Cout、S

### 模擬測試波形圖

<img src="" width='100%' height='100%'/>

## 題目 2：用 4 bits BCD 可串接上數器組成 3 位數 BCD 可串接上數器

### 說明

- 輸入 Input：CLK、RESET、CASIN
- 輸出 Output：CASOUT、F

`CASIN = 0` 時，前面沒進位，不能數。  
`CASIN = 1` 時，前面有進位，可以數。  
`CASOUT = 0` 時，自己還沒數滿，不用沒進位給下一位，下一個不能數。  
`CASOUT = 1` 時，自己數滿了，要進位給下一位，下一個可以數。

### 模擬測試波形圖

<img src="https://github.com/5j54d93/NTOU-CS/blob/main/Digital%20System%20Design/HW3/Photo/HW3-2.png" width='100%' height='100%'/>

## Digital System Design｜License：© Ricky Chuang

This package is licensed under MIT license. See [LICENSE](https://github.com/5j54d93/NTOU-CS/blob/main/LICENSE) for details.
