本示例程序适用于喵喵派(MeowPi)。
___
# 开发板简介
* 操作系统: 运行 Linux 系统
* 显示屏: 3.1 英寸，MIPI 接口，分辨率 480×800
* 主控芯片: T113-S3，双核 ARM Cortex-A7，内存 128MB，支持硬件解码
* USB 接口:
  * 双 USB-A Host 接口：支持HUB、键盘、鼠标、采集卡、U盘等设备
  * 三路 TYPE-C 接口：用于 USB 网卡、串口调试、键鼠输出
* 散热: 配备被动散热片
<div align="center">
  <img src="/pic/front.jpg" width="300" height="400" alt="MeowPi 正面"/>
  <img src="/pic/opposite.jpg" width="300" height="400" alt="MeowPi 背面"/>
</div>

___

## 演示视频

<div align="center">
  <img src="./pic/DemoVideo.gif" alt="Demo Video" />
</div>

---

# 资料下载

包括使用说明、开发环境、各类工具。

* 百度云: https://pan.baidu.com/s/1lHSPZqeX-rEO_0sqOz3B5Q?pwd=r5ik
* 123网盘 https://www.123pan.com/s/f2PIjv-gFsHv?提取码:E1V3
* 开发手册和使用手册在工程pic目录
___

# 开发环境搭建
1.安装WSL2    参考 [WSL的安装与使用](https://blog.csdn.net/weixin_57367513/article/details/135001273 "title")

2.下载喵喵派资料

3.导入ubuntu备份到电脑

* 使用命令: wsl --export Ubuntu-meowpi <安装路径> <映像文件路径>

___

# 功能描述

* catbox (兼容kmbox)
* 更多功能正在开发

___

# 版本更新

1.1 增加网页OTA，更改UUID获取方式
___
免责声明，本代码仅用于学习，下载后请勿用于商业用途。

禁止使用本软件（系统）用于任何违法违规业务或项目,造成的任何法律后果允由使用者（或运营者）承担全部责任。
___