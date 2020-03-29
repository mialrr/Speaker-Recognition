#################################################
#Speaker_1_1 1:1 检测两个声音是不是同一个人的声音
#################################################
var form = new FormData();
form.append("AppID", "2rtg2z53r");
form.append("APIKey", "378d4582ad3ed253057cafe9c70fae8b");
form.append("SecretKey", "d6uk5fd");
form.append("Sound0", fileInput.files[0], "../sample-files/156_0.wav");
form.append("Sound1", fileInput.files[0], "../sample-files/156_1.wav");

var settings = {
  "url": "http://47.110.142.112:9999",
  "method": "POST",
  "timeout": 0,
  "processData": false,
  "mimeType": "multipart/form-data",
  "contentType": false,
  "data": form
};

$.ajax(settings).done(function (response) {
  console.log(response);
});



#################################################
# ASR_Speaker_1_1 认证分为两部分
# 1:检测是否说了指定的文字的语音
# 2:检测是不是同一个人的声纹
# SpkTxt是语音Sound0的文本
#################################################
var form = new FormData();
form.append("AppID", "2rtg2z53r");
form.append("APIKey", "378d4582ad3ed253057cafe9c70fae8b");
form.append("SecretKey", "d6uk5fd");
form.append("Sound0", fileInput.files[0], "../sample-files/76256_39.wav");
form.append("Sound1", fileInput.files[0], "../sample-files/156_1.wav");
form.append("Language", "cn");
form.append("SpkTxt", "他完全将自己当成了一个凡人在体会这人世间的生老病死悲欢离合");

var settings = {
  "url": "http://47.110.142.112:9999",
  "method": "POST",
  "timeout": 0,
  "processData": false,
  "mimeType": "multipart/form-data",
  "contentType": false,
  "data": form
};

$.ajax(settings).done(function (response) {
  console.log(response);
});
