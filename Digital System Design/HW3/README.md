# Digital System Design 數位系統設計：作業三

- 題目 1：階梯波
- 題目 2：可串接 1 bit BCD 上數器
- 題目 3：用題目 2 以方塊圖實做2 bit BCD 上數器
- License

## 題目 1：階梯波

### 說明

循環的階梯波，高為 8。

- 輸入 Input：CLK、RESET
- 輸出 Output：F

### 模擬測試波形圖

<img src="" width='100%' height='100%'/>

## 題目 2：可串接 1 bit BCD 上數器

### 說明

正緣觸發

- 輸入 Input：CLK、RESET、CASIN
- 輸出 Output：CASOUT、F

`CASIN = 0` 時，前面沒進位，不能數。  
`CASIN = 1` 時，前面有進位，可以數。  
`CASOUT = 0` 時，自己還沒數滿，不用沒進位給下一位，下一個不能數。  
`CASOUT = 1` 時，自己數滿了，要進位給下一位，下一個可以數。

### 模擬測試波形圖

<img src="" width='100%' height='100%'/>

## 題目 3：用題目 2 以方塊圖實做2 bit BCD 上數器

### 說明

<img src="" width='100%' height='100%'/>

### 模擬測試波形圖

<img src="" width='100%' height='100%'/>

## Digital System Design｜License：© Ricky Chuang

This package is licensed under MIT license. See [LICENSE](https://github.com/5j54d93/NTOU-CS/blob/main/LICENSE) for details.
