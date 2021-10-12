# ST7735 TFT LCD & STM32F1xx Import External Fonts.
ST3375 w/ stm32f1xx Now can import external font format by MicroElectronica GLCD Fonts Creator.  
Base on this project : https://github.com/ScarsFun/STM32F103C8T6_cubeIDE_ST7735_1.8_DMA

<img src="img/11.jpg" width="40%"/>   
How to make a font?</p>   
1. Download MicroElectronica GLCD Fonts Creator From this link : https://www.mikroe.com/glcd-font-creator</p>   
2. Click "File" >> "New Font" >> "Import An Existing System Font"</p>
<img src="img/1.jpg" width="40%"/> 
And then Config a Font, Font style and Size that you prefer. Click "OK" and wait a program to generate a GLCD code.</p>
<p float="left">
  <img src="img/2.jpg" width="40%"/> 
  <img src="img/3.jpg" width="40%"/>
</p>
3.Click "Export for TFT and new GLCD(new library)" >> "mikroC".</p>
4.Create a 'static const uint16_t' array type in fonts.c file and fill array with a font data.</p>
<p float="left">
  <img src="img/4.jpg" width="50%"/>
  <img src="img/5.jpg" width="60%"/>
</p>
Define a FontDef looks like in a below image at a bottom of file.</p>
<img src="img/6.jpg" width="50%"/>
And then open a fonts.h and Define a data looks like in a below image.</p>
<img src="img/7.jpg" width="50%"/></p>
Now you can use Fonts that you have imported.</p>
<img src="img/8.jpg" width="50%"/>
<img src="img/9.jpg" width="50%"/>
<img src="img/10.jpg" width="50%"/>
<img src="img/11.jpg" width="50%"/>
