## What is DIY Boost Circuit?
最近開始想要針對一些基本的電路做些實驗, 以提升自己的基礎能力以及基礎概念

已經做了許多實驗, 但是 Boost這一個是比較有趣的, 所以想說先做個紀錄吧

Boost基本電路使用 Google可以找到許多資料, 其中最基本的電路如下

<center><img src="https://github.com/TripleC-Light/DIY-Boost-Circuit/blob/master/image/example.png?raw=true" width=600></center>

當 mos導通時, 電流 Is流過電感L使電感L將能量轉為磁場並儲存
當 mos關閉時, 儲存在電感L的磁場能量轉為電流流向電容C與負載
電容C由於電流流入使電壓上升
當 mos再度導通時, 因為二極體逆向偏壓所以導通, 電容能量流向負載
回到步驟1
這次實驗我隨手找了幾顆元件來試試, 電感為10uH, mos使用AO3413, 二極體為FM340, 電感C為330uF, 焊接後如下圖所示

<center><img src="https://github.com/TripleC-Light/DIY-Boost-Circuit/blob/master/image/realCircuit.png?raw=true" width=600></center>

Arduino的作用就是拿來控制 mos, 我使用 pin11的 PWM來做控制, 並使用 A0的 ADC來監控輸出電壓

透過監看回授的輸出電壓, 我可以控制 Arduino的 PWM輸出, 使的電壓可以維持在我需要的位置

最後的實驗結果還算如預期的達到升壓的功能

輸入最低可以到 0.2v, 輸出 5v, 穩定輸出電流為 22mA左右, 大約為 0.11w, 足夠驅動一些小系統了

但畢竟整個電路都是撿現成的元件來兜, 沒有做過優化, 只是為了驗證 Boost的基礎電路

所以結果還算滿意, 未來有時間會再試試看如何加大電流


## About Me
 - My Blog : [愛德華空想科學誌](https://triplec-light.000webhostapp.com)
 - E-mail : TripleC.Light@gmail.com
 - LinkedIn : [Edward Chou](https://www.linkedin.com/in/edward-chou-42058912a)
 - Buy Me A Coffee : [Buy Me A Coffee](https://www.buymeacoffee.com/YrFKPo2)
 - Paypal : [Link](https://www.paypal.me/TripleCLight?locale.x=zh_TW)
 