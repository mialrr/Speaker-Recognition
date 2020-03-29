#################################################
#Speaker_1_1 1:1 检测两个声音是不是同一个人的声音
#################################################
CURL *curl;
CURLcode res;
curl = curl_easy_init();
if(curl) {
  curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "POST");
  curl_easy_setopt(curl, CURLOPT_URL, "http://47.110.142.112:9999");
  curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
  curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, "https");
  struct curl_slist *headers = NULL;
  curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
  curl_mime *mime;
  curl_mimepart *part;
  mime = curl_mime_init(curl);
  part = curl_mime_addpart(mime);
  curl_mime_name(part, "AppID");
  curl_mime_data(part, "2rtg2z53r", CURL_ZERO_TERMINATED);
  part = curl_mime_addpart(mime);
  curl_mime_name(part, "APIKey");
  curl_mime_data(part, "378d4582ad3ed253057cafe9c70fae8b", CURL_ZERO_TERMINATED);
  part = curl_mime_addpart(mime);
  curl_mime_name(part, "SecretKey");
  curl_mime_data(part, "d6uk5fd", CURL_ZERO_TERMINATED);
  part = curl_mime_addpart(mime);
  curl_mime_name(part, "Sound0");
  curl_mime_filedata(part, "../sample-files/156_0.wav");
  part = curl_mime_addpart(mime);
  curl_mime_name(part, "Sound1");
  curl_mime_filedata(part, "../sample-files/156_1.wav");
  curl_easy_setopt(curl, CURLOPT_MIMEPOST, mime);
  res = curl_easy_perform(curl);
  curl_mime_free(mime);
}
curl_easy_cleanup(curl);



#################################################
# ASR_Speaker_1_1 认证分为两部分
# 1:检测是否说了指定的文字的语音
# 2:检测是不是同一个人的声纹
# SpkTxt是语音Sound0的文本
#################################################

CURL *curl;
CURLcode res;
curl = curl_easy_init();
if(curl) {
  curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "POST");
  curl_easy_setopt(curl, CURLOPT_URL, "http://47.110.142.112:9999");
  curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
  curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, "https");
  struct curl_slist *headers = NULL;
  curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
  curl_mime *mime;
  curl_mimepart *part;
  mime = curl_mime_init(curl);
  part = curl_mime_addpart(mime);
  curl_mime_name(part, "AppID");
  curl_mime_data(part, "2rtg2z53r", CURL_ZERO_TERMINATED);
  part = curl_mime_addpart(mime);
  curl_mime_name(part, "APIKey");
  curl_mime_data(part, "378d4582ad3ed253057cafe9c70fae8b", CURL_ZERO_TERMINATED);
  part = curl_mime_addpart(mime);
  curl_mime_name(part, "SecretKey");
  curl_mime_data(part, "d6uk5fd", CURL_ZERO_TERMINATED);
  part = curl_mime_addpart(mime);
  curl_mime_name(part, "Sound0");
  curl_mime_filedata(part, "../sample-files/76256_39.wav");
  part = curl_mime_addpart(mime);
  curl_mime_name(part, "Sound1");
  curl_mime_filedata(part, "../sample-files/156_1.wav");
  part = curl_mime_addpart(mime);
  curl_mime_name(part, "Language");
  curl_mime_data(part, "cn", CURL_ZERO_TERMINATED);
  part = curl_mime_addpart(mime);
  curl_mime_name(part, "SpkTxt");
  curl_mime_data(part, "他完全将自己当成了一个凡人在体会这人世间的生老病死悲欢离合", CURL_ZERO_TERMINATED);
  curl_easy_setopt(curl, CURLOPT_MIMEPOST, mime);
  res = curl_easy_perform(curl);
  curl_mime_free(mime);
}
curl_easy_cleanup(curl);

