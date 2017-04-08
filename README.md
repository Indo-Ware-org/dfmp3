<p align="center">
  <img src="https://indo-ware.com/logo/LOGONEW2.png" alt="Indoware logo"/>
</p>

# DFPlayer Mini MP3

 <img align="middle" src="https://www.dfrobot.com/wiki/images/thumb/a/ab/Miniplayer_pin_map.png/450px-Miniplayer_pin_map.png"/>

<p>Pada <i>readme</i> ini akan dijelaskan cara memainkan musik dengan modul DFPlayer Mini MP3 dengan menggunakan modul mikrokontroller AVR ATmega328P IndoWare.</p>

## Format Pengiriman data UART
<p>Berdasarkan link <a href="https://www.dfrobot.com/wiki/index.php/DFPlayer_Mini_SKU:DFR0299">Wiki</a> Modul ini dapat melakukan berbagai instruksi dengan komunikasi UART berkecepatan 9600bps dengan rincian frame pengiriman seperti ini:</p>
 
<table><tr><td>7E</td> <td>FF</td> <td>06</td> <td>cm</td> <td>00</td> <td>dh</td> <td>dl</td> <td>ch</td> <td>cl</td> <td>EF</td>
<tr><td>start byte</td><td>version/td><td>panjang data</td><td>command</td><td>echo command</td><td colspan="2">data yang diisi</td><td colspan="2">checksum</td><td>stop byte</td>
</table>
 
<p>command yang dapat diisi dapat dilihat pada tabel di bawah :</p>

<table style="width:800px;" align="center">
<tr>
<td style="text-align:center;background-color:#78CDF8;"><b>Commands</b>
</td>
<td style="text-align:center;background-color:#78CDF8;"><b>Function Description</b>
</td>
<td style="text-align:center;background-color:#78CDF8;"><b>Parameters(16 bit)</b>
</td></tr>
<tr>
<td style="text-align:center;">0x01
</td>
<td style="text-align:center;">Next
</td>
<td style="text-align:center;">
</td></tr>
<tr>
<td style="text-align:center;">0x02
</td>
<td style="text-align:center;">Previous
</td>
<td style="text-align:center;">
</td></tr>
<tr>
<td style="text-align:center;">0x03
</td>
<td style="text-align:center;">Special tracking(NUM)
</td>
<td style="text-align:center;">0-2999
</td></tr>
<tr>
<td style="text-align:center;">0x04
</td>
<td style="text-align:center;">Increase volume
</td>
<td style="text-align:center;">
</td></tr>
<tr>
<td style="text-align:center;">0x05
</td>
<td style="text-align:center;"> Decrease volume
</td>
<td style="text-align:center;">
</td></tr>
<tr>
<td style="text-align:center;">0x06
</td>
<td style="text-align:center;">Specify volume
</td>
<td style="text-align:center;">0-30
</td></tr>
<tr>
<td style="text-align:center;">0x07
</td>
<td style="text-align:center;">Specify EQ 0/1/2/3/4/5
</td>
<td style="text-align:center;">Normal/Pop/Rock/Jazz/Classic/Bass
</td></tr>
<tr>
<td style="text-align:center;">0x08
</td>
<td style="text-align:center;">Specify playback mode(0/1/2/3)
</td>
<td style="text-align:center;">repeat/folder repeat/single repeat/random
</td></tr>
<tr>
<td style="text-align:center;">0x09
</td>
<td style="text-align:center;">Specify playback source( 0/1/2/3/4)
</td>
<td style="text-align:center;">U/TF/AUX/SLEEP/FLASH
</td></tr>
<tr>
<td style="text-align:center;">0x0A
</td>
<td style="text-align:center;">Enter into standby-low power loss
</td>
<td style="text-align:center;">
</td></tr>
<tr>
<td style="text-align:center;">0x0B
</td>
<td style="text-align:center;">Normal working
</td>
<td style="text-align:center;">
</td></tr>
<tr>
<td style="text-align:center;">0x0C
</td>
<td style="text-align:center;">Reset module
</td>
<td style="text-align:center;">
</td></tr>
<tr>
<td style="text-align:center;">0x0D
</td>
<td style="text-align:center;">Playback
</td>
<td style="text-align:center;">
</td></tr>
<tr>
<td style="text-align:center;">0x0E
</td>
<td style="text-align:center;">Pause
</td>
<td style="text-align:center;">
</td></tr>
<tr>
<td style="text-align:center;">0x0F
</td>
<td style="text-align:center;">Specify folder to playback
</td>
<td style="text-align:center;">1-10（need to set by user）
</td></tr>
<tr>
<td style="text-align:center;">0x10
</td>
<td style="text-align:center;">Volume adjust set
</td>
<td style="text-align:center;">[DH=1:Open volume adjust][DL:set volume gain 0-31]
</td></tr>
<tr>
<td style="text-align:center;">0x11
</td>
<td style="text-align:center;">Repeat play
</td>
<td style="text-align:center;">[1:start repeat play][0:stop play]
</td></tr>
<tr>
<td style="text-align:center;">0x12
</td>
<td style="text-align:center;">Specify MP3 tracks folder
</td>
<td style="text-align:center;">0-9999
</td></tr>
<tr>
<td style="text-align:center;">0x13
</td>
<td style="text-align:center;"> Commercials
</td>
<td style="text-align:center;">0-9999
</td></tr>
<tr>
<td style="text-align:center;">0x14
</td>
<td style="text-align:center;"> Support 15 folder
</td>
<td style="text-align:center;"> See detailed description below
</td></tr>
<tr>
<td style="text-align:center;">0x15
</td>
<td style="text-align:center;"> Stop playback, play background
</td>
<td style="text-align:center;">
</td></tr>
<tr>
<td style="text-align:center;">0x16
</td>
<td style="text-align:center;">Stop playback
</td>
<td style="text-align:center;">
</td></tr></table>

