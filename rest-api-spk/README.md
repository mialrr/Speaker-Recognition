# 声纹识别：
- 声纹识别长度不要超过10秒

# 简介
- Rest API 接口为http 访问， 任意操作系统，任意语言，只要能对域名或者IP地址发起http请求的，均可以使用。
- 以JAVA PHP python C BASH 作为示例，展示rest api的调用过程，选择一个运行即可。
- 支持音频格式：wav、flac
- 音频编码要求：采样率 16000，16bit 位深，单声道（音频格式查看及转换）
- 返回识别结果：识别结果会即刻返回，采用 JSON 格式封装

# 目录结构
- +--rest-api-spk  声纹识别rest api
-    /-- bash_shell shell脚本                  （稍后开发）
-    /-- java 代码                             （稍后开发）
-    /-- linux_c C代码 （windows Cygwin可以运行）（稍后开发）
-    /-- php 代码                              （稍后开发）
-    /-- python代码                            （已经开发）

- +-- sample-files 语音识别示例音频文件
 
 
# 项目进度：
-   ☑ 声纹识别1:1 (Speaker_1_1())
-   ☑ 声纹识别1:1 + 语音识别 (ASR_Speaker_1_1())
-   ☒ 声纹识别1:N （开发中......）


# Speaker_1_1() 参数设置
### 描述
- 简单纯粹比较两个声音是不是同一个人

### 入参：
参数名称|类型|例子|描述|
|---|---|---|---|
|AppID|字符|2rtg2z53r|以后通过网站申请，现在使用默认就可以|
|APIKey|字符|378d4582ad3ed253057cafe9c70fae8b|以后通过网站申请，现在使用默认就可以|
|SecretKey|字符|d6uk5fd|以后通过网站申请，现在使用默认就可以|
|Sound0|file|你要识别的音频文件，例如：156_0.wav|目前支持(wav,flac)|
|Sound1|file|你要识别的音频文件，例如：156_1.wav|目前支持(wav,flac)|

### json 返回：
参数名称|类型|例子|描述|
|---|---|---|---|
|txt|字符|同一人声音| |
|scores|字符|'0.997'| |
|errId|字符|'200'或者'404'| |
|cosine|字符| | |
|angle|字符|'52.01266039016127'|夹角|
|threshold|字符|'58.3404892609345'|门槛|

### 结果设置：
- 普通精度判断是否同一人：threshold>angle 
- 指定精度 0.996 判断是否同一人：threshold>angle 并且 scores>=0.996

# ASR_Speaker_1_1() 参数设置
### 描述
- 声纹比较两个声音是不是同一个人的同时语音识别（防止录音伪造攻击）

### 入参：
参数名称|类型|例子|描述|
|---|---|---|---|
|AppID|字符|2rf9j453r|以后通过网站申请，现在使用默认就可以|
|APIKey|字符|378d4582ad3ed253057cafe9c70fae8b|以后通过网站申请，现在使用默认就可以|
|SecretKey|字符|d6uk5fd|以后通过网站申请，现在使用默认就可以|
|Language|字符|cn|中文语音识别（cn），中文语音识别（en）|
|SpkTxt|字符|'他完全将自己当成了一个凡人在体会这人世间的生老病死悲欢离合'|Sound0说话的文本内容|
|Sound0|file|你要识别的音频文件，例如：76256_39.wav|目前支持(wav,flac)|
|Sound1|file|你要识别的音频文件，例如：156_1.wav|目前支持(wav,flac)|

### json 返回：
参数名称|类型|例子|描述|
|---|---|---|---|
|txt|字符|同一人声音| |
|scores|字符|'0.997'| |
|errId|字符|'200'或者'404'| |
|cosine|字符| | |
|angle|字符|'52.01266039016127'|夹角|
|threshold|字符|'58.3404892609345'|门槛|
|ASRSpeaker|字符|'accept'|'accept'或'refuse'|
|ASRSpeakerDes|字符|'通过语音认证'| |

### 结果设置：
- 普通精度判断是否同一人：threshold>angle 并且 ASRSpeaker == accept
- 指定精度 0.996 判断是否同一人：threshold>angle 并且 scores >= 0.996 并且 ASRSpeaker == accept

# Speaker_1_N() 参数设置
### 描述
- 还在开发。。。。