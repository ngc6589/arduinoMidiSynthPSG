# arduinoMidiSynthPSG

![image](https://user-images.githubusercontent.com/4132056/136721304-d8033698-e76b-4714-b7b7-a6a07bdd763b.jpg)

Blog page https://mkusunoki.net/?p=7942

部品表(4枚分)

|部品名|型番|数量|その他|
|-----|-----|----|----|
|PSG|AY-3-8910|4|Aitendo/共立/Aliexpressなど|
|フォトカプラ|6N138|1|https://www.marutsu.co.jp/pc/i/15150015/<br>MIDI用フォトカプラなら良い|
|ダイオード|1N4148|1|https://akizukidenshi.com/catalog/g/gI-00941/<br>50本入りなので1袋で良い|
||74HC74|1|https://akizukidenshi.com/catalog/g/gI-10879/|
|クリスタル|3.579545MHz|1|https://akizukidenshi.com/catalog/g/gP-01567/
|MIDIジャック|PRT-09536|1|https://www.switch-science.com/catalog/263/|
|タクトスイッチ|タクトスイッチ|1|https://akizukidenshi.com/catalog/g/gP-03650/|
|ジャンパー|MJ-254-6R|10|https://akizukidenshi.com/catalog/g/gP-03688/<br>25個入りなので1袋で良い|
|電解コンデンサ|10uF/25V|2|https://akizukidenshi.com/catalog/g/gP-04624/|
|セラミックコンデンサ|0.1uF 5mm|4|https://akizukidenshi.com/catalog/g/gP-15927/<br>10個入りなので1袋で良い|
|抵抗|1k|8|https://akizukidenshi.com/catalog/g/gR-25102/<br>100本入りなので1袋で良い|
|抵抗|2.2k|10|https://akizukidenshi.com/catalog/g/gR-25222/<br>100本入りなので1袋で良い|
|抵抗|220|2|https://akizukidenshi.com/catalog/g/gR-25221/<br>100本入りなので1袋で良い|
|ピンソケット|1x8 15mm|24|https://akizukidenshi.com/catalog/g/gC-07913/|
|ピンソケット|1x10 15mm|12|https://akizukidenshi.com/catalog/g/gC-07914/|
|ピンヘッダ|2x25|2|https://akizukidenshi.com/catalog/g/gC-00081/|
|3.5mmジャック|MJ-8435|1|https://akizukidenshi.com/catalog/g/gC-09060/|
|ICソケット|8ピン|1|https://akizukidenshi.com/catalog/g/gP-00017/<br>10個入りなので1袋で良い|
|ICソケット|14ピン|1|https://akizukidenshi.com/catalog/g/gP-00006/<br>10個入りなので1袋で良い|
|ICソケット|40ピン|1|https://akizukidenshi.com/catalog/g/gP-00015/<br>10個入りなので1袋で良い|
|プリント基板||1|業者にガーバーを送って作成|

MIDI コネクタは秋月の https://akizukidenshi.com/catalog/g/gC-09565/ で代用可能です。基板のフットプリントはことなりますが問題ありません。

製作
1枚目は、クロックなどすべての部品を取り付ける形で作成します。
![image](https://user-images.githubusercontent.com/4132056/136722215-af37a62e-97b9-4079-90a8-3748f640211a.jpg)
増設音源シールドは次の写真のように、AY-3-8910 と抵抗・連結ソケットだけになります。
![image](https://user-images.githubusercontent.com/4132056/136722366-4324522d-57e2-495d-82a1-0a849c294d3c.jpg)

ジャンパの設定。

J6 RX1 Ardiono の Serial1 に接続

J1 CLK/2 3.579545Mhz を2分周したクロックを AY-3-8910に供給します。

|Shield|BDIR|PC1|Voice番号|
|---|---|---|---|
|1枚目|PC0|PC4|0-2|
|増設|PC1|PC5|3-5|
|増設|PC2|PC6|6-8|
|増設|PC3|PC7|9-11|

が、標準の設定です。

