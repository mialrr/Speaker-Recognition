# Speaker-Recognition
声纹识别(Voiceprint Recognition, VPR)，也称为说话人识别(Speaker Recognition)，
有两类，即说话人辨认(Speaker Identification)和说话人确认(Speaker Verification)

# speech-demo
- 项目地址：https://github.com/mialrr/Speaker-Recognition

### 文档地址：

- 声纹识别：
- 语音识别：
- 语音合成：

- 目前AppID，APIKey，SecretKey是共用的等待官网开发完成自己申请就可以

# 简介
- Rest API 接口为http 访问， 任意操作系统，任意语言，只要能对域名或者IP地址发起http请求的，均可以使用。
- 以JAVA PHP python C BASH 作为示例，展示rest api的调用过程，选择一个运行即可。
- 支持音频格式：wav、flac
- 音频编码要求：采样率 16000，16bit 位深，单声道（音频格式查看及转换）声纹识别长度不要超过10毫秒
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
-   ☑ spk声纹识别 （acc 99.6%, i7-9700K(5Ghz) M40下10毫秒）
-   ☑ asr语音识别 （acc 90.9%, i7-9700K(5Ghz) 1秒）（开发语音识别主要是为了声纹认证本地部署需要）极度缺少训练样本） 
-   ☒ tts语音合成
  
# 请求
-  对于贡献大批量可用（开源数据不算）训练样本的兄弟，我们可以给您线下免费部署一次完整服务

# 客户场景
- 已在一家支付公司使用（支付场景）

# 谢谢各位

#### weixin:13165984330


#说明
- 目前公网的API接口刚刚开发还有些问题，随着开发进行会一一处理掉，这几天测试的兄弟不要太激动，如有问题直接在github上提问就行
- 如需部署私有云（好处就是不会泄露用户隐私）可以直接微信咨询
