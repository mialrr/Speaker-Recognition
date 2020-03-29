#################################################
#Speaker_1_1 1:1 检测两个声音是不是同一个人的声音
#################################################
OkHttpClient client = new OkHttpClient().newBuilder().build();
MediaType mediaType = MediaType.parse("text/plain");
RequestBody body = new MultipartBody.Builder().setType(MultipartBody.FORM)
  .addFormDataPart("AppID", "2rtg2z53r")
  .addFormDataPart("APIKey", "378d4582ad3ed253057cafe9c70fae8b")
  .addFormDataPart("SecretKey", "d6uk5fd")
  .addFormDataPart("Sound0","../sample-files/156_0.wav",
    RequestBody.create(MediaType.parse("application/octet-stream"),
    new File("/C:/Users/nuc/Desktop/tmp/my/2.wav")))
  .addFormDataPart("Sound1","../sample-files/156_0.wav",
    RequestBody.create(MediaType.parse("application/octet-stream"),
    new File("/C:/Users/nuc/Desktop/tmp/my/3.wav")))
  .build();
Request request = new Request.Builder()
  .url("http://47.110.142.112:9999")
  .method("POST", body)
  .build();
Response response = client.newCall(request).execute();



#################################################
# ASR_Speaker_1_1 认证分为两部分
# 1:检测是否说了指定的文字的语音
# 2:检测是不是同一个人的声纹
# SpkTxt是语音Sound0的文本
#################################################
OkHttpClient client = new OkHttpClient().newBuilder()
  .build();
MediaType mediaType = MediaType.parse("text/plain");
RequestBody body = new MultipartBody.Builder().setType(MultipartBody.FORM)
  .addFormDataPart("AppID", "2rtg2z53r")
  .addFormDataPart("APIKey", "378d4582ad3ed253057cafe9c70fae8b")
  .addFormDataPart("SecretKey", "d6uk5fd")
  .addFormDataPart("Sound0", "../sample-files/76256_39.wav",
    RequestBody.create(MediaType.parse("application/octet-stream"),
    new File("/C:/Users/nuc/Desktop/tmp/my/156_1.wav")))
  .addFormDataPart("Sound1","../sample-files/156_1.wav",
    RequestBody.create(MediaType.parse("application/octet-stream"),
    new File("/C:/Users/nuc/Desktop/tmp/my/156_0.wav")))
  .addFormDataPart("Language", "cn")
  .addFormDataPart("SpkTxt", "他完全将自己当成了一个凡人在体会这人世间的生老病死悲欢离合")
  .build();
Request request = new Request.Builder()
  .url("http://47.110.142.112:9999")
  .method("POST", body)
  .build();
Response response = client.newCall(request).execute();
