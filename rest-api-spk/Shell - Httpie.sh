#################################################
#Speaker_1_1 1:1 检测两个声音是不是同一个人的声音
#################################################
http --ignore-stdin --form --follow --timeout 3600 POST 47.110.142.112:9999/ \
 'AppID'='2rtg2z53r' \
 'APIKey'='378d4582ad3ed253057cafe9c70fae8b' \
 'SecretKey'='d6uk5fd' \
 'Sound0'@../sample-files/156_0.wav \
 'Sound1'@../sample-files/156_1.wav


#################################################
# ASR_Speaker_1_1 认证分为两部分
# 1:检测是否说了指定的文字的语音
# 2:检测是不是同一个人的声纹
# SpkTxt是语音Sound0的文本
#################################################
http --ignore-stdin --form --follow --timeout 3600 POST 47.110.142.112:9999/ \
 'AppID'='2rtg2z53r' \
 'APIKey'='378d4582ad3ed253057cafe9c70fae8b' \
 'SecretKey'='d6uk5fd' \
 'Sound0'@"../sample-files/76256_39.wav" \
 'Sound1'@../sample-files/156_1.wav \
 'Language'='cn' \
 'SpkTxt'='他完全将自己当成了一个凡人在体会这人世间的生老病死悲欢离合'
