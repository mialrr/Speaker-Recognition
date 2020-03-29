
"../sample-files/156_1.wav"
#################################################
#Speaker_1_1 1:1 检测两个声音是不是同一个人的声音
#################################################
require "uri"
require "net/http"

url = URI("http://47.110.142.112:9999")

http = Net::HTTP.new(url.host, url.port);
request = Net::HTTP::Post.new(url)
form_data = [['AppID', '2rtg2z53r'],['APIKey', '378d4582ad3ed253057cafe9c70fae8b'],['SecretKey', 'd6uk5fd'],['Sound0', File.open("../sample-files/156_0.wav")],['Sound1', File.open("../sample-files/156_1.wav")]]
request.set_form form_data, 'multipart/form-data'
response = http.request(request)
puts response.read_body



#################################################
# ASR_Speaker_1_1 认证分为两部分
# 1:检测是否说了指定的文字的语音
# 2:检测是不是同一个人的声纹
# SpkTxt是语音Sound0的文本
#################################################
require "uri"
require "net/http"

url = URI("http://47.110.142.112:9999")

http = Net::HTTP.new(url.host, url.port);
request = Net::HTTP::Post.new(url)
form_data = [['AppID', '2rtg2z53r'],['APIKey', '378d4582ad3ed253057cafe9c70fae8b'],['SecretKey', 'd6uk5fd'],['Sound0', File.open("../sample-files/76256_39.wav")],['Sound1', File.open("../sample-files/156_1.wav")],['Language', 'cn'],['SpkTxt', '他完全将自己当成了一个凡人在体会这人世间的生老病死悲欢离合']]
request.set_form form_data, 'multipart/form-data'
response = http.request(request)
puts response.read_body