## Perangkat Yang Digunakan
<img align="middle" src="https://lh3.googleusercontent.com/DsFCQqg1TCoFYDbX_irX5psnqgtvOeD01rfeBfgrN_q7fVXR1odJj0IVnXE3R-lWT0iaI2grQpdOid6gsUyXnZ1Dh3T17Q_ECKLFU-MkiyYq2nHaakbOwdXcI6E2Nzyv53S5tNK_p4xUHZtT5KFwJy_mRAIFsJiX3yFdmS9MQtk5f9RbosrwRxIxU2k6cUmrpZwpDr2fge8nMFMuZxvb2waQfVwu3oQ_94SoAu1i5SmFsimSeTGlzt1Lz1JRUq2C9IPNTkxl9yLvM2PN0kBTAwX9pZb6Sa-c9TGw-4WwvaOhlIxYkTaRzu-AYAJJAwlPy_Yc-sC-Ztt2bnILwMYV9CyhLR6qN2ymts5ebXJJR42J-QJV_QAkzOptuAhOwj2lmXx1fov3eC5YJVhflxy1NuulsnymTh4W7x9zZxUYxWtxv88vTeiM-jL342dOMv1hBhjZwTLGppV-2bT1E64skL51QyXIGeth_WxIFMnlRrNk7x3p31PXOGl11ZhNeH8rJyEXWHOLivWOf6TvhVC5bfn1Rwm4Jaf6RSMBodpqMmOm8Hys2N4jPP21HME9Yf2VtI_xgqUH-3Q61J9UhWDMpqDA6xyVNDgTw9EihneKiO3HJz6KAd0=w1087-h613-no"/>
<ol>
<li>Modul ATmega328P dengan sumber clock Crystal 16MHz</li>
<li>Modul DFPlayer Mini MP3</li>
<li>Speaker</li>
<li>Resistor 1K Ohm di kaki RX MP3</li>
</ol>

<p>Sambungannya pada modul ATmega328P adalah sebagai berikut</p>
<table>
<tr><td>Pin DFplayer Mini</td><td>Ke</td></tr>
<tr><td>Vcc</td><td>+5v</td></tr>
<tr><td>RX</td><td>RX + Resistor 1K</td></tr>
<tr><td>TX</td><td>TX</td></tr>
<tr><td>SPK_1</td><td>Speaker (+)</td></tr>
<tr><td>GND</td><td>Ground (GND)</td></tr>
<tr><td>SPK_2/td><td>Speaker (-)</td></tr>
<tr><td>Busy</td><td>PIND.2</td></tr>
</table>

## Cara Penyimpanan File MP3 pada SD card
<p>Sebelum mulai mengakses, terlebih dahulu mempersiapkan SD Card yang akan dimasukkan pada modul MP3. Langkahnya :</p>
<p>1. Format SD Card dengan ketentuan sebagai berikut:</p>
<img align="middle" src="https://lh3.googleusercontent.com/V9Dta7sldpwuPb72cQHHim95Jd_NYQXPgShg3YIfAvM2TPk0Fl4EXOMwRHWWSo_WQcWZCyllLFiQbWy_Yt_mWtdZHm3gTSWALKtZMEoNpX-jJBwbhtyLmBDDn3NNxm5Fi0-t-kgzVtY7FuMz55xsLzeVavWJFjGz4yR5skQxPgyvzxX0qtHRjyt-C4vFTOr6gLQR8EwyUn5y1xjVy4GdvUwazxbYdwM8zX8IYzckpS2xQm_Qpw2UlEppbfUcImGaXpXr4nVnDfNIS6PiUKgA435DyZUSRgfP1hT1o10Le0fp0jdTwesJvWgd61XWDDo2-5nwAas57fAwdJ8AUhC4z52_oE220TyC5hlWnr-fvqNeVJSMus1KcPnYAeYvTLTFlhdRucGXuH_CJA8do0CP3VgGn456xDJQXuTh1oKIS_dHuLI9QXOO6_-CGNAW-JbCjfzvZNZ-ooO65YnmzcqRjO_yc5u6AflZIDoFFWxnstdob86efxos5dg9hPufQQ6ZaxevdE5qqFJqGIt8OadiQO0ghG23PQx8kzyfulIwFOI3npBqdZLhEGFlr-jz7a3sCWF6_DCrMfLreYfzS-zJDj5b7-cuDWYH3K5HkEn_TkWxjM8HN_U=w278-h503-no"/>
<p>2. Buat folder MP3 pada directory root SD Card :</p>
<img align="middle" src="https://lh3.googleusercontent.com/J6OLg_s9f28p87euo1ArloDNUQT78iCmlRw4PP5VDlDoTM5Wn8TtwireZ85eY1DaLQk3rRW4bytGJc3EKFjANS5xdZfNaCzar1XJ-iyj5K374PSKezhuD1aGCIDSJaWW7umSxLfUXHXNE28MfyFTqEUKi1oMoQ7q8UWcPyDVKPbqviOZqfVJa428vV_DXOzi_Gcnx4EEeEAQ94oeLJaJjue3z5WJweiHLjveE_NTk-TmI6NFPockLabuo2j_PyL-21Ybrqt1hjCgPgC2sKZJ93gDZsBFD2C82WkYIM8zUM3yKOjI-ppoKggDcRw9N87GMCFNQOerU7rvX1DIrGZdYUEql77XtZbaYB3KtO605ZJUXAx-iod0J-u8swgZXqvJMkqYrEA_ftFPTvz066mWesqjSfZxQAVSkfByR7zRYjiPhEOqzU0cwKAJXS0j33cPsFgGuC7Q_pV9ii0pXtXfmaJ2VM7V-DEKZYZDz6tWPeXeUethOS7_NkkXhF6ySCMpR1Za6ZK5Me2f7q2qs58_Q_EkeWuWVgbNCdvy3MmmqcDtLSLn-8QJsQ0bSokAIswRYS2YEwLrZRF1HvJ8Nc_XuWW7zDR6RaYISAJx7FQRV5x3oL7AC9A=w761-h330-no"/>
<p>3. Isi folder MP3 dengan file MP3 yang diinginkan dengan nama file ****.mp3 ganti **** dengan nama file angka ribuan dari 0001 sampai 2999:</p>
<img align="middle" src="https://lh3.googleusercontent.com/Teftmb8p68hvDpDBGqTuHvzeHTx_QLV9YvZLzf1alnukhx_jAImBDXBVkSSEGXYE74CAufubdUsPmDk6vwmwEWcUBtKaGZ76mNGi7iGZU66mjTX0at9HR64zmPSss9sc_p1Y2rsSRiqjwrLdy0e-0jpvDM2zmjGr9KFh_ixyWgIA4n2u1B0Us-HAM0z44Yt5WFE8C22pl4AO3OsG2iAWjLqRvmGN1_xTH2Auw1TPtFASH1v6xYbZi8faalCplu2wq67XmAVs7uHxVEFNxUd7F4-YcosH_zoD6stxj-SGgbvJgH9ZDVELzxZXhyza_PqD5_xtM1FO7JCSB4hLR2eCCNcULSVGqFdyNEE2A6G9WOtI7XITHzRjVX51gXDU9O8nFjFgv37x64yHD5fVKmyv4G4vwwcJURIetAmpWTA2KfFlbKDTGXZuHtJPaxIHCsufbbhFXbuFr0chvEIwgSiavKMBxbZDCs7ABAbs-d7w1WwC3Pf2ylmR5AqlR8zSCqOnsrXb2PNEs2FKrWi5-NZX9PUtsqnhBuzPGubLUap3-M-XvuOapUr0Ah0ZDqiAGWnIgNV7VWKLKsz1K_RlmutXKL1Jbwe4glEqhD_7kpWzKcclmQTPepQ=w592-h514-no"/>

## Deskripsi Kerja Program
<p>Untuk penggunaan dengan modul ATmega328P Indoware dengan menggunakan compiler CodeVisionAVR pertama download library dfmp3.c pada yang terdapat pada repsitory ini dan File ini bisa dijadikan file library dengan cara menaruh file ini satu folder pada project CodeVisionAVR atau bisa menyalin isi fungsi ini dan memasukkannya pada file utama projek. Selanjutnya adalah mengisi program berikut pada CodeVisionAVR. Listing program yang digunakan ada pada file main.c pada repository ini.</p>
<br>
<p>Pada saat Modul dinyalakan maka maka Mikrokontroller akan mengirimkan perintah untuk memainkan file pada file SD card dengan track 1 sampai 3 hingga selesai</p>

##
<hr>
<p align="right" size"6"><b>by IRP</b></p>
<p align="right" size"6"><b>Copyright Indo-Ware</b></p>
